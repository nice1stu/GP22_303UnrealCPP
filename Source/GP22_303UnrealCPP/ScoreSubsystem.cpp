// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreSubsystem.h"

void UScoreSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString("Score Subsystem is Alive"));
}

void UScoreSubsystem::AddScore()
{
	CurrentScore++;
}