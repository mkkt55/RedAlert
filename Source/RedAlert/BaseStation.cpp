// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseStation.h"


ABaseStation::ABaseStation()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABaseStation::BeginPlay()
{
	Super::BeginPlay();

}

void ABaseStation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


APowerStation *ABaseStation::CreatePowerStation()
{
	return NULL;
}

AMineFactory *ABaseStation::CreateMineFactory()
{
	return NULL;
}

ASoldierCamp *ABaseStation::CreateSoldierCamp()
{
	return NULL;
}


AVehicleFactory *ABaseStation::CreateVehicleFactory()
{
	return NULL;
}
