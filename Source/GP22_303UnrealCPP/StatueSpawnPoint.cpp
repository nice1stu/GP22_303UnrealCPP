// Fill out your copyright notice in the Description page of Project Settings.


#include "StatueSpawnPoint.h"
#include "DrawDebugHelpers.h"

AStatueSpawnPoint::AStatueSpawnPoint()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AStatueSpawnPoint::BeginPlay()
{
	Super::BeginPlay();

	// Loop through SpawnCount
		// Generate random position inside the radius
		// Spawn 1 entity using StatueManager
	
}

void AStatueSpawnPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebugSphere(GetWorld(), GetActorLocation(), SpawnRadius, 12, FColor::Red);
}

