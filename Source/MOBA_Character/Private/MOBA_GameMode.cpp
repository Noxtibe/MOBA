#include "MOBA_GameMode.h"
#include "MOBACharacter.h"
#include "MOBA_HUD.h"
#include "MOBA_PlayerController.h"
#include "MOBA_GameState.h"
#include "MOBA_PlayerState.h"
#include "UObject/ConstructorHelpers.h"

AMOBA_GameMode::AMOBA_GameMode() : Super()
{

	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	HUDClass = AMOBA_HUD::StaticClass();
	PlayerControllerClass = AMOBA_PlayerController::StaticClass();
	GameStateClass = AMOBA_GameState::StaticClass();
	PlayerStateClass = AMOBA_PlayerState::StaticClass();

}