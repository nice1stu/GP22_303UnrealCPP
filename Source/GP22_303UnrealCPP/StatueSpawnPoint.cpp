// Fill out your copyright notice in the Description page of Project Settings.


#include "StatueSpawnPoint.h"
#include "DrawDebugHelpers.h"
#include "StatueHelpers.h"
#include "StatueManager.h"
#include "Kismet/GameplayStatics.h"

AStatueSpawnPoint::AStatueSpawnPoint()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AStatueSpawnPoint::BeginPlay()
{
	Super::BeginPlay();

	StatueManager = Cast<AStatueManager>(
		UGameplayStatics::GetActorOfClass(
			GetWorld(),
			AStatueManager::StaticClass()
		)
	);

	auto Location = GetActorLocation();

	for (int i = 0; i < SpawnCount; i++)
	{
		// Generate random position inside the radius
		const auto RandomPoint = UStatueHelpers::RandomLocation(Location, SpawnRadius);
		StatueManager->SpawnStatue(RandomPoint);
	}

}

void AStatueSpawnPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DrawDebugSphere(GetWorld(), GetActorLocation(), SpawnRadius, 12, FColor::Red);
}

