// Fab by Johnny Cochrane

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"

#include "AbilitySystemInterface.h"
#include "FabPlayerState.generated.h"

class UFabAbilitySystemComponent;

UCLASS()
class FAB_DEV_KAI_API AFabPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFabPlayerState();

	//~IAbilitySystemInterface interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Attach `AbilitySystemComponent` as a uproperty
	UPROPERTY()
	TObjectPtr<UFabAbilitySystemComponent> AbilitySystemComponent;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};