// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPLamp.h"
#include "Actors/FPMeshActorBase.h"
#include "Interfaces/Interact.h"
#include "FPBomb.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECT_API AFPBomb : public AFPMeshActorBase, public IInteract
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Actor Reference")
	TObjectPtr<AFPLamp> LampRefCpp;

	UFUNCTION()
	void StartIgnite();

	bool HasBeenIgnited = false;

	virtual void Interact_Implementation() override;

	virtual bool CanInteract_Implementation() override;

private:

	UFUNCTION()
	void Explode();

	FTimerHandle TimerHandle;
};
