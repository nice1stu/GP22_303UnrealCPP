// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM()
enum ETileType
{
    /// <summary>
    /// A void tile is empty space and is used to make sure tile footprints don't intersect. It's the
    /// only form of a tile that is not "valid," by definition.
    /// </summary>
    Void    UMETA(DisplayName = "Void"),

    /// <summary>
    /// A wall tile has three valid connections.
    /// </summary>
    Wall    UMETA(DisplayName = "Wall"),

    /// <summary>
    /// A corner tile has two adjacent cardinal direction connections.
    /// </summary>
    Corner  UMETA(DisplayName = "Corner"),

    /// <summary>
    /// A floor tile has all four connections into other valid tiles.
    /// </summary>
    Floor   UMETA(DisplayName = "Floor"),

    /// <summary>
    /// A hallway tile has two connections on opposite sides.
    /// </summary>
    Hallway UMETA(DisplayName = "Hallway"),

    /// <summary>
    /// A deadend has only a single valid connection.
    /// </summary>
    Deadend UMETA(DisplayName = "Deadend"),

    /// <summary>
    /// A start tile has been flagged as a potential entrance.
    /// </summary>
    Start UMETA(DisplayName = "Start"),

    /// <summary>
    /// An end tile has been flagged as a potential exit.
    /// </summary>
    End   UMETA(DisplayName = "End")
};
