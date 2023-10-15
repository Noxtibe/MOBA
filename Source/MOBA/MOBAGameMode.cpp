// Copyright Epic Games, Inc. All Rights Reserved.

#include "MOBAGameMode.h"
#include "MOBACharacter.h"
#include "UObject/ConstructorHelpers.h"

AMOBAGameMode::AMOBAGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
