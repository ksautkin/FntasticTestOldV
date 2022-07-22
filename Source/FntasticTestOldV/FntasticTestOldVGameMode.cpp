// Copyright Epic Games, Inc. All Rights Reserved.

#include "FntasticTestOldVGameMode.h"
#include "FntasticTestOldVCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFntasticTestOldVGameMode::AFntasticTestOldVGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
