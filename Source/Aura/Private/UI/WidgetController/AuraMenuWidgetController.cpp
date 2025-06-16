// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/AuraMenuWidgetController.h"

#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"
#include "AuraGameplayTags.h"

void UAuraMenuWidgetController::BindCallbacksToDependencies()
{
	
}

void UAuraMenuWidgetController::BroadcastInitialValues()
{
	UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);

	check(AttributeInfo);

	FAuraAttributeInfo Info= AttributeInfo->FindAttributeInfoForTag(FAuraGameplayTags::Get().Attributes_Primary_Strength);
	Info.AttributeValue= AS;
	UE_LOG(LogTemp, Warning, TEXT("The strength value on AuraMenuWidgetController is: %f"), Info.AttributeValue);
	AttributeInfoDelegate.Broadcast(Info);
}
