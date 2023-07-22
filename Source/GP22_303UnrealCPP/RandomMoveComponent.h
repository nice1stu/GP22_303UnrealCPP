// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RandomMoveComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GP22_303UNREALCPP_API URandomMoveComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	float Timer;

	UFUNCTION()
	
	void RandomMove();


public:	
	URandomMoveComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)

	float Radius = 1000.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)

	float Interval = 30.f;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
