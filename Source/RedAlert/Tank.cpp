// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"


ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = true;

	HealthComponent->CurrentHealth = 1000;
	HealthComponent->MaximumHealth = 1000;
	ProductionComponent->ProductionTime = 15;
	ProductionComponent->RefundFactor = 1;
}


void  ATank::BeginPlay()
{
	Super::BeginPlay();

}

void  ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



