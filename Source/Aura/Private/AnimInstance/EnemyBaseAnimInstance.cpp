// Fill out your copyright notice in the Description page of Project Settings.

#include "AnimInstance/EnemyBaseAnimInstance.h"
#include "Character/AuraCharacterEnemy.h"
#include "GameFramework/CharacterMovementComponent.h"

UEnemyBaseAnimInstance::UEnemyBaseAnimInstance()
{
	GroundSpeed = 0;
}

void UEnemyBaseAnimInstance::NativeInitializeAnimation()
{
	AuraEnemy = Cast<AAuraCharacterEnemy>(TryGetPawnOwner());
	if (AuraEnemy) MovCompREF = Cast<UCharacterMovementComponent>(AuraEnemy->GetCharacterMovement());
}

void UEnemyBaseAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if (AuraEnemy)
	{
		Velocity = AuraEnemy->GetVelocity();
		GroundSpeed = FVector(Velocity.X, Velocity.Y, 0).Size();
	}
}
