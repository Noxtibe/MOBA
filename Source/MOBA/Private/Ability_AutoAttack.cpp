#include "Ability_AutoAttack.h"

UAbility_AutoAttack::UAbility_AutoAttack()
{
    CastingTime = 1.0f;
    CooldownTime = 5.0f;
    Damage = 6.0f;

    bIsCasting = false;
    bIsOnCooldown = false;
}

void UAbility_AutoAttack::Activate()
{
    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Auto Attack"));
}

bool UAbility_AutoAttack::IsReadyToActivate()
{
    return !bIsCasting && !bIsOnCooldown;
}

void UAbility_AutoAttack::StartCooldown()
{
    bIsOnCooldown = true;

    FTimerManager& TimerManager = GetWorld()->GetTimerManager();
    // Planifiez une fonction de rappel pour réinitialiser le temps de recharge
    TimerManager.SetTimer(TimerHandle_ResetCooldown, this, &UAbility_AutoAttack::ResetCooldown, CooldownTime, false);
}

// Implémentez la fonction pour récupérer le temps de recharge
float UAbility_AutoAttack::GetCooldownTime() const
{
    return CooldownTime;
}

void UAbility_AutoAttack::ResetCooldown()
{
    bIsOnCooldown = false;
}