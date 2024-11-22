// Fab by Johnny Cochrane


#include "EnemyCharacter.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/FabAbilitySystemComponent.h"


// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UFabAbilitySystemComponent>("AbilitySystemComponent");
	// Gameplay effects are not replicated to other AI controlled pawns
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Setup enemy's AbilitySystemComponent
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
