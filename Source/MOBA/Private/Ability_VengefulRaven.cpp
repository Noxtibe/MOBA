#include "Ability_VengefulRaven.h"

UAbility_VengefulRaven::UAbility_VengefulRaven()
{
	CastingTime = 1.0f;
	CooldownTime = 60.0f;
}

void UAbility_VengefulRaven::Activate()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Magenta, TEXT("Capacity 4"));
}
