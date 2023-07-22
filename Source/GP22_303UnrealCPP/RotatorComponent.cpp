// Fill out your copyright notice in the Description page of Prude "RotatorComponent.h"

#include "RotatorComponent.h"

URotatorComponent::URotatorComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void URotatorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	auto Owner = GetOwner();
	auto Rotator = FRotator(0.f, RotationSpeed * DeltaTime, 0.f);

	Owner->AddActorLocalRotation(Rotator);
}