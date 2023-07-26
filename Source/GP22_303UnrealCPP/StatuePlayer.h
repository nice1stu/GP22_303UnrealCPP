// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "StatuePlayer.generated.h"

UCLASS()
class GP22_303UNREALCPP_API AStatuePlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AStatuePlayer();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MoveSpeed = 1000.f;

	UFUNCTION(BlueprintCallable)
	void Move(FVector2D AxisInput);
};
