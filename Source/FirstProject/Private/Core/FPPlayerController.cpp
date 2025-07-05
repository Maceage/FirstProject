// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/FPPlayerController.h"
#include "EnhancedInputSubsystems.h"

void AFPPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(MovementContext, 0);
	}
}
