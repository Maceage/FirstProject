// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/FPCharacterBase.h"
#include "EnhancedInputComponent.h"

// Sets default values
AFPCharacterBase::AFPCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFPCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void AFPCharacterBase::DoMove(const FInputActionValue& value)
{
	const FVector2D move = value.Get<FVector2D>();

	AddMovementInput(GetActorForwardVector() * move.X);
	AddMovementInput(GetActorRightVector() * move.Y);
}

void AFPCharacterBase::DoJump(const FInputActionValue& value)
{
	const bool jump = value.Get<bool>();

	if (jump)
	{
		Jump();
	}
	else
	{
		StopJumping();
	}
}

void AFPCharacterBase::DoLook(const FInputActionValue& value)
{
	const FVector2D look = value.Get<FVector2D>();

	AddControllerPitchInput(look.Y);
	AddControllerYawInput(look.X);
}

// Called every frame
void AFPCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AFPCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveActions, ETriggerEvent::Triggered, this, &AFPCharacterBase::DoMove);
		EnhancedInputComponent->BindAction(JumpActions, ETriggerEvent::Triggered, this, &AFPCharacterBase::DoJump);

		EnhancedInputComponent->BindAction(LookActions, ETriggerEvent::Triggered, this, &AFPCharacterBase::DoLook);
	}
}

