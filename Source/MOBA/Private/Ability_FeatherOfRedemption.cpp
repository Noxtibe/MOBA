#include "Ability_FeatherOfRedemption.h"

UAbility_FeatherOfRedemption::UAbility_FeatherOfRedemption()
{
    CastingTime = 0.4f;
    CooldownTime = 1.5f;
    Damage = 40.0f;
}

void UAbility_FeatherOfRedemption::Activate()
{
    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Capacity 1"));
}
