	// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPLamp.h"
#include "NiagaraSystem.h"
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

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void StartIgnite();

	virtual void Interact_Implementation() override;

	virtual bool CanInteract_Implementation() override;

protected:

	virtual void BeginPlay() override;
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ignition", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMaterialInstanceDynamic> MaterialInst;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Actor Reference", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AFPLamp> LampRefCpp;

	UPROPERTY(EditAnywhere, Category = "Explosion", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UNiagaraSystem> ExplosionEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Explosion", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USoundBase> ExplosionSound;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ignition", meta = (AllowPrivateAccess = "true"))
	float IgnitionDuration = 2.0f;
	
	bool HasBeenIgnited = false;
	
	UFUNCTION(BlueprintCallable)
	void Explode();
};
