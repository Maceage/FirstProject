// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FPLamp.h"

void AFPLamp::BeginPlay()
{
	Super::BeginPlay();

	CodeMaterialInst = MeshComp->CreateAndSetMaterialInstanceDynamic(0);
}

void AFPLamp::ToggleLamp()
{
	IsOn = !IsOn;

	CodeMaterialInst->SetScalarParameterValue(TEXT("EmissiveStrength"), IsOn ? 20.0f : 0.0f);

	OnLightSwitchedOnDelegate.Broadcast();
}

void AFPLamp::Interact_Implementation()
{
	ToggleLamp();
}

bool AFPLamp::CanInteract_Implementation()
{
	return false;
}
