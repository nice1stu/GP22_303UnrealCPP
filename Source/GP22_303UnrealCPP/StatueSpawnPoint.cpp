// Fill out your copyright notice in the Description page of Project Settings.

#include "StatueSpawnPoint.h"
#include "DrawDebugHelpers.h"
#include "StatueHelpers.h"
#include "StatueManager.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameGlobals.h"

AStatueSpawnPoint::AStatueSpawnPoint()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AStatueSpawnPoint::BeginPlay()
{
    Super::BeginPlay();

    // Set the global spawn point and radius
    GlobalSpawnPoint = GetActorLocation();
    GlobalSpawnRadius = SpawnRadius;

    StatueManager = Cast<AStatueManager>(
        UGameplayStatics::GetActorOfClass(
            GetWorld(),
            AStatueManager::StaticClass()
        )
    );

    for (int i = 0; i < SpawnCount; i++)
    {
        const auto RandomPoint = UStatueHelpers::RandomLocation(GlobalSpawnPoint, GlobalSpawnRadius);
        StatueManager->SpawnStatue(RandomPoint);
    }
}

void AStatueSpawnPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DrawDebugSphere(GetWorld(), GetActorLocation(), SpawnRadius, 12, FColor::Red);
}