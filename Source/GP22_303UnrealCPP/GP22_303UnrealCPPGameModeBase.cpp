// Copyright Epic Games, Inc. All Rights Reserved.


#include "GP22_303UnrealCPPGameModeBase.h"

void AGP22_303UnrealCPPGameModeBase::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	StatueManager = GetWorld()->SpawnActor<AStatueManager>();
}
