// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickUpInterface.generated.h"

/**
 * 
 */
UCLASS(MinimalAPI, BlueprintType)

class GP22_303UNREALCPP_API PickUpInterface : UInterface
{
	GENERATED_BODY()
};

class GP22_303UNREALCPP_API IPickUpInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)

	void PickUp();
};