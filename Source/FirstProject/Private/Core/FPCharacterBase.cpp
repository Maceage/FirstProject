// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/FPCharacterBase.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Interfaces/Interact.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AFPCharacterBase::AFPCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.SetTickFunctionEnable(true);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void AFPCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void AFPCharacterBase::Move(const FInputActionValue& value)
{
	const FVector2D move = value.Get<FVector2D>();

	AddMovementInput(GetActorForwardVector() * move.X);
	AddMovementInput(GetActorRightVector() * move.Y);
}

void AFPCharacterBase::Look(const FInputActionValue& value)
{
	const FVector2D look = value.Get<FVector2D>();

	if (look.Length() != 0.0f)
	{
		AddControllerPitchInput(look.Y);
		AddControllerYawInput(look.X);
	}
}

void AFPCharacterBase::Interact()
{
	FHitResult OutHit;
	FVector Start = Camera->GetComponentLocation();

	FVector Forward = Camera->GetForwardVector();
	FVector End = Start + Forward * 10000.0f;

	FCollisionQueryParams CollisionQueryParams;

	DrawDebugLine(GetWorld(), Start, End, FColor::Orange, false, 1, 0, 1);

	if (GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionQueryParams))
	{
		bool bValidInterface = UKismetSystemLibrary::DoesImplementInterface(OutHit.GetActor(), UInteract::StaticClass());

		if (bValidInterface)
		{
			IInteract::Execute_Interact(OutHit.GetActor());
		}
	}
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
		EnhancedInputComponent->BindAction(MoveActions, ETriggerEvent::Triggered, this, &AFPCharacterBase::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AFPCharacterBase::Look);

		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AFPCharacterBase::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AFPCharacterBase::StopJumping);

		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &AFPCharacterBase::Interact);
	}
}
