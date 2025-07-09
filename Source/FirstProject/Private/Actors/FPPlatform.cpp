// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FPPlatform.h"

// Sets default values
AFPPlatform::AFPPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetActorScale3D(Size);
}

// Called when the game starts or when spawned
void AFPPlatform::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFPPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AddActorWorldOffset(GetActorLocation() * DeltaTime);
}
