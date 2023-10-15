#include "MOBA_GameMode.h"
#include "MOBA_PlayerState.h"
#include "MOBA_GameState.h"
#include "MOBA_HUD.h"
#include "MOBA_PlayerController.h"
#include "MOBA_Character.h"

AMOBA_GameMode::AMOBA_GameMode() : Super()
{
    // Custom PlayerState
    PlayerStateClass = AMOBA_PlayerState::StaticClass();

    // Custom GameState
    GameStateClass = AMOBA_GameState::StaticClass();

    // Custom HUD
    HUDClass = AMOBA_HUD::StaticClass();

    // Custom PlayerController
    PlayerControllerClass = AMOBA_PlayerController::StaticClass();

    // Custom Character
    //static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
    DefaultPawnClass = AMOBA_Character::StaticClass();
}

void AMOBA_GameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
    Super::InitGame(MapName, Options, ErrorMessage);
}