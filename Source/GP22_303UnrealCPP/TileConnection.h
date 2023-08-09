// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TileDirection.h"
#include "TileConnection.generated.h"

class UTile;

USTRUCT(BlueprintType)
struct GP22_303UNREALCPP_API FTileConnection
{
	GENERATED_BODY()

	FTileConnection() {};

	FTileConnection(ETileDirection Direction, UTile* Tile)
	{
		this->Direction = Direction;
		this->Tile = Tile;
	};

	UPROPERTY(EditAnywhere)
	UTile* Tile;

	UPROPERTY(EditAnywhere)
	TEnumAsByte<ETileDirection> Direction;
};
