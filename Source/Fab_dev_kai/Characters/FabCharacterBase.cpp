// Fab by Johnny Cochrane


#include "FabCharacterBase.h"

#include "AbilitySystem/FabAbilitySystemComponent.h"


// Sets default values
AFabCharacterBase::AFabCharacterBase()
{
	// Set this character to call Tick() every frame.  YouW can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFabCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFabCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AFabCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

UAbilitySystemComponent* AFabCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UFabAttributeSet* AFabCharacterBase::GetAttributeSet() const
{
	return AttributeSet;
}

// Called to give default abilities to the character
void AFabCharacterBase::GiveDefaultAbilities()
{
	check(AbilitySystemComponent)
	if (!HasAuthority()) { return; }

	for (TSubclassOf<UGameplayAbility> AbilityClass : DefaultAbilities)
	{
		const FGameplayAbilitySpec AbilitySpec(AbilityClass, 1);
		AbilitySystemComponent->GiveAbility(AbilitySpec);
	}
}

void AFabCharacterBase::InitDefaultAttributes() const
{
	if (!AbilitySystemComponent || !DefaultAttributeEffect) { return; }

	// Sets the source of the Effect, i.e. this Character (?)
	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	// Apply the effect to this Character (?)
	const FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(
		DefaultAttributeEffect, 1.f, EffectContext);
	if (SpecHandle.IsValid())
	{
		AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}
}
