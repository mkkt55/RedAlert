// Fill out your copyright notice in the Description page of Project Settings.

#include "Soldiers.h"



ASoldiers::ASoldiers()
{
	PrimaryActorTick.bCanEverTick = true;
	
	HealthComponent->CurrentHealth = 400;
	HealthComponent->MaximumHealth = 400;
	ProductionComponent->ProductionTime = 2;
	ProductionComponent->RefundFactor = 1;
}


void ASoldiers::BeginPlay()
{
	Super::BeginPlay();

}

void ASoldiers::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


