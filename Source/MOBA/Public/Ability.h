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

    virtual void Activate();
};
