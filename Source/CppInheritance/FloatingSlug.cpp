#include "FloatingSlug.h"
#include "EngineMinimal.h"

// Sets default values
// Invoke the parent constructor in the initialization list
AFloatingSlug::AFloatingSlug() : Super()
{
	TWeakObjectPtr<UMaterialInstanceDynamic> Material = SkeletalMesh->CreateAndSetMaterialInstanceDynamic(0);
	Material->SetVectorParameterValue(FName(TEXT("Color")), FLinearColor(255.0f, 255.0f, 255.0f));

}

void AFloatingSlug::RunBehaviour()
{
	FVector SpawnLocation;
	FRotator SpawnRotation;

	//makes slug float on the air
	float DeltaTime = GetWorld()->GetDeltaSeconds();
	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.X += DeltaHeight * 500.0f;       //Scale our height by a factor of 50
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);

	// If fire interval has elapsed, spawn a new enemy projectile
	if (AccumulatedDeltaTime >= FireTimeInterval) {
		SpawnLocation = GetActorLocation() + GetActorForwardVector() * 250.0f;
		SpawnRotation = GetActorRotation();

		GetWorld()->SpawnActor(ProjectileClass, &SpawnLocation, &SpawnRotation);

		AccumulatedDeltaTime = 0.0f;
	}
}