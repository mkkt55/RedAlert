// Fill out your copyright notice in the Description page of Project Settings.

#include "MineTruck.h"



AMineTruck::AMineTruck()
{
	PrimaryActorTick.bCanEverTick = true;

	HealthComponent->CurrentHealth = 1400;
	HealthComponent->MaximumHealth = 1400;
	ProductionComponent->ProductionTime = 20;
	ProductionComponent->RefundFactor = 1;

	Gather = CreateDefaultSubobject<URTSGathererComponent>(TEXT("Gatherer"));
}


void  AMineTruck::BeginPlay()
{
	Super::BeginPlay();

}

void  AMineTruck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

