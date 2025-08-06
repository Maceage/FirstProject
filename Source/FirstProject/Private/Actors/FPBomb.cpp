// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FPBomb.h"

#include "NiagaraFunctionLibrary.h"
#include "Actors/FPDoor.h"
#include "Actors/FPLamp.h"

void AFPBomb::BeginPlay()
{
	Super::BeginPlay();

	MaterialInst = MeshComp->CreateAndSetMaterialInstanceDynamic(0);
	
	if (LampRefCpp)
	{
		LampRefCpp->OnLightSwitchedOnDelegate.AddUniqueDynamic(this, &AFPBomb::Interact);
	}
}

void AFPBomb::StartIgnite_Implementation()
{
	HasBeenIgnited = true;
}

void AFPBomb::Interact_Implementation()
{
	if (!HasBeenIgnited)
	{
		StartIgnite();
	}
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

	if (ExplosionEffect)
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ExplosionEffect, GetActorLocation());
	}

	Destroy();
}
