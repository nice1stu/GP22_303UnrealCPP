// Fill out your copyright notice in the Description page of Project Settings.

#include "Statue.h"

// Sets default values
AStatue::AStatue()
{
	PrimaryActorTick.bCanEverTick = true;
	//RandomMoveComponent = CreateDefaultSubobject<URandomMoveComponent>(TEXT("Random Move Component"));
}

void AStatue::BeginPlay()
{
    Super::BeginPlay();

    // Print the spawned statue's location
    FString DebugMessage = FString::Printf(TEXT("Spawned Statue Location: X=%.2f, Y=%.2f, Z=%.2f"), GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z);
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, DebugMessage);

    ScoreSubsystem = GetWorld()->GetSubsystem<UScoreSubsystem>();
}


void AStatue::PickUp_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, FString("Woohoo, used the interface !"));
	ScoreSubsystem->AddScore();
	Destroy();
	//RandomMoveComponent->RandomMove();
}