// Fill out your copyright notice in the Description page of Project Settings.


#include "StatueManager.h"

void AStatueManager::SpawnStatue(FVector Location)
{
	auto SpawnParams = FActorSpawnParameters();
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	auto NewInstance = GetWorld()->SpawnActor<AStatue>(LoadedObject, SpawnParams);
	NewInstance->SetActorLocation(Location);
	Instances.Add(NewInstance);
}

void AStatueManager::Initialize()
{
	LoadedObject = StatueClass.LoadSynchronous();
}