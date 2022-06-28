// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTestCase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class NORTHERN_API UGameplayTestCase : public UObject
{
	GENERATED_BODY()

public:


	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "callF")
		bool PerformCheck();
	
};
