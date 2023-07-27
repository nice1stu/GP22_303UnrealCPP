// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StatueSpawnPoint.generated.h"

UCLASS()
class GP22_303UNREALCPP_API AStatueSpawnPoint : public AActor
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	AStatueSpawnPoint();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 SpawnCount;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float SpawnRadius;
};
