// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseEnemy.h"
#include "TeleportingSlug.generated.h"

/**
 * 
 */
UCLASS()
class CPPINHERITANCE_API ATeleportingSlug : public ABaseEnemy
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ATeleportingSlug();

private:
	// Invisible plane to teleport
	TWeakObjectPtr<AActor> ReferencePlane;

	virtual void BeginPlay() override;
	void RunBehaviour() override;
	FVector GetRandomLocationFromReferencePlane() const;
	
};
