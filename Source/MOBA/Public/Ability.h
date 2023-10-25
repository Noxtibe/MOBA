#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Ability.generated.h"

UCLASS(Blueprintable, Abstract)
class MOBA_API UAbility : public UObject
{
    GENERATED_BODY()

public:

    UAbility();

    UPROPERTY(EditAnywhere, Category = "Ability")
    float CastingTime;

    UPROPERTY(EditAnywhere, Category = "Ability")
    float CooldownTime;

    UPROPERTY(EditAnywhere, Category = "Ability")
    float Damage;

    // Casting time & cooldown management
    UPROPERTY(Transient)
    bool bIsCasting;

    UPROPERTY(Transient)
    float CastingTimeRemaining;

    UPROPERTY(Transient)
    float CooldownTimeRemaining;

    virtual void Activate();
    virtual void Tick(float DeltaTime);
};
