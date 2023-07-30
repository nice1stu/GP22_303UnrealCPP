// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../GP22_303UnrealCPP/GP22_303UnrealCPPGameModeBase.h"
#include "StatueSpawnPoint.generated.h"

UCLASS()
class GP22_303UNREALCPP_API AStatueSpawnPoint : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY()
	AStatueManager* StatueManager;
	
protected:
	virtual void BeginPlay() override;

public:
	AStatueSpawnPoint();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawning")
	int32 SpawnCount = 3;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawning")
	float SpawnRadius = 3000;
};