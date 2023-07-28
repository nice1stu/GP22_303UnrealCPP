// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickUpInterface.h"
#include "ScoreSubsystem.h"
#include "RandomMoveComponent.h"
#include "GameFramework/Actor.h"
#include "Statue.generated.h"

UCLASS()
class GP22_303UNREALCPP_API AStatue : public AActor,
	public IPickUpInterface
{
	GENERATED_BODY()

private:
	UScoreSubsystem* ScoreSubsystem;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	URandomMoveComponent* RandomMoveComponent;

	virtual void BeginPlay() override;

public:
	AStatue();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PickUp(); virtual void PickUp_Implementation() override;
};
