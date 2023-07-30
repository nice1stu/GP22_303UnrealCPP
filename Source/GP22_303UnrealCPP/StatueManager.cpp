// Fill out your copyright notice in the Description page of Project Settings.


#include "StatueManager.h"

void AStatueManager::SpawnStatue(FVector Location)
{
	auto NewInstance = GetWorld()->SpawnActor<AStatue>(LoadedObject);
	NewInstance->SetActorLocation(Location);
	Instances.Add(NewInstance);
}

void AStatueManager::Initialize()
{
	LoadedObject = StatueClass.LoadSynchronous();
}