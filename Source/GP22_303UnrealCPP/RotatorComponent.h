// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RotatorComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GP22_303UNREALCPP_API URotatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	URotatorComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)

		float RotationSpeed = 45.f;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};