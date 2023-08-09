// Fill out your copyright notice in the Description page of Project Settings.


#include "TileActor.h"

// Sets default values
ATileActor::ATileActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATileActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATileActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ATileActor::Evaluate(TArray<TEnumAsByte<ETileDirection>> CandidateDirections)
{
	int32 Count = CandidateDirections.Num();

	if (Count != RequiredDirections.Num())
		return false;

	for (int i = 0; i < RequiredDirections.Num(); i++)
	{
		for (int r = 0; r < CandidateDirections.Num(); r++)
		{
			if (RequiredDirections[i] == CandidateDirections[r])
				Count--;
		}
	}

	if (Count == 0)
		return true;

	return false;
}

