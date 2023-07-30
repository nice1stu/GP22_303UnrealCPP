// Fill out your copyright notice in the Description page of Project Settings.

#include "Statue.h"

// Sets default values
AStatue::AStatue()
{
	PrimaryActorTick.bCanEverTick = true;
	RandomMoveComponent = CreateDefaultSubobject<URandomMoveComponent>(TEXT("Random Move Component"));
}

void AStatue::BeginPlay()
{
	Super::BeginPlay();
	ScoreSubsystem = GetWorld()->GetSubsystem<UScoreSubsystem>();
}

void AStatue::PickUp_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, FString("Woohoo, used the interface !"));
	ScoreSubsystem->AddScore();
	RandomMoveComponent->RandomMove();
}