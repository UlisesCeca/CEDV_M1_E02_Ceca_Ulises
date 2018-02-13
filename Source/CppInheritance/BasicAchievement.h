// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasicAchievement.generated.h"

UCLASS(Abstract)
class CPPINHERITANCE_API ABasicAchievement : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasicAchievement();

protected:
	virtual void Update() PURE_VIRTUAL(ABasicAchievement::Update, );
	
};
