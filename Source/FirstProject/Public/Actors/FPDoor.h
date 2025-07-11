// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPMeshActorBase.h"
#include "GameFramework/Actor.h"
#include "FPDoor.generated.h"

UCLASS()
class FIRSTPROJECT_API AFPDoor : public AFPMeshActorBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFPDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rotation")
	FRotator RotationTarget;

public:

	void OpenDoor();

};
