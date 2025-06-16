// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/AuraHUD.h"

#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/AuraMenuWidgetController.h"
#include "UI/WidgetController/OverlayAuraWidgetController.h"

UOverlayAuraWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController== nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayAuraWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		OverlayWidgetController->BindCallbacksToDependencies();
	}
	return OverlayWidgetController;
}

UAuraMenuWidgetController* AAuraHUD::GetAuraMenuWidgetController(const FWidgetControllerParams& WCParams)
{
	if (AuraMenuWidgetController == nullptr)
	{
		AuraMenuWidgetController = NewObject<UAuraMenuWidgetController>(this, AuraMenuWidgetControllerClass);
		AuraMenuWidgetController->SetWidgetControllerParams(WCParams);
		AuraMenuWidgetController->BindCallbacksToDependencies();
	}
	return AuraMenuWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class uninitialized, please fill out BP_AuraHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class uninitialized, please fill out BP_AuraHUD"));
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(Widget);
	
	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	UOverlayAuraWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);

	OverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialValues();
	Widget->AddToViewport();
}
