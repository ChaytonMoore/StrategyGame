// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPTribe.h"

// Sets default values
ACPPTribe::ACPPTribe()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPTribe::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPPTribe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPPTribe::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACPPTribe::CreateInfantPop(UPopulationContainer* Parent, int Number)
{
	UPopulationContainer NPop;
	NPop.Number = Number;
	NPop.PopType = Parent->PopType;
	NPop.Age = "Infant";
	Pops.Add(&NPop);
}

UPopulationContainer* ACPPTribe::GetSmallestPopofAge(FString PopAge)
{
	int smallest = MAX_int32;
	UPopulationContainer* out = nullptr;
	for (UPopulationContainer* i : Pops)
	{
		if (i->Age==PopAge && i->Number<smallest)
		{
			out = i;
			smallest = i->Number;
		}
	}


	return out;
}

void ACPPTribe::FavourPop(UPopulationContainer* specificpop)
{
	//put one pop above the other
	for (UPopulationContainer* i: Pops)
	{
		if (i!=specificpop)
		{
			i->AddModifier(-5,"Loyalty",14,"Disbained");
		}


	}
	specificpop->AddModifier(25, "Loyalty", 12, "Favoured");
	specificpop->AddModifier(15, "Happiness", 12, "Favoured Happiness");

}

void ACPPTribe::DistributeFood()
{
	Food -= Pops.Num()*10;
	//people like it when you give them extra food
	for (UPopulationContainer* i : Pops)
	{
		i->AddModifier(5, "Loyalty", 4, "Fed");
		i->AddModifier(5, "Happiness", 4, "Fed Happiness");
		i->AddModifier(5, "Unity", 6, "Unity");
		if (i->Health<40)
		{
			i->AddModifier(10, "Happiness", 4, "Fed Health");
		}
	}



}

bool ACPPTribe::canFavourPop(UPopulationContainer* specificpop)
{
	if (specificpop->Age == "Infant" || specificpop->Age == "Child")
	{
		return false;
	}
	if (specificpop->Loyalty == 100)
	{
		return false;
	}


	return true;
}

bool ACPPTribe::canDistributeFood()
{
	if (Food>Pops.Num() * 10)
	{
		return false;
	}


	return true;
}

void ACPPTribe::SetupStartingPops()
{
	//This function is called when 



}

void ACPPTribe::YearlyReproduction()
{
	
	for (UPopulationContainer* i: Pops) 
	{
		if (i->Age=="Adult" || i->Age=="YoungAdult")
		{
			//these are the only two that can reproduce
			int HavingKids = i->Fertility * i->Happiness * pow(i->Health,1)*i->SexRatio*i->Number;
			int deaths = HavingKids * pow((1-i->Health),4); //some die in childbirth etc
			HavingKids -= deaths;

			int popFTemp = i->Number * (i->SexRatio) - deaths; //recalc gender balance and number in pop
			i->Number -= deaths;
			i->SexRatio = popFTemp / i->Number;
			

			UPopulationContainer* AddToPop = GetSmallestPopofAge("Infant");
			if (AddToPop)
			{
				if (AddToPop->Number<100)
				{
					//Add to the existing pop

					AddToPop->Number += HavingKids;
					//will need to recalc stats for the pop
				}
				else
				{
					CreateInfantPop(i,HavingKids);
				}
			}
			else
			{
				CreateInfantPop(i,HavingKids);
			}


		}
	}


}


