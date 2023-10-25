#pragma once
#include "CoreMinimal.h"
#include "Ability.h"
#include "Ability_FeatherOfRedemption.generated.h"

UCLASS()
class MOBA_API UAbility_FeatherOfRedemption : public UAbility
{
	GENERATED_BODY()
	
public:

	UAbility_FeatherOfRedemption();

	virtual void Activate() override;
};
