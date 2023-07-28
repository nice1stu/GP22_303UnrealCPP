// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StatueHelpers.generated.h"

/**
 * 
 */
UCLASS()
class GP22_303UNREALCPP_API UStatueHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
		UFUNCTION(Blueprintcallable, Category = "Helpers")
		static FVector RandomLocation(const FVector Origin, const float Radius);
};
