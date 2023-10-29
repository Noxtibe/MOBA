#pragma once
#include "CoreMinimal.h"
#include "Ability.h"
#include "Ability_AutoAttack.generated.h"

UCLASS()
class MOBA_API UAbility_AutoAttack : public UAbility
{
	GENERATED_BODY()

public:

	UAbility_AutoAttack();

	virtual void Activate() override;

};
