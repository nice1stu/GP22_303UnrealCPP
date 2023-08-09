// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MeshData.h"
#include "Tile.h"
#include "ProceduralMeshComponent.h"
#include "ProcMeshExample.generated.h"

UCLASS()
class GP22_303UNREALCPP_API AProcMeshExample : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProcMeshExample();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* FloorMaterial;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* CeilingMaterial;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* WallMaterial;

	UPROPERTY(EditAnywhere)
	float TileSize = 2000.f;

	UPROPERTY(EditAnywhere)
	float CeilingHeight = 1000.f;

	UPROPERTY(EditAnywhere)
	int32 TileCount = 10;

public:	
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void Tick(float DeltaTime) override;

	FVector RandomTileLocation();

private:
	UProceduralMeshComponent* ProceduralMeshComponent;

	TArray<UTile*> Tiles;

	TArray<FMeshData*> MeshData;

	void RoamingGenerator();

	void GenerateMesh();

	void AddQuad(FMeshData* Data, FVector v1, FVector v2, FVector v3, FVector v4, FVector Normal, float UVXScale = 1.f, float UVYScale = 1.f);

	void AddTile(UTile* Tile);

	void AssignConnections(UTile* Tile);
	
	void AssignType(UTile* Tile);

	bool IsCoordinateOccupied(int32 X, int32 Y);

	UTile* GetTileByCoordinate(int32 X, int32 Y);

	void CreateSection(FMeshData* Data);
};
