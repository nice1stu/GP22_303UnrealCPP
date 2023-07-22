// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomMoveComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Private
void URandomMoveComponent::RandomMove()
{
	auto Owner = GetOwner();

	FVector RandomUnitVector = UKismetMathLibrary::RandomUnitVector();
	RandomUnitVector.Z = 0.f;

	const FVector RandomLocation = RandomUnitVector * Radius;

	Owner->SetActorLocation(Owner->GetActorLocation() + RandomLocation);
}

// Protected

// Public
URandomMoveComponent::URandomMoveComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void URandomMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Timer += DeltaTime;

	if (Timer > Interval)
	{
		Timer -= Interval;
		RandomMove();
	}
}