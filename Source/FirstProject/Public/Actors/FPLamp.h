// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/FPMeshActorBase.h"
#include "Interfaces/Interact.h"
#include "FPLamp.generated.h"

UCLASS()
class FIRSTPROJECT_API AFPLamp : public AFPMeshActorBase, public IInteract
{
	GENERATED_BODY()

public:
	
	void ToggleLamp();

	virtual void Interact_Implementation() override;

	virtual bool CanInteract_Implementation() override;
	
protected:

	virtual void BeginPlay() override;
	
	TObjectPtr<UMaterialInstanceDynamic> CodeMaterialInst;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "References")
	TObjectPtr<AActor> CodeDoorRef;

private:
	bool CodeIsOn = false;
};
