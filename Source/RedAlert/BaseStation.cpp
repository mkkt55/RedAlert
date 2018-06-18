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

