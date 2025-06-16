// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/WidgetController/AuraMenuWidgetController.h"
#include "AuraHUD.generated.h"

class UAuraMenuWidgetController;
class UAttributeSet;
class UAbilitySystemComponent;
class UOverlayAuraWidgetController;
class UAuraUserWidget;
struct FWidgetControllerParams;
/**
 * 
 */
UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()

public:
	
	
	UOverlayAuraWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);
	UAuraMenuWidgetController* GetAuraMenuWidgetController(const FWidgetControllerParams& WCParams);
	
	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);
	
protected:
	

private:
	UPROPERTY()
	TObjectPtr<UAuraUserWidget> OverlayWidget;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayAuraWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayAuraWidgetController> OverlayWidgetControllerClass;

	UPROPERTY()
	TObjectPtr<UAuraMenuWidgetController> AuraMenuWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraMenuWidgetController> AuraMenuWidgetControllerClass;
};
