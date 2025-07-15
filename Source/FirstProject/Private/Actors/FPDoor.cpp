// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FPDoor.h"

// Sets default values
AFPDoor::AFPDoor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AFPDoor::Interact_Implementation()
{
	OpenDoor();
}

bool AFPDoor::CanInteract_Implementation()
{
	return false;
}

void AFPDoor::OpenDoor()
{
	SetActorRotation(RotationTarget);
}