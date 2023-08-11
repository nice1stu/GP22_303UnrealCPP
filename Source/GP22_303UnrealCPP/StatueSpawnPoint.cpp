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
    /*GlobalSpawnPoint = GetActorLocation();
    GlobalSpawnRadius = SpawnRadius;*/

    StatueManager = Cast<AStatueManager>(
        UGameplayStatics::GetActorOfClass(
            GetWorld(),
            AStatueManager::StaticClass()
        )
    );

    ProcMeshExample = Cast<AProcMeshExample>(
        UGameplayStatics::GetActorOfClass(
            GetWorld(),
            AProcMeshExample::StaticClass()
        )
    );

    for (int i = 0; i < SpawnCount; i++)
    {
        //const auto RandomPoint = UStatueHelpers::RandomLocation(GlobalSpawnPoint, GlobalSpawnRadius);
        const auto RandomPoint = ProcMeshExample->GetRandomTileLocation();
 
        // Add Debug message
        FString DebugMessage = FString::Printf(TEXT("Random Point Location %d: X=%.2f, Y=%.2f, Z=%.2f"), i, RandomPoint.X, RandomPoint.Y, RandomPoint.Z);
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, DebugMessage);

        StatueManager->SpawnStatue(RandomPoint);
    }

    /*for (int i = 0; i < SpawnCount; i++)
    {
        const FVector ManualLocation(1000.f, 1000.f, 0.f); // Set the manual location here

        // Convert FVector to FString for debug message
        FString DebugMessage = FString::Printf(TEXT("Manual Tile Location %d: X=%.2f, Y=%.2f, Z=%.2f"), i, ManualLocation.X, ManualLocation.Y, ManualLocation.Z);

        // Print debug message on screen
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, DebugMessage);

        // Spawn the statue at the manual location
        StatueManager->SpawnStatue(ManualLocation);
    }*/

}

void AStatueSpawnPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DrawDebugSphere(GetWorld(), GetActorLocation(), SpawnRadius, 12, FColor::Red);
}