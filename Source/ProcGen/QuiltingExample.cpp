// Fill out your copyright notice in the Description page of Project Settings.


#include "QuiltingExample.h"

// Sets default values
AQuiltingExample::AQuiltingExample()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AQuiltingExample::BeginPlay()
{
	Super::BeginPlay();
	GenerateQuilt();
}

void AQuiltingExample::GenerateQuilt()
{
	RoamingGenerator();

	// For each tile
	// Spawn a random TileCandidate
	for (int i = 0; i < Tiles.Num(); i++)
	{

	}

	int32 Index = FMath::RandRange(0, CandidateTiles.Num() -1);
	auto TileCandidate = CandidateTiles[Index];
	auto Instance = GetWorld()->SpawnActor<ATileActor>(ATileActor::StaticClass());

	//Instance->SetActorLocation();

	CandidateInstances.Add(Instance);
}

void AQuiltingExample::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
}

// Called every frame
void AQuiltingExample::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AQuiltingExample::RoamingGenerator()
{
	Tiles.SetNum(TileCount);

	for (int i = 0; i < TileCount; i++)
		Tiles[i] = NewObject<UTile>();

	auto x = 0;
	auto y = 0;

	Tiles[0]->X = 0;
	Tiles[0]->Y = 0;

	for (int i = 1; i < TileCount; i++)
	{
		while (IsCoordinateOccupied(x, y))
		{
			auto Direction = (ETileDirection)FMath::RandRange(0, 6) + 1;

			if (Direction == ETileDirection::North) x++;
			if (Direction == ETileDirection::South) x--;
			if (Direction == ETileDirection::East) y++;
			if (Direction == ETileDirection::West) y--;
		}

		Tiles[i]->X = x;
		Tiles[i]->Y = y;
	}

	for (int i = 0; i < TileCount; i++)
	{
		AssignConnections(Tiles[i]);
	}

	for (int i = 0; i < TileCount; i++)
	{
		AssignType(Tiles[i]);
	}
}

void AQuiltingExample::AssignConnections(UTile* Tile)
{
	if (Tile == nullptr)
		return;

	auto x = Tile->X;
	auto y = Tile->Y;

	Tile->Connections.SetNum(4);

	// North
	if (IsCoordinateOccupied(x + 1, y))
	{
		UTile* NorthRoom = GetTileByCoordinate(x + 1, y);
		Tile->Connections[0] = FTileConnection(ETileDirection::North, NorthRoom);
	}
	else
	{
		Tile->Connections[0] = FTileConnection(ETileDirection::North, nullptr);
	}

	// South
	if (IsCoordinateOccupied(x - 1, y))
	{
		UTile* SouthRoom = GetTileByCoordinate(x - 1, y);
		Tile->Connections[1] = FTileConnection(ETileDirection::South, SouthRoom);
	}
	else
	{
		Tile->Connections[1] = FTileConnection(ETileDirection::South, nullptr);
	}

	// East
	if (IsCoordinateOccupied(x, y + 1))
	{
		UTile* EastRoom = GetTileByCoordinate(x, y + 1);
		Tile->Connections[2] = FTileConnection(ETileDirection::East, EastRoom);
	}
	else
	{
		Tile->Connections[2] = FTileConnection(ETileDirection::East, nullptr);
	}

	// West
	if (IsCoordinateOccupied(x, y - 1))
	{
		UTile* WestRoom = GetTileByCoordinate(x, y - 1);
		Tile->Connections[3] = FTileConnection(ETileDirection::West, WestRoom);
	}
	else
	{
		Tile->Connections[3] = FTileConnection(ETileDirection::West, nullptr);
	}
}

void AQuiltingExample::AssignType(UTile* Tile)
{
	if (Tile == nullptr)
		return;

	int32 Connections = Tile->Connections.Num();

	// No connections means this is a void -- should not be possible
	if (Connections == 0)
		Tile->Type = ETileType::Void;

	// Exactly 1 connection means this is a deadend
	if (Connections == 1)
		Tile->Type = ETileType::Deadend;

	// Exactly 2 connections means this is either a hallway or a corner
	if (Connections == 2)
	{
		int32 XMatches = 0;
		int32 YMatches = 0;

		auto x = Tile->X;
		auto y = Tile->Y;

		for (int i = 0; i < Connections; i++)
		{
			if (Tile->Connections[i].Tile->X == x)
				XMatches++;

			if (Tile->Connections[i].Tile->Y == y)
				YMatches++;
		}

		if (XMatches == 2 || YMatches == 2)
		{
			Tile->Type = ETileType::Hallway;
		}
		else
		{
			Tile->Type = ETileType::Corner;
		}
	}

	// Three connections means this is a wall tile
	if (Connections == 3)
		Tile->Type = ETileType::Wall;

	// Four connections means this is an empty tile
	if (Connections == 4)
		Tile->Type = ETileType::Floor;
}

bool AQuiltingExample::IsCoordinateOccupied(int32 X, int32 Y)
{
	for (int i = 0; i < Tiles.Num(); i++)
	{
		if (Tiles[i] == nullptr)
			continue;

		if (Tiles[i]->X == X && Tiles[i]->Y == Y)
			return true;
	}

	return false;
}

UTile* AQuiltingExample::GetTileByCoordinate(int32 X, int32 Y)
{
	for (int i = 0; i < Tiles.Num(); i++)
	{
		if (Tiles[i] == nullptr)
			continue;

		if (Tiles[i]->X == X && Tiles[i]->Y == Y)
			return Tiles[i];
	}

	return nullptr;
}