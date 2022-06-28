// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PopulationContainer.generated.h"

/**
 * 
 */



USTRUCT(BlueprintType)
struct FPopulationModifier
{
	GENERATED_BODY()

		//~ The following member variable will be accessible by Blueprint Graphs:
		// This is the tooltip for our test variable.
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modifier")
		float ModifierValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modifier")
		FString ModifierType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modifier")
		int32 RemainingMonths;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modifier")
		FString ModifierName;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Modifier")
		TArray<FString> Removes;

	/**~
	* This UObject pointer is not accessible to Blueprint Graphs, but
	* is visible to UE4's reflection, smart pointer, and garbage collection
	* systems.
	*/
	UPROPERTY()
		UObject* SafeObjectPointer;



};

USTRUCT(BlueprintType)
struct FTrait
{
	GENERATED_BODY()

		//~ The following member variable will be accessible by Blueprint Graphs:
		// This is the tooltip for our test variable.





	/**~
	* This UObject pointer is not accessible to Blueprint Graphs, but
	* is visible to UE4's reflection, smart pointer, and garbage collection
	* systems.
	*/
	UPROPERTY()
		UObject* SafeObjectPointer;



};





UCLASS()
class NORTHERN_API UPopulationContainer : public UObject
{
	GENERATED_BODY()

public:
		UPROPERTY(EditAnywhere)
		int32 Number;

	UPROPERTY(EditAnywhere)
		float SexRatio;

	UPROPERTY(EditAnywhere)
		FString Age;

	UPROPERTY(EditAnywhere)
		FString PopType;

	UPROPERTY(EditAnywhere)
		float Health;

	UPROPERTY(EditAnywhere)
		float Happiness;

	UPROPERTY(EditAnywhere)
		float Loyalty;

	UPROPERTY(EditAnywhere)
		float Fertility;

	UPROPERTY(EditAnywhere)
		float Wealth;

	UPROPERTY(EditAnywhere)
		float Unity;

	UPROPERTY(EditAnywhere)
		TArray<FPopulationModifier> Modifiers;

	UFUNCTION(BlueprintCallable, Category = Properties)
		void CalculateHealth();

	UFUNCTION(BlueprintCallable, Category = Properties)
		void AddModifier(float valueIn, FString typeIn, int32 timeIn, FString nameIn);


	
};
