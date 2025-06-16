// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacterEnemy.h"

#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/AurasAbilitySystemComponent.h"
#include "Aura/Aura.h"

AAuraCharacterEnemy::AAuraCharacterEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UAurasAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

void AAuraCharacterEnemy::HighlightActor()
{
	bHighLightActor = true;
	GetMesh()->SetRenderCustomDepth(bHighLightActor);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	WeaponMesh->SetRenderCustomDepth(bHighLightActor);
	WeaponMesh->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAuraCharacterEnemy::UnHighlightActor()
{
	bHighLightActor = false;
	GetMesh()->SetRenderCustomDepth(bHighLightActor);
	WeaponMesh->SetRenderCustomDepth(bHighLightActor);

}

int32 AAuraCharacterEnemy::GetPlayerLevel()
{
	return Level;
}

void AAuraCharacterEnemy::BeginPlay()
{
	Super::BeginPlay();
	InitAbilityActorInfo();
}

void AAuraCharacterEnemy::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UAurasAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
}
