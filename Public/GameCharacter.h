// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameCharacter.generated.h"




USTRUCT(BlueprintType)
struct FRace
{
	GENERATED_BODY()

		//~ The following member variable will be accessible by Blueprint Graphs:
		// This is the tooltip for our test variable.
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
		FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
		TArray<float> GenericFacialFeatures;


	/**~
	* This UObject pointer is not accessible to Blueprint Graphs, but
	* is visible to UE4's reflection, smart pointer, and garbage collection
	* systems.
	*/
	UPROPERTY()
		UObject* SafeObjectPointer;



};


/**
 * 
 */
UCLASS()
class NORTHERN_API UGameCharacter : public UObject
{
	GENERATED_BODY()


	
};
