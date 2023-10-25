#pragma once
#include "CoreMinimal.h"
#include "Ability.h"
#include "Ability_VengefulRaven.generated.h"

UCLASS()
class MOBA_API UAbility_VengefulRaven : public UAbility
{
	GENERATED_BODY()
	
public:

	UAbility_VengefulRaven();

	virtual void Activate() override;
};
