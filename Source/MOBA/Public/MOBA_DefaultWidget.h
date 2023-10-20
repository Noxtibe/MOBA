#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MOBA_DefaultWidget.generated.h"


UCLASS()
class MOBA_API UMOBA_DefaultWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	void SetHealth(float CurrentHealth, float MaxHealth);
	void SetEnergy(float CurrentEnergy, float MaxEnergy);

	// Link to the widget to dispplay the progress bar

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* HealthBar;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* EnergyBar;

protected:

	virtual void NativeConstruct() override;
};
