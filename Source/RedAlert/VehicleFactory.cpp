// Fill out your copyright notice in the Description page of Project Settings.

#include "VehicleFactory.h"


AVehicleFactory::AVehicleFactory()
{
	PrimaryActorTick.bCanEverTick = true;

	ConstructionComponent->ConstructionTime = 30;
	ConstructionComponent->bStartImmediately = true;
	ConstructionComponent->bConsumesBuilders = false;
	ConstructionComponent->MaxAssignedBuilders = 1;
	ConstructionComponent->RefundFactor = 1;
	ConstructionComponent->RemainingConstructionTime = 0;

	HealthComponent->CurrentHealth = 2000;
	HealthComponent->MaximumHealth = 2000;

	ProductionComponent = CreateDefaultSubobject<URTSProductionComponent>(TEXT("Production"));
	ProductionComponent->CapacityPerQueue = 99;
	ProductionComponent->QueueCount = 1;
}


void AVehicleFactory::BeginPlay()
{
	Super::BeginPlay();

}

void AVehicleFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

