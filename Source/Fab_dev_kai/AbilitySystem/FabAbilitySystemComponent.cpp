// Fab by Johnny Cochrane


#include "FabAbilitySystemComponent.h"


// Sets default values for this component's properties
UFabAbilitySystemComponent::UFabAbilitySystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	SetIsReplicated(true);
}


// Called when the game starts
void UFabAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UFabAbilitySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                               FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
