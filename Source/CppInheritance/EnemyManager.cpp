#include "EnemyManager.h"
#include "EngineUtils.h"

#include "FloatingSlug.h"
#include "TeleportingSlug.h"
#include "SuicidalSlug.h"
#include "Engine.h"
#include "AchievementManager.h"


// Example of member initialization list
AEnemyManager::AEnemyManager()
	: AccumulatedDeltaTime(0.0f), EnemySpawnTimeSeconds(3.5f), MaxNumberOfEnemies(5), ReferencePlane(0)
{
	MaxEnemiesSpawn = 0;
	PrimaryActorTick.bCanEverTick = true;

	// Store references to enemy classes for later
	EnemyClasses.AddUnique(ASuicidalSlug::StaticClass());
	EnemyClasses.AddUnique(AFloatingSlug::StaticClass());
	EnemyClasses.AddUnique(ATeleportingSlug::StaticClass());
}

void AEnemyManager::BeginPlay()
{
	
	Super::BeginPlay();

	FString EnemySpawnPlaneString = FString(TEXT("EnemySpawnPlane"));

	FString AchievementManagerString = FString(TEXT("AchievementManager_1"));

	TotalEnemies = MaxEnemiesSpawn;

	// Get a reference to the invisible plane used to spawn enemies
	for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (EnemySpawnPlaneString.Equals(ActorItr->GetName()))
		{
			// Conversion to smart pointer
			ReferencePlane = *ActorItr;
			break;
		}
	}

	// Get a reference to the invisible plane used to spawn enemies
	for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (AchievementManagerString.Equals(ActorItr->GetName()))
		{
			// Conversion to smart pointer
			AchievementManagerReference = Cast<AAchievementManager>(*ActorItr);
			break;
		}
	}
}

void AEnemyManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AccumulatedDeltaTime += DeltaTime;
	if ((AccumulatedDeltaTime >= EnemySpawnTimeSeconds)
		&&
		(GetNumberOfEnemies() < MaxNumberOfEnemies))
	{
		// Spawn new enemy and reset the counter
		SpawnEnemy();
		AccumulatedDeltaTime = 0.0f;
	}
}

int AEnemyManager::GetNumberOfEnemies() const
{
	int LivingEnemies = 0;

	for (TActorIterator<ABaseEnemy> ActorItr(GetWorld(), ABaseEnemy::StaticClass()); ActorItr; ++ActorItr)
	{
		LivingEnemies++;
	}

	return LivingEnemies;
}

FVector AEnemyManager::GetRandomLocationFromReferencePlane() const
{
	FVector RandomLocation;
	FVector Orgin;
	FVector BoundsExtent;
	ReferencePlane->GetActorBounds(false, Orgin, BoundsExtent);

	// Build a bounding box and get a random location.
	RandomLocation = FMath::RandPointInBox(FBox::BuildAABB(Orgin, BoundsExtent));

	return RandomLocation;
}

TSubclassOf<ABaseEnemy> AEnemyManager::GetRandomEnemyClass() const
{
	return EnemyClasses[FMath::RandRange(0, EnemyClasses.Num() - 1)];
}

void AEnemyManager::SpawnEnemy()
{
	if (MaxEnemiesSpawn > 0) {
		TSubclassOf<ABaseEnemy> EnemyType = GetRandomEnemyClass();
		FVector EnemySpawnLocation = GetRandomLocationFromReferencePlane();
		GetWorld()->SpawnActor(EnemyType, &EnemySpawnLocation);
		MaxEnemiesSpawn -= 1;
	}
	else {
		if (AchievementManagerReference->GetBeenHit() == false && GetNumberOfEnemies() <= 0) { //shows event when you win without being hit
			AchievementManagerReference->CreateNoHitAchievementEvent();
		}

		if (AchievementManagerReference->GetMadeShoots() <= TotalEnemies) { //shows event when you don't miss a hit
			AchievementManagerReference->CreateNoHitMissAchievementEvent();
		}
		EnemySpawnTimeSeconds = 10.0f;
	}
}

void AEnemyManager::PostInitProperties()
{
	Super::PostInitProperties();
}