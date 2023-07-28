// Fill out your copyright notice in the Description page of Project Settings.

#include "RandomMoveComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "StatueHelpers.h"

URandomMoveComponent::URandomMoveComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void URandomMoveComponent::RandomMove()
{
	const auto Owner = GetOwner();
	const auto RandomLocation = UStatueHelpers::RandomLocation(Owner->GetActorLocation(), Radius);
	Owner->SetActorLocation(RandomLocation);
}

void URandomMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Timer += DeltaTime;

	if (Timer > Interval)
	{
		Timer -= Interval;
		RandomMove();
	}
}