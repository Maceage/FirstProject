// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPLamp.h"
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

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OpenDoor();

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(BlueprintReadOnly, Category = "Rotation", meta = (AllowPrivateAccess = "true"))
	bool IsOpen = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Actor Reference", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AFPLamp> LampRefCpp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rotation", meta = (AllowPrivateAccess = "true"))
	FRotator RotationTarget;
};
