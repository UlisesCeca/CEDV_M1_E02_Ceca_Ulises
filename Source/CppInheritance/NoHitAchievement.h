// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicAchievement.h"
#include "NoHitAchievement.generated.h"


UCLASS()
class CPPINHERITANCE_API ANoHitAchievement : public ABasicAchievement
{
	GENERATED_BODY()

public:

	ANoHitAchievement();

private:
	void Update() override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
