// Fab by Johnny Cochrane


#include "FabAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"


UFabAttributeSet::UFabAttributeSet()
{
	InitHealth(80.f);
}

void UFabAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UFabAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFabAttributeSet, HealthMax, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFabAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFabAttributeSet, StaminaMax, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFabAttributeSet, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UFabAttributeSet, StrengthMax, COND_None, REPNOTIFY_Always);
}

void UFabAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, GetHealthMax());
	}
}

void UFabAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp<float>(GetHealth(), 0.0f, GetHealthMax()));
	}
}

void UFabAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFabAttributeSet, Health, OldHealth);
}


void UFabAttributeSet::OnRep_HealthMax(const FGameplayAttributeData& OldHealthMax) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFabAttributeSet, HealthMax, OldHealthMax);
}

void UFabAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFabAttributeSet, Stamina, OldStamina);
}

void UFabAttributeSet::OnRep_StaminaMax(const FGameplayAttributeData& OldStaminaMax) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFabAttributeSet, StaminaMax, OldStaminaMax);
}

void UFabAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFabAttributeSet, Strength, OldStrength);
}

void UFabAttributeSet::OnRep_StrengthMax(const FGameplayAttributeData& OldStrengthMax) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UFabAttributeSet, StrengthMax, OldStrengthMax);
}
