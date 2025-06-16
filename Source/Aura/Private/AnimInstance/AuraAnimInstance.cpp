// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/AuraAnimInstance.h"

#include "Character/AuraCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

UAuraAnimInstance::UAuraAnimInstance()
{
	GroundSpeed = 0;
}

void UAuraAnimInstance::NativeInitializeAnimation()
{
	AuraCharacter = Cast<AAuraCharacter>(TryGetPawnOwner());
	if (AuraCharacter) MovCompREF = Cast<UCharacterMovementComponent>(AuraCharacter->GetCharacterMovement());
}

void UAuraAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if (AuraCharacter)
	{
		Velocity = AuraCharacter->GetVelocity();
		GroundSpeed = FVector(Velocity.X, Velocity.Y, 0).Size();
		
	}
}
