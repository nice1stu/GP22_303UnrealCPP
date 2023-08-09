// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.h"
#include "TileActor.h"

#include "QuiltingExample.generated.h"

UCLASS()
class GP22_303UNREALCPP_API AQuiltingExample : public AActor
{
	GENERATED_BODY()
	
public:	
	AQuiltingExample();

private:
	TArray<ATileActor*> CandidateInstances;
	TArray<UTile*> Tiles;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	int32 TileCount = 10;

	UFUNCTION()
	void GenerateQuilt();

	void RoamingGenerator();
	void AssignConnections(UTile* Tile);

	void AssignType(UTile* Tile);

	bool IsCoordinateOccupied(int32 X, int32 Y);

	UTile* GetTileByCoordinate(int32 X, int32 Y);

public:	
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ATileActor*> CandidateTiles;
};
