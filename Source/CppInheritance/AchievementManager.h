// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AchievementManager.generated.h"

class ABasicAchievement;

UCLASS()
class CPPINHERITANCE_API AAchievementManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAchievementManager();

	UFUNCTION(BlueprintCallable, Category = "Enemy Manager")
		void SetMadeShoots(int i);
	UFUNCTION(BlueprintCallable, Category = "Enemy Manager")
		void SetBeenHit(bool b);

	bool GetBeenHit() const;

	UFUNCTION(BlueprintCallable, Category = "Enemy Manager")
		int GetMadeShoots() const;
	void CreateNoHitAchievementEvent();
	void CreateNoHitMissAchievementEvent();


private:
	UPROPERTY(EditAnywhere, Category = "Deaths Streak")
		int FloatingSlugStreakN;
	UPROPERTY(EditAnywhere, Category = "Deaths Streak")
		int TeleportingSlugStreakN;
	UPROPERTY(EditAnywhere, Category = "Deaths Streak")
		int SuicidalSlugStreakN;

	// Keeps a list of achievements to be shown
	TArray<TSubclassOf<ABasicAchievement>> AchievementClasses;

	int MadeShoots;
	bool BeenHit;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
