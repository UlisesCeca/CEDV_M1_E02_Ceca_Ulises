// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseEnemy.h"
#include "FloatingSlug.generated.h"

/**
 * 
 */
UCLASS()
class CPPINHERITANCE_API AFloatingSlug : public ABaseEnemy
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AFloatingSlug();
	float RunningTime;

private:
	void RunBehaviour() override;
};
