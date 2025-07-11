// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FPMeshActorBase.h"

// Sets default values
AFPMeshActorBase::AFPMeshActorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Comp"));
	RootComponent = MeshComp;
}

// Called when the game starts or when spawned
void AFPMeshActorBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFPMeshActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

