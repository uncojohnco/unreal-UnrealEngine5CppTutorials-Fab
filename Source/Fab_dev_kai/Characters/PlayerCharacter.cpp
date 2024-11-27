// Fab by Johnny Cochrane


#include "PlayerCharacter.h"

#include "AbilitySystem/FabAbilitySystemComponent.h"
#include "Player/FabPlayerState.h"

#include "FabMacros.h"
#include "UI/FabHUD.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Set player's AbilitySystemComponent
void APlayerCharacter::InitAbilitySystemComponent()
{
	AFabPlayerState* FabPlayerState = GetPlayerState<AFabPlayerState>();
	check(FabPlayerState);
	AbilitySystemComponent = CastChecked<UFabAbilitySystemComponent>(
		FabPlayerState->GetAbilitySystemComponent());
	AbilitySystemComponent->InitAbilityActorInfo(FabPlayerState, this);
	AttributeSet = FabPlayerState->GetAttributeSet();
}

void APlayerCharacter::InitHUD() const
{
	if (const APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (AFabHUD* FabHUD = Cast<AFabHUD>(PlayerController->GetHUD()))
		{
			FabHUD->Init();
		}
	}
}

void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Setup player's AbilitySystemComponent
	InitAbilitySystemComponent();
	GiveDefaultAbilities();
	InitDefaultAttributes();
	InitHUD();
}

void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbilitySystemComponent();
	InitDefaultAttributes();
	InitHUD();
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	// log to console
	UE_LOG(LogTemp, Warning, TEXT("APlayerCharacter::BeginPlay"));
	UE_LOG(LogTemp, Warning, TEXT("PrimaryActorTick.bCanEverTick = %s"),
	       PrimaryActorTick.bCanEverTick ? TEXT("true") : TEXT("false"));

	// log to screen
	GEngine->AddOnScreenDebugMessage(-1, 4.f, FColor::Purple, TEXT("OnScreen"));

	// log to screen via macro
	DBG_PRINT_ONSCREEN("Print via macro from, %s", *FString(__FUNCTION__));

	// Draw debug doodads
	FVector TargetLocation = FVector(2200.f, 700.f, 150.f);
	DBG_SPHERE(TargetLocation);
	DBG_LINE(GetActorLocation(), TargetLocation);
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Draw debug doodads
	FVector ActorLocation = GetActorLocation();
	FVector TargetLocation = FVector(2200.f, 700.f, 150.f);
	DBG_SPHERE_TICK(ActorLocation);
	DBG_LINE_TICK(ActorLocation, TargetLocation);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
