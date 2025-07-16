// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/FPMeshActorBase.h"
#include "Interfaces/Interact.h"
#include "FPLamp.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLightSwitchedOnSignature);

UCLASS()
class FIRSTPROJECT_API AFPLamp : public AFPMeshActorBase, public IInteract
{
	GENERATED_BODY()

public:
	
	virtual void Interact_Implementation() override;

	virtual bool CanInteract_Implementation() override;

	UPROPERTY(BlueprintAssignable)
	FLightSwitchedOnSignature OnLightSwitchedOnDelegate;
	
protected:

	virtual void BeginPlay() override;

private:
	
	bool IsOn = false;

	TObjectPtr<UMaterialInstanceDynamic> CodeMaterialInst;

	void ToggleLamp();
};
