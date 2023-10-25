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

	bool IsReadyToActivate();
	void StartCooldown();

	// Ajoutez une fonction pour récupérer le temps de recharge
	UFUNCTION(BlueprintCallable, Category = "Ability")
	float GetCooldownTime() const;

private:

	bool bIsCasting;
	bool bIsOnCooldown;

	// Fonction de rappel pour réinitialiser le temps de recharge
	void ResetCooldown();
	
	FTimerHandle TimerHandle_ResetCooldown; // Déclaration de TimerHandle_ResetCooldown
};
