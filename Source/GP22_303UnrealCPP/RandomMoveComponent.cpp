// Fill out your copyright notice in the Description page of Project Settings.

#include "RandomMoveComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "StatueHelpers.h"
#include "MyGameGlobals.h"

URandomMoveComponent::URandomMoveComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void URandomMoveComponent::RandomMove()
{
    const auto Owner = GetOwner();
    const auto SpawnPoint = GlobalSpawnPoint;

    FVector RandomDirection = FMath::VRand();
    RandomDirection.Z = 0.0f;

    float RandomDistance = FMath::FRandRange(0.0f, GlobalSpawnRadius);

    FVector DesiredLocation = SpawnPoint + RandomDirection.GetSafeNormal() * RandomDistance;

    float DistanceToSpawn = FVector::Dist2D(DesiredLocation, SpawnPoint);
    if (DistanceToSpawn > GlobalSpawnRadius)
    {
        DesiredLocation = SpawnPoint + (DesiredLocation - SpawnPoint).GetSafeNormal() * GlobalSpawnRadius;
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