// Copyright Epic Games, Inc. All Rights Reserved.

#include "MOBA_CharacterGameMode.h"
#include "MOBA_CharacterCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMOBA_CharacterGameMode::AMOBA_CharacterGameMode(): Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
