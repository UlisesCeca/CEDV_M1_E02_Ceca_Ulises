// Fill out your copyright notice in the Description page of Project Settings.

#include "DeathsStreakAchievement.h"
#include "Engine.h"



// Sets default values
// Invoke the parent constructor in the initialization list
ADeathsStreakAchievement::ADeathsStreakAchievement() : Super()
{
}

void ADeathsStreakAchievement::Update()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You've killed all the enemies of this type!"));
}

void ADeathsStreakAchievement::BeginPlay()
{
	Super::BeginPlay();

	Update();
}