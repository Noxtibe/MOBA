#include "Ability_BreezeOfTerror.h"

UAbility_BreezeOfTerror::UAbility_BreezeOfTerror()
{
	CastingTime = 0.5f;
	CooldownTime = 15.0f;
}

void UAbility_BreezeOfTerror::Activate()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Capacity 2"));
}
