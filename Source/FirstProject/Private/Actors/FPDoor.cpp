// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FPDoor.h"

// Sets default values
AFPDoor::AFPDoor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Comp"));
	RootComponent = MeshComp;
}

// Called when the game starts or when spawned
void AFPDoor::BeginPlay()
{
	Super::BeginPlay();

	SetActorRotation(RotationTarget);
}

// Called every frame
void AFPDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

