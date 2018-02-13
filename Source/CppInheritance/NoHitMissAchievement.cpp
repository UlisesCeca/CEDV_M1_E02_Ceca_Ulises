// Fill out your copyright notice in the Description page of Project Settings.

#include "NoHitMissAchievement.h"
#include "Engine.h"


// Sets default values
// Invoke the parent constructor in the initialization list
ANoHitMissAchievement::ANoHitMissAchievement() : Super()
{
}

void ANoHitMissAchievement::Update()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You've killed all enemies without wasting a bullet!!"));
}

void ANoHitMissAchievement::BeginPlay()
{
	Super::BeginPlay();

	Update();
}