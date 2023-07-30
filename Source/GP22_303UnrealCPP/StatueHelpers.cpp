// Fill out your copyright notice in the Description page of Project Settings.


#include "StatueHelpers.h"
#include "Kismet/KismetMathLibrary.h"

FVector UStatueHelpers::RandomLocation(const FVector Origin, const float Radius)
{
	FVector RandomUnitVector = UKismetMathLibrary::RandomUnitVector();
	RandomUnitVector.Z = 0.f;

	const FVector RandomLocation = RandomUnitVector * Radius;

	return Origin + RandomLocation;
}