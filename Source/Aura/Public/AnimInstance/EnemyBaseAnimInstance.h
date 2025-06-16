// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EnemyBaseAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UEnemyBaseAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:

	/** Speed on the ground **/
	UPROPERTY(BlueprintReadOnly, Category = Stat)
	float GroundSpeed;
	
	/** Actor velocity */
	UPROPERTY(BlueprintReadOnly, Category = Stat)
	FVector Velocity;
	
	class AAuraCharacterEnemy* AuraEnemy;

	class UCharacterMovementComponent* MovCompREF;

public:
	UEnemyBaseAnimInstance();

	/**
	* Native initialization override point
	* This is called in editor and play 
	* Use this only for initalize non-character related stuff
	* */
	virtual void NativeInitializeAnimation() override;

	/**
	* Native update override point. It is usually a good idea to simply gather data in this step and
	* for the bulk of the work to be done in NativeUpdateAnimation.
	* This is called in editor and play
	* */
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
