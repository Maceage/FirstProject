// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FPBomb.h"

#include "Actors/FPDoor.h"
#include "Actors/FPLamp.h"

void AFPBomb::BeginPlay()
{
	Super::BeginPlay();

	if (LampRefCpp)
	{
		LampRefCpp->OnLightSwitchedOnDelegate.AddUniqueDynamic(this, &AFPBomb::StartIgnite);
	}
}

void AFPBomb::StartIgnite()
{
	if (HasBeenIgnited)
	{
		return;
	}
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Orange, TEXT("FzzzzzZZZZzzz!"));
	}

	GetWorldTimerManager().SetTimer(TimerHandle, this, &AFPBomb::Explode, 2.0f, false);

	HasBeenIgnited = true;
}

void AFPBomb::Interact_Implementation()
{
	StartIgnite();
}

bool AFPBomb::CanInteract_Implementation()
{
	return !HasBeenIgnited;
}

void AFPBomb::Explode()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Orange, TEXT("Boom!"));
	}

	Destroy();
}
