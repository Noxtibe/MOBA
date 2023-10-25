#pragma once
#include "CoreMinimal.h"
#include "Ability.h"
#include "Ability_BreezeOfTerror.generated.h"

UCLASS()
class MOBA_API UAbility_BreezeOfTerror : public UAbility
{
	GENERATED_BODY()
	
public:

	UAbility_BreezeOfTerror();

	virtual void Activate() override;
};
