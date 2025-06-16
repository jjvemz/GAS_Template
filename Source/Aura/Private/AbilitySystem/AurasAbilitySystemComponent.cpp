// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AurasAbilitySystemComponent.h"
#include "AuraGameplayTags.h"

void UAurasAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAurasAbilitySystemComponent::EffectApplied);


}

void UAurasAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
												const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTags.Broadcast(TagContainer);
}

