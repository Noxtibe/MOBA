#include "Ability_AutoAttack.h"

UAbility_AutoAttack::UAbility_AutoAttack()
{
    CastingTime = 1.0f;
    CooldownTime = 0.4f;
    Damage = 6.0f;
}

void UAbility_AutoAttack::Activate()
{
    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Auto Attack"));
}