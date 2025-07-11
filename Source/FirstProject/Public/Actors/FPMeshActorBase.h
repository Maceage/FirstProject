// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPMeshActorBase.generated.h"

UCLASS()
class FIRSTPROJECT_API AFPMeshActorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPMeshActorBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Mesh")
	TObjectPtr<UStaticMeshComponent> MeshComp;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
