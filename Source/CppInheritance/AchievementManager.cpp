// Fill out your copyright notice in the Description page of Project Settings.

#include "AchievementManager.h"
#include "EngineUtils.h"
#include "NoHitMissAchievement.h"
#include "DeathsStreakAchievement.h"
#include "NoHitAchievement.h"
#include "Engine.h"


// Sets default values
AAchievementManager::AAchievementManager() : FloatingSlugStreakN(2), SuicidalSlugStreakN(2), TeleportingSlugStreakN(2), MadeShoots(0), BeenHit(false)
{

}
void AAchievementManager::BeginPlay()
{
	Super::BeginPlay();
}
void AAchievementManager::CreateNoHitAchievementEvent()
{
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;

	ANoHitAchievement* MyActor = GWorld->SpawnActor<ANoHitAchievement>(ANoHitAchievement::StaticClass(), Location, Rotation, SpawnInfo);
}

void AAchievementManager::CreateNoHitMissAchievementEvent()
{
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;

	ANoHitMissAchievement* MyActor = GWorld->SpawnActor<ANoHitMissAchievement>(ANoHitMissAchievement::StaticClass(), Location, Rotation, SpawnInfo);
}


void AAchievementManager::SetMadeShoots(int i)
{
	MadeShoots = i;
}

void AAchievementManager::SetBeenHit(bool b)
{
	BeenHit = b;
}

bool AAchievementManager::GetBeenHit() const
{
	return BeenHit;
}

int AAchievementManager::GetMadeShoots() const
{
	return MadeShoots;
}

