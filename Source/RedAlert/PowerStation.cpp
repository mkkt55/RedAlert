// Fill out your copyright notice in the Description page of Project Settings.

#include "PowerStation.h"




APowerStation::APowerStation()
{
	PrimaryActorTick.bCanEverTick = true;
	AttackComponent = CreateDefaultSubobject<URTSAttackComponent>(TEXT("Attack"));
	//abcdefghijklmnopqrstuvwxyz
	ConstructionComponent->ConstructionTime = 20;
	ConstructionComponent->bStartImmediately = true;
	ConstructionComponent->bConsumesBuilders = false;
	ConstructionComponent->MaxAssignedBuilders = 1;
	ConstructionComponent->RefundFactor = 1;
	ConstructionComponent->RemainingConstructionTime = 0;
	HealthComponent->CurrentHealth = 1000;
	HealthComponent->MaximumHealth = 1000;
	//abcdefghijklmnopqrstuvwxyz
	AttackComponent->AcquisitionRadius = 1000;
}


void APowerStation::BeginPlay()
{
	Super::BeginPlay();
	//abcdefghijklmnopqrstuvwxyz
}

void APowerStation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);//abcdefghijklmnopqrstuvwxyz
						   //abcdefghijklmnopqrstuvwxyz
}