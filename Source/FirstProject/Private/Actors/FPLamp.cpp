// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FPLamp.h"

void AFPLamp::BeginPlay()
{
	Super::BeginPlay();

	CodeMaterialInst = MeshComp->CreateAndSetMaterialInstanceDynamic(0);
}

void AFPLamp::ToggleLamp()
{
	CodeIsOn = !CodeIsOn;

	CodeMaterialInst->SetScalarParameterValue(TEXT("EmissiveStrength"), CodeIsOn ? 20.0f : 0.0f);

	if (CodeIsOn)
	{
		OnLightSwitchedOnDelegate.Broadcast();
	}
}

void AFPLamp::Interact_Implementation()
{
	ToggleLamp();
}

bool AFPLamp::CanInteract_Implementation()
{
	return false;
}
