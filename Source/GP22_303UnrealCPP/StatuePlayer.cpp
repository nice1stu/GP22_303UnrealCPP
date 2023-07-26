// Fill out your copyright notice in the Description page of Project Settings.


#include "StatuePlayer.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AStatuePlayer::AStatuePlayer()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AStatuePlayer::Move(FVector2D AxisInput)
{
	auto MoveVector = FVector(AxisInput.Y, -AxisInput.X, 0.f);

	auto TransformedVector = UKismetMathLibrary::TransformDirection(
		GetActorTransform(), 
		MoveVector
	);

	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	
	MoveVector *= MoveSpeed;

	SetActorLocation(
		GetActorLocation() + 
		MoveVector * DeltaTime
	);
}