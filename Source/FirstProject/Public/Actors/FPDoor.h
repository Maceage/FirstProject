// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPMeshActorBase.h"
#include "GameFramework/Actor.h"
#include "Interfaces/Interact.h"
#include "FPDoor.generated.h"

UCLASS()
class FIRSTPROJECT_API AFPDoor : public AFPMeshActorBase, public IInteract
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFPDoor();

	virtual void Interact_Implementation() override;

	virtual bool CanInteract_Implementation() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rotation")
	FRotator RotationTarget;

public:

	void OpenDoor();

};
