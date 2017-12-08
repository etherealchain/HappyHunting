// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "HappyHuntingGameMode.h"
#include "HappyHuntingHUD.h"
#include "HappyHuntingCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHappyHuntingGameMode::AHappyHuntingGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AHappyHuntingHUD::StaticClass();
}
