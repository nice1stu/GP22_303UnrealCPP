// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TileType.h"
#include "TileConnection.h"
#include "Tile.generated.h"

UCLASS(BlueprintType)
class GP22_303UNREALCPP_API UTile : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TEnumAsByte<ETileType> Type;

	UPROPERTY()
	int32 X = -1;

	UPROPERTY()
	int32 Y = -1;

	UPROPERTY()
	TArray<FTileConnection> Connections;
};
