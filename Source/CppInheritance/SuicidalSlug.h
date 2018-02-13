// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseEnemy.h"
#include "SuicidalSlug.generated.h"

/**
*
*/
UCLASS()
class CPPINHERITANCE_API ASuicidalSlug : public ABaseEnemy
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASuicidalSlug();

private:
	void RunBehaviour() override;
};
