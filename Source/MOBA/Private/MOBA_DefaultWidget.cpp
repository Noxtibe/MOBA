#include "MOBA_DefaultWidget.h"
#include "Components/ProgressBar.h"

void UMOBA_DefaultWidget::SetHealth(float CurrentHealth, float MaxHealth)
{
	if (HealthBar)
	{
		HealthBar->SetPercent(CurrentHealth / MaxHealth);
	}
}

void UMOBA_DefaultWidget::SetEnergy(float CurrentEnergy, float MaxEnergy)
{
	if (EnergyBar)
	{
		EnergyBar->SetPercent(CurrentEnergy / MaxEnergy);
	}
}

void UMOBA_DefaultWidget::NativeConstruct()
{
	Super::NativeConstruct();
}
