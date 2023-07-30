// Fill out your copyright notice in the Description page of Project Settings.

#include "RandomMoveComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "StatueHelpers.h"
#include "MyGameGlobals.h" // Make sure this header is included if it contains GlobalSpawnPoint and GlobalSpawnRadius declarations

URandomMoveComponent::URandomMoveComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void URandomMoveComponent::RandomMove()
{
	const auto Owner = GetOwner();

	FVector RandomDirection = FMath::VRand();
	RandomDirection.Z = 0.0f;

	float RandomDistance = FMath::FRandRange(0.0f, GlobalSpawnRadius);

	FVector DesiredLocation = GlobalSpawnPoint + RandomDirection.GetSafeNormal() * RandomDistance;

	float DistanceToSpawn = FVector::Dist2D(DesiredLocation, GlobalSpawnPoint);
	if (DistanceToSpawn > GlobalSpawnRadius)
	{
		DesiredLocation = GlobalSpawnPoint + (DesiredLocation - GlobalSpawnPoint).GetSafeNormal() * GlobalSpawnRadius;
	}

	DesiredLocation.Z = 0.0f;

	Owner->SetActorLocation(DesiredLocation);
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