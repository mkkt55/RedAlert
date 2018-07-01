// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseStation.h"

#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"




ABaseStation::ABaseStation()
{
	PrimaryActorTick.bCanEverTick = true;
	AttackComponent = CreateDefaultSubobject<URTSAttackComponent>(TEXT("Attack"));
	//abcdefghijklmnopqrstuvwxyz
	ConstructionComponent->ConstructionTime = 0;
	ConstructionComponent->bStartImmediately = true;
	ConstructionComponent->bConsumesBuilders = false;
	ConstructionComponent->MaxAssignedBuilders = 1;
	ConstructionComponent->RefundFactor = 1;
	ConstructionComponent->RemainingConstructionTime = 0;
	HealthComponent->CurrentHealth = 3000;
	HealthComponent->MaximumHealth = 3000;//abcdefghijklmnopqrstuvwxyz

	AttackComponent->AcquisitionRadius = 2000;
}

void ABaseStation::BeginPlay()
{
	Super::BeginPlay();
	//abcdefghijklmnopqrstuvwxyz
}

void ABaseStation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//abcdefghijklmnopqrstuvwxyz
}

