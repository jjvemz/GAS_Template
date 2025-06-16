// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraCharacterEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacterEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
public:
	AAuraCharacterEnemy();
	
	/* Enemy interface*/
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

	UPROPERTY(BlueprintReadWrite)
	bool bHighLightActor = false;

	/** Combat Interface*/
	virtual int32 GetPlayerLevel() override;
	
	/** End Combat Interface*/

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category ="Character Defaults")
	int32 Level = 1;
	
};
