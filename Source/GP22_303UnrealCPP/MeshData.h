// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MeshData.generated.h"

USTRUCT(BlueprintType, Blueprintable)
struct GP22_303UNREALCPP_API FMeshData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UMaterialInterface* Material;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 SectionNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> Vertices;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> Normals;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector2D> UV;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FColor> Colors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int32> Triangles;
};
