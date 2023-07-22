// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatorComponent.h"
#include "RotatingActor.generated.h"

UCLASS(BlueprintType, Blueprintable)

class GP22_303UNREALCPP_API ARotatingActor : public AActor
{
	GENERATED_BODY()

public:
	ARotatingActor();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)

		URotatorComponent* RotatorComponent;
};