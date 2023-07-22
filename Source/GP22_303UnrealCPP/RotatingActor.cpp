// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingActor.h"

// Sets default values
ARotatingActor::ARotatingActor()
{
	PrimaryActorTick.bCanEverTick = true;
	RotatorComponent = CreateDefaultSubobject<URotatorComponent>(TEXT("Rotator"));
}