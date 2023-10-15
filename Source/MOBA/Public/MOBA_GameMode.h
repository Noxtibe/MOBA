#pragma once

#include "GameFramework/GameModeBase.h"
#include "MOBA_GameMode.generated.h"

UCLASS()
class MOBA_API AMOBA_GameMode : public AGameModeBase
{
    GENERATED_BODY()

public:

    AMOBA_GameMode();

    virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
};
