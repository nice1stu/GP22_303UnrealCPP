// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractorComponent.h"

UInteractorComponent::UInteractorComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UInteractorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	const AActor* Owner = GetOwner();

	TArray<FOverlapResult> CandidateActors;
	/*
	// Find nearby actors, by channel
	GetWorld()->OverlapMultiByChannel(CandidateActors,
		Owner->GetActorLocation(),
		FQuat::Identity,
		
		)*/

	// Loop through found actors

	// Call the interface on all collected actors
}