#pragma once
#include "CoreMinimal.h"
#include "Ability.h"
#include "Ability_ThreeEyedCrow.generated.h"

UCLASS()
class MOBA_API UAbility_ThreeEyedCrow : public UAbility
{
	GENERATED_BODY()
	
public:

	UAbility_ThreeEyedCrow();

	virtual void Activate() override;
};
