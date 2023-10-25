#include "Ability_ThreeEyedCrow.h"

UAbility_ThreeEyedCrow::UAbility_ThreeEyedCrow()
{
	CastingTime = 1.0f;
	CooldownTime = 3.0f;
}

void UAbility_ThreeEyedCrow::Activate()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Capacity 3"));
}
