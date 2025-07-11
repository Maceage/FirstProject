// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FPLamp.h"

#include "Actors/FPBomb.h"
#include "Actors/FPDoor.h"
#include "Kismet/GameplayStatics.h"

void AFPLamp::BeginPlay()
{
	Super::BeginPlay();

	CodeMaterialInst = MeshComp->CreateAndSetMaterialInstanceDynamic(0);
}

void AFPLamp::ToggleLamp()
{
	CodeIsOn = !CodeIsOn;

	CodeMaterialInst->SetScalarParameterValue(TEXT("EmissiveStrength"), CodeIsOn ? 20.0f : 0.0f);

	if (CodeDoorRef)
	{
		CodeDoorRef->OpenDoor();

		CodeDoorRef = nullptr;
	}

	CodeBombRef = Cast<AFPBomb>(UGameplayStatics::GetActorOfClass(GetWorld(), AFPBomb::StaticClass()));

	if (CodeBombRef && !CodeBombRef->HasBeenIgnited)
	{
		CodeBombRef->StartIgnite();
	}
}