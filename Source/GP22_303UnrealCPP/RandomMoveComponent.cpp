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

    // Generate a random direction vector on the XY plane
    FVector RandomDirection = FMath::VRand();
    RandomDirection.Z = 0.0f; // Set the Z component to 0 to keep the movement on the ground level

    // Calculate the desired location as the global spawn point plus the random direction
    FVector DesiredLocation = GlobalSpawnPoint + RandomDirection.GetSafeNormal() * GlobalSpawnRadius;

    // Clamp the desired location to be within the spawn radius
    float DistanceToSpawn = FVector::Dist2D(DesiredLocation, GlobalSpawnPoint);
    if (DistanceToSpawn > GlobalSpawnRadius)
    {
        // Calculate the new desired location limited to the spawn radius
        DesiredLocation = GlobalSpawnPoint + (DesiredLocation - GlobalSpawnPoint).GetSafeNormal() * GlobalSpawnRadius;
    }

    // Set the Z component to 0 to keep the statue on the ground level
    DesiredLocation.Z = 0.0f;

    // Update the owner's location to the desired location
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