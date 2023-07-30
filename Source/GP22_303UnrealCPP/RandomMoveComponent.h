// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RandomMoveComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GP22_303UNREALCPP_API URandomMoveComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	float Timer;

public:
	URandomMoveComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Interval = 2.0f;

	UFUNCTION(BlueprintCallable)
		void RandomMove();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
