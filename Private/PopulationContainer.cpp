// Fill out your copyright notice in the Description page of Project Settings.
#include "PopulationContainer.h"
#include "..\TribalUtils.h"

void UPopulationContainer::CalculateHealth()
{
	//default 50 for health
	Health = 50;
	for (FPopulationModifier i: Modifiers)
	{
		if(i.ModifierType=="Health")
		{
			Health += i.ModifierValue;
		}
	}
	Health = UTribalUtils::ClampStat(Health);

}

void UPopulationContainer::AddModifier(float valueIn, FString typeIn, int32 timeIn, FString nameIn)
{

	FPopulationModifier t;
	t.ModifierValue = valueIn;
	t.ModifierName = nameIn;
	t.ModifierType = typeIn;
	t.RemainingMonths = timeIn;


	//cant use add uniquye
	bool canAdd = true;
	for (FPopulationModifier i: Modifiers)
	{
		if (t.ModifierName == i.ModifierName)
		{
			canAdd = false;
			break;
		}
	}
	if (canAdd)
	{
		Modifiers.Add(t);
	}

}



