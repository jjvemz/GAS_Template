// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UI/WidgetController/OverlayAuraWidgetController.h"
#include "AuraAbilitySystemLibrary.generated.h"

class UAuraMenuWidgetController;
class UOverlayAuraWidgetController;
/**
 * 
 */
UCLASS()
class AURA_API UAuraAbilitySystemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Aura| AbilitySystemController | WidgetController")
	static UOverlayAuraWidgetController* GetOverlayAuraWidgetController(const UObject* WorldContextObject);

	
	UFUNCTION(BlueprintPure, Category="Aura| AbilitySystemController | WidgetController")
	static UAuraMenuWidgetController* GetAuraMenuWidgetController(const UObject* WorldContextObject);
};
