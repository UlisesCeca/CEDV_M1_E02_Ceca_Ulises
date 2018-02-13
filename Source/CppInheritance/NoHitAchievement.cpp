// Fill out your copyright notice in the Description page of Project Settings.

#include "NoHitAchievement.h"
#include "Engine.h"


// Sets default values
// Invoke the parent constructor in the initialization list
ANoHitAchievement::ANoHitAchievement() : Super()
{
}

void ANoHitAchievement::Update()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You've killed all enemies without being hit!!"));
}

void ANoHitAchievement::BeginPlay()
{
	Super::BeginPlay();

	Update();
}