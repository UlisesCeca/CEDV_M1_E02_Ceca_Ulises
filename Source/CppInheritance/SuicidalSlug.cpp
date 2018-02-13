#include "SuicidalSlug.h"
#include "EngineMinimal.h"

// Sets default values
// Invoke the parent constructor in the initialization list
ASuicidalSlug::ASuicidalSlug() : Super()
{
	TWeakObjectPtr<UMaterialInstanceDynamic> Material = SkeletalMesh->CreateAndSetMaterialInstanceDynamic(0);
	Material->SetVectorParameterValue(FName(TEXT("Color")), FLinearColor(0.0f, 247.0f, 255.0f));

}

void ASuicidalSlug::RunBehaviour()
{
	FVector SpawnLocation;
	FRotator SpawnRotation;

	// If fire interval has elapsed, spawn a new enemy projectile
	if ((AccumulatedDeltaTime + 1.5f) >= FireTimeInterval) {
		SpawnLocation = GetActorLocation() + GetActorForwardVector() * 250.0f;
		SpawnRotation = GetActorRotation();
		float SpawnIncrease = 0.0f;
		float RotationIncrease = -15.0f;

		for (int i = 0; i < 10; ++i) {
			SpawnRotation = GetActorRotation().Add(0.0f, 0.0f, 0.0f);
			SpawnLocation = GetActorLocation() + GetActorForwardVector();
			GetWorld()->SpawnActor(ProjectileClass, &SpawnLocation, &SpawnRotation);
		}

		AccumulatedDeltaTime = 0.0f;
	}
}