// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/FPMeshActorBase.h"
#include "FPBomb.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECT_API AFPBomb : public AFPMeshActorBase
{
	GENERATED_BODY()

public:
	
	void StartIgnite();

	bool HasBeenIgnited = false;

private:

	UFUNCTION()
	void Explode();

	FTimerHandle TimerHandle;
};
