// Fill out your copyright notice in the Description page of Project Settings.

#include "SoldierCamp.h"




ASoldierCamp::ASoldierCamp()
{
	PrimaryActorTick.bCanEverTick = true;
	ConstructionComponent->ConstructionTime = 15;
	ConstructionComponent->bStartImmediately = true;
	ConstructionComponent->bConsumesBuilders = false;
	ConstructionComponent->MaxAssignedBuilders = 1;
	ConstructionComponent->RefundFactor = 1;
	ConstructionComponent->RemainingConstructionTime = 0;

	HealthComponent->CurrentHealth = 1000;
	HealthComponent->MaximumHealth = 1000;

	ProductionComponent = CreateDefaultSubobject<URTSProductionComponent>(TEXT("Production"));
	ProductionComponent->CapacityPerQueue = 99;
	ProductionComponent->QueueCount = 1;
}


void ASoldierCamp::BeginPlay()
{
	Super::BeginPlay();

}

void ASoldierCamp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}