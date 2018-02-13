// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicAchievement.h"
#include "NoHitMissAchievement.generated.h"


UCLASS()
class CPPINHERITANCE_API ANoHitMissAchievement : public ABasicAchievement
{
	GENERATED_BODY()

public:

	ANoHitMissAchievement();

private:
	void Update() override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
