// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PopulationContainer.h"
#include "CPPTribe.generated.h"
#include "GameCharacter.h"










UCLASS()
class NORTHERN_API ACPPTribe : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPPTribe();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
	TArray<UPopulationContainer*> Pops;

	UPROPERTY(EditAnywhere)
	int32 Food;

	UPROPERTY(EditAnywhere)
	UGameCharacter* Leader;

	UPROPERTY(EditAnywhere)
	TArray<UGameCharacter*> Notables;
	

	UFUNCTION(BlueprintCallable, Category = Properties)
		void YearlyReproduction();

	UFUNCTION(BlueprintCallable, Category = Properties)
		void CreateInfantPop(UPopulationContainer* Parent, int Number);

	UFUNCTION(BlueprintCallable, Category = Properties)
		UPopulationContainer* GetSmallestPopofAge(FString PopAge);


	//Each one of these can only be applied to certain types of pops
	UFUNCTION(BlueprintCallable, Category = Properties)
		void FavourPop(UPopulationContainer* specificpop);
	
	
	UFUNCTION(BlueprintCallable, Category = Properties)
		void DistributeFood();


	UFUNCTION(BlueprintCallable, Category = Properties)
		bool canFavourPop(UPopulationContainer* specificpop);

	UFUNCTION(BlueprintCallable, Category = Properties)
		bool canDistributeFood();

	UFUNCTION(BlueprintCallable, Category = Properties)
		void SetupStartingPops();



	

};
