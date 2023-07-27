// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "ScoreSubsystem.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)

class GP22_303UNREALCPP_API UScoreSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
private:
	int32 CurrentScore;

public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION()
	void AddScore();

	UFUNCTION(BlueprintCallable)
	int32 GetScore()
	{
		return CurrentScore;
	};
};
