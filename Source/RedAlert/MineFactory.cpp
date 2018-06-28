// Fill out your copyright notice in the Description page of Project Settings.

#include "MineFactory.h"





AMineFactory::AMineFactory()
{
	PrimaryActorTick.bCanEverTick = true;

	ConstructionComponent->ConstructionTime = 15;
	ConstructionComponent->bStartImmediately = true;
	ConstructionComponent->bConsumesBuilders = false;
	ConstructionComponent->MaxAssignedBuilders = 1;
	ConstructionComponent->RefundFactor = 1;
	ConstructionComponent->RemainingConstructionTime = 0;

	HealthComponent->CurrentHealth = 1400;
	HealthComponent->MaximumHealth = 1400;

	ProductionComponent = CreateDefaultSubobject<URTSProductionComponent>(TEXT("Production"));
	ProductionComponent->CapacityPerQueue = 99;
	ProductionComponent->QueueCount = 1;
}


void AMineFactory::BeginPlay()
{
	Super::BeginPlay();

}

void  AMineFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}