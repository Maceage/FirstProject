// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FPLamp.h"
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
		if (UKismetSystemLibrary::DoesImplementInterface(CodeDoorRef, UInteract::StaticClass()))
		{
			IInteract::Execute_Interact(CodeDoorRef);
		}

		CodeDoorRef = nullptr;
	}

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsWithInterface(GetWorld(), UInteract::StaticClass(), FoundActors);

	for (auto FoundActor : FoundActors)
	{
		if (UKismetSystemLibrary::DoesImplementInterface(FoundActor, UInteract::StaticClass()))
		{
			if (IInteract::Execute_CanInteract(FoundActor))
			{
				IInteract::Execute_Interact(FoundActor);
			}
		}
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
