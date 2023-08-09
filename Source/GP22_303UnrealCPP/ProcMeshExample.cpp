// Fill out your copyright notice in the Description page of Project Settings.
#include "ProcMeshExample.h"
#include "DrawDebugHelpers.h"

// Sets default values
AProcMeshExample::AProcMeshExample()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ProceduralMeshComponent = CreateDefaultSubobject<UProceduralMeshComponent>("Procedural Mesh");
	ProceduralMeshComponent->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AProcMeshExample::BeginPlay()
{
	Super::BeginPlay();
}

void AProcMeshExample::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	MeshData.SetNum(3);

	// Floor
	MeshData[0] = new FMeshData();
	MeshData[0]->SectionNumber = 0;
	MeshData[0]->Material = FloorMaterial;

	// Ceiling
	MeshData[1] = new FMeshData();
	MeshData[1]->SectionNumber = 1;
	MeshData[1]->Material = CeilingMaterial;

	// Walls
	MeshData[2] = new FMeshData();
	MeshData[2]->SectionNumber = 2;
	MeshData[2]->Material = WallMaterial;

	RoamingGenerator();
	GenerateMesh();

	for (int i = 0; i < MeshData.Num(); i++)
	{
		CreateSection(MeshData[i]);
	}
}

// Called every frame
void AProcMeshExample::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	return;

	FVector Location = GetActorLocation();
	Location.X -= TileSize * .5f;
	Location.Y -= TileSize * .5f;

	for (int i = 0; i < Tiles.Num(); i++)
	{
		FVector BottomLeftCorner = Location + FVector(Tiles[i]->X * TileSize, Tiles[i]->Y * TileSize, 0);
		FVector TopRightCorner = Location + FVector((Tiles[i]->X * TileSize) + TileSize, Tiles[i]->Y * TileSize, 0);
		FVector TopLeftCorner = Location + FVector((Tiles[i]->X * TileSize) + TileSize, (Tiles[i]->Y * TileSize) + TileSize, 0);
		FVector BottomRightCorner = Location + FVector(Tiles[i]->X * TileSize, (Tiles[i]->Y * TileSize) + TileSize, 0);

		DrawDebugPoint(GetWorld(), BottomLeftCorner, 25.f, FColor::Blue, false, .0f, 0U);
		DrawDebugPoint(GetWorld(), TopLeftCorner, 25.f, FColor::Blue, false, .0f, 0U);
		DrawDebugPoint(GetWorld(), TopRightCorner, 25.f, FColor::Blue, false, .0f, 0U);
		DrawDebugPoint(GetWorld(), BottomRightCorner, 25.f, FColor::Blue, false, .0f, 0U);

		DrawDebugLine(GetWorld(), BottomLeftCorner, TopRightCorner, FColor::Blue, false, .0f, 0U, 5.f);
		DrawDebugLine(GetWorld(), TopRightCorner, TopLeftCorner, FColor::Blue, false, .0f, 0U, 5.f);
		DrawDebugLine(GetWorld(), TopLeftCorner, BottomRightCorner, FColor::Blue, false, .0f, 0U, 5.f);
		DrawDebugLine(GetWorld(), BottomRightCorner, BottomLeftCorner, FColor::Blue, false, .0f, 0U, 5.f);

		FString DebugString;
		DebugString.Append(FString::FromInt(Tiles[i]->X));
		DebugString.Append(":");
		DebugString.Append(FString::FromInt(Tiles[i]->Y));
		DebugString.Append("->");
		DebugString.Append(UEnum::GetValueAsString(Tiles[i]->Type));
		
		if (Tiles[i]->Connections.Num() > 0)
		{
			DebugString.Append("Connections: ");

			for (int c = 0; c < Tiles[i]->Connections.Num(); c++)
			{
				DebugString.Append(UEnum::GetValueAsString(Tiles[i]->Connections[c].Direction));

				if(c < Tiles[i]->Connections.Num() -1)
					DebugString.Append(",");
			}
		}

		DrawDebugString(GetWorld(), BottomLeftCorner, DebugString, 0, FColor::White, .0f);
	}
}

void AProcMeshExample::RoamingGenerator()
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
		while (IsCoordinateOccupied(x,y))
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

void AProcMeshExample::GenerateMesh()
{
	for (int i = 0; i < Tiles.Num(); i++)
	{
		AddTile(Tiles[i]);
	}

}

void AProcMeshExample::AddQuad(FMeshData* Data, FVector v1, FVector v2, FVector v3, FVector v4, FVector Normal, float UVXScale, float UVYScale)
{
	int32 VertexIndex = Data->Vertices.Num();

	Data->Vertices.Add(v1);
	Data->Vertices.Add(v2);
	Data->Vertices.Add(v3);
	Data->Vertices.Add(v4);

	Data->UV.Add(FVector2D(0,0));
	Data->UV.Add(FVector2D(UVXScale, 0));
	Data->UV.Add(FVector2D(0, UVYScale));
	Data->UV.Add(FVector2D(UVXScale, UVYScale));

	Data->Normals.Add(Normal);
	Data->Normals.Add(Normal);
	Data->Normals.Add(Normal);
	Data->Normals.Add(Normal);

	if (Normal == FVector::DownVector)
	{
		Data->Triangles.Add(VertexIndex + 2);
		Data->Triangles.Add(VertexIndex + 3);
		Data->Triangles.Add(VertexIndex + 1);
		Data->Triangles.Add(VertexIndex + 2);
		Data->Triangles.Add(VertexIndex + 1);
		Data->Triangles.Add(VertexIndex);
	}
	else
	{
		Data->Triangles.Add(VertexIndex);
		Data->Triangles.Add(VertexIndex + 1);
		Data->Triangles.Add(VertexIndex + 2);
		Data->Triangles.Add(VertexIndex + 1);
		Data->Triangles.Add(VertexIndex + 3);
		Data->Triangles.Add(VertexIndex + 2);
	}
}

void AProcMeshExample::AddTile(UTile* Tile)
{
	FVector Location = GetActorLocation();
	Location.X -= TileSize * .5f;
	Location.Y -= TileSize * .5f;

	auto RX = Tile->X * TileSize;
	auto RY = Tile->Y * TileSize;

	FVector BottomLeftCorner = Location + FVector(RX, RY, 0);
	FVector TopLeftCorner = Location + FVector(RX + TileSize, RY, 0);
	FVector TopRightCorner = Location + FVector(RX + TileSize, RY + TileSize, 0);
	FVector BottomRightCorner = Location + FVector(RX, RY + TileSize, 0);

	// Floor
	AddQuad(
		MeshData[0],
		BottomLeftCorner,
		BottomRightCorner,
		TopLeftCorner,
		TopRightCorner,
		FVector::UpVector
	);

	// Ceiling
	auto Ceiling = FVector::UpVector * CeilingHeight;

	AddQuad(
		MeshData[1],
		BottomLeftCorner + Ceiling,
		BottomRightCorner + Ceiling,
		TopLeftCorner + Ceiling,
		TopRightCorner + Ceiling,
		FVector::DownVector
	);
	
	auto HeightBySize = CeilingHeight / TileSize;

	// Walls
	for (int i = 0; i < Tile->Connections.Num(); i++)
	{
		auto Connection = Tile->Connections[i];

		if (Connection.Tile != nullptr)
			continue;

		if (Connection.Direction == ETileDirection::North)
		{
			AddQuad(
				MeshData[2],
				TopLeftCorner,
				TopRightCorner,
				TopLeftCorner + Ceiling,
				TopRightCorner + Ceiling,
				FVector::BackwardVector,
				1.f,
				HeightBySize
			);
		}

		if (Connection.Direction == ETileDirection::South)
		{
			AddQuad(
				MeshData[2],
				BottomRightCorner,
				BottomLeftCorner,
				BottomRightCorner + Ceiling,
				BottomLeftCorner + Ceiling,
				FVector::ForwardVector,
				1.f,
				HeightBySize
			);
		}

		if (Connection.Direction == ETileDirection::East)
		{
			AddQuad(
				MeshData[2],
				TopRightCorner,
				BottomRightCorner,
				TopRightCorner + Ceiling,
				BottomRightCorner + Ceiling,
				FVector::LeftVector,
				1.f,
				HeightBySize
			);
		}

		if (Connection.Direction == ETileDirection::West)
		{
			AddQuad(
				MeshData[2],
				BottomLeftCorner,
				TopLeftCorner,
				BottomLeftCorner + Ceiling,
				TopLeftCorner + Ceiling,
				FVector::RightVector,
				1.f,
				HeightBySize
			);
		}
	}
}

void AProcMeshExample::AssignConnections(UTile* Tile)
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

void AProcMeshExample::AssignType(UTile* Tile)
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

bool AProcMeshExample::IsCoordinateOccupied(int32 X, int32 Y)
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

UTile* AProcMeshExample::GetTileByCoordinate(int32 X, int32 Y)
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

void AProcMeshExample::CreateSection(FMeshData* Data)
{
	ProceduralMeshComponent->SetMaterial(Data->SectionNumber, Data->Material);
	ProceduralMeshComponent->CreateMeshSection(Data->SectionNumber, Data->Vertices, Data->Triangles, Data->Normals, Data->UV, Data->Colors, TArray<FProcMeshTangent>(), true);
}