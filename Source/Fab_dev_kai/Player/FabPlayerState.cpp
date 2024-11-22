// Fab by Johnny Cochrane


#include "FabPlayerState.h"

#include "AbilitySystem/FabAbilitySystemComponent.h"


// Sets default values
AFabPlayerState::AFabPlayerState()
{
	// Default value is too low as can cause perceived lag when updating attributes, update 100 times per sec.
	NetUpdateFrequency = 100.f;

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UFabAbilitySystemComponent>("AbilitySystemComponent");
	// Gameplay effects are applied only to the owner of the character.
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

UAbilitySystemComponent* AFabPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

// Called when the game starts or when spawned
void AFabPlayerState::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFabPlayerState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
