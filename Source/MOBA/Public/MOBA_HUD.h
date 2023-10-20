#pragma once
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MOBA_HUD.generated.h"


UCLASS()
class MOBA_API AMOBA_HUD : public AHUD
{
	GENERATED_BODY()

public :

	AMOBA_HUD();

	virtual void BeginPlay() override;

};
