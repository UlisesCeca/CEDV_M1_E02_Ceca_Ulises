// Fill out your copyright notice in the Description page of Project Settings.

#include "TeleportingSlug.h"
#include "EngineMinimal.h"
#include "EngineUtils.h"

ATeleportingSlug::ATeleportingSlug() : Super()
{
	TWeakObjectPtr<UMaterialInstanceDynamic> Material = SkeletalMesh->CreateAndSetMaterialInstanceDynamic(0);
	Material->SetVectorParameterValue(FName(TEXT("Color")), FLinearColor(0.0f, 0.0f, 0.0f));

}

void ATeleportingSlug::RunBehaviour()
{
	FVector NewLocation = GetRandomLocationFromReferencePlane();
	FVector SpawnLocation;
	FRotator SpawnRotation;

	// If fire interval has elapsed, spawn a new enemy projectile
	if (AccumulatedDeltaTime >= FireTimeInterval) {
		SetActorLocation(NewLocation, false);
		SpawnLocation = GetActorLocation() + GetActorForwardVector() * 250.0f;
		SpawnRotation = GetActorRotation();

		GetWorld()->SpawnActor(ProjectileClass, &SpawnLocation, &SpawnRotation);

		AccumulatedDeltaTime = 0.0f;
	}
}

FVector ATeleportingSlug::GetRandomLocationFromReferencePlane() const
{
	FVector RandomLocation;
	FVector Orgin;
	FVector BoundsExtent;
	ReferencePlane->GetActorBounds(false, Orgin, BoundsExtent);

	// Build a bounding box and get a random location.
	RandomLocation = FMath::RandPointInBox(FBox::BuildAABB(Orgin, BoundsExtent));

	return RandomLocation;
}

void ATeleportingSlug::BeginPlay()
{
	Super::BeginPlay();

	FString EnemySpawnPlaneString = FString(TEXT("EnemySpawnPlane"));

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
}