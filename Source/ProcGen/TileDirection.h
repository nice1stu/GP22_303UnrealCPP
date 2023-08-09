// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM()
enum ETileDirection
{
    None    UMETA(DisplayName = "None"),
    North   UMETA(DisplayName = "North"),
    South   UMETA(DisplayName = "South"),
    East    UMETA(DisplayName = "East"),
    West    UMETA(DisplayName = "West")
};