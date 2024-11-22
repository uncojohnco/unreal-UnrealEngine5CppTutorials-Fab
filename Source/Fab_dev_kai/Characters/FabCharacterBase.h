// Fab by Johnny Cochrane

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Abilities/GameplayAbility.h"

#include "AbilitySystemInterface.h"

#include "FabCharacterBase.generated.h"

class UFabAbilitySystemComponent;


UCLASS()
class FAB_DEV_KAI_API AFabCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFabCharacterBase();

	//~IAbilitySystemInterface interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	void GiveDefaultAbilities();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Attach `AbilitySystemComponent` as a uproperty
	UPROPERTY()
	TObjectPtr<UFabAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Ability")
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
