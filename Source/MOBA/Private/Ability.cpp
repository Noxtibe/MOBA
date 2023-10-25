#include "Ability.h"

UAbility::UAbility() : CastingTime(1.0f), CooldownTime(5.0f), Damage(10.0f)
{
}

void UAbility::Activate()
{
    if (!bIsCasting && CooldownTimeRemaining <= 0.0f)
    {
        // Starting casting time
        bIsCasting = true;
        CastingTimeRemaining = CastingTime;
    }
}

void UAbility::Tick(float DeltaTime)
{
    // Update casting time & cooldown
    if (bIsCasting)
    {
        CastingTimeRemaining -= DeltaTime;

        if (CastingTimeRemaining <= 0.0f)
        {
            bIsCasting = false;
            CooldownTimeRemaining = CooldownTime;
        }
    }

    if (CooldownTimeRemaining > 0.0f)
    {
        CooldownTimeRemaining -= DeltaTime;
    }
}