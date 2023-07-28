// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StatueManager.h"
#include "Statue.h"
#include "GP22_303UnrealCPPGameModeBase.generated.h"

UCLASS()
class GP22_303UNREALCPP_API AGP22_303UnrealCPPGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:

	UPROPERTY()
	AStatueManager* StatueManager;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TSoftClassPtr<AStatue> StatueClass;

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	void SpawnStatue(const FVector Location);
};