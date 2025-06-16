// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/AuraPlayerController.h"


#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"


AAuraPlayerController::AAuraPlayerController()
{
	bReplicates= true;
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit;

	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor= CurrentActor;
	CurrentActor = Cast<IEnemyInterface>(CursorHit.GetActor());

	/**
	 *Line trace from cursor. Possible scenarios:
	 *A. LastActor is null && CurrentActor is null
	 *		- Do nothing
	 *B. LastActor is null && CurrentActor is valid
	 *		- Highlight CurrentActor
	 *C. LastActor is valid && CurrentActor is null
	 *		- UnHighlight LastActor
	 *D. Both Actors are valid, but LastActor != CurrentActor
	 *		- UnHighlight LastActor, and Highlight CurrentActor
	 *E. Both Actors are valid, but LastActor == CurrentActor
	 *		-Do nothing
	 ***/

	if (LastActor == nullptr)
	{
		if (CurrentActor != nullptr) CurrentActor->HighlightActor();
		
	}
	else
	{
		if (CurrentActor == nullptr)  LastActor->UnHighlightActor();
		else
		{
			if (LastActor != CurrentActor)
			{
				LastActor->UnHighlightActor();
				CurrentActor->HighlightActor();
			}
		}
	}
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
	
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraInputContext);

	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(AuraInputContext, 0);
	}

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2d InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f , Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(Rotation).GetUnitAxis(EAxis::Y);

	if(APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection , InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection , InputAxisVector.X);

	}
}

