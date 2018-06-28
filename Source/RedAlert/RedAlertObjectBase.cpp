// Fill out your copyright notice in the Description page of Project Settings.

#include "RedAlertObjectBase.h"


// Sets default values
ARedAlertObjectBase::ARedAlertObjectBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ConstructionComponent = CreateDefaultSubobject<URTSConstructionSiteComponent>(TEXT("Construction"));
	HealthComponent = CreateDefaultSubobject<URTSHealthComponent>(TEXT("Health"));
	AttackableComponent = CreateDefaultSubobject<URTSAttackableComponent>(TEXT("Attackable"));
	SelectableComponent = CreateDefaultSubobject<URTSSelectableComponent>(TEXT("Selectable"));
	OwnerComponent = CreateDefaultSubobject<URTSOwnerComponent>(TEXT("Owner"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
}

// Called when the game starts or when spawned
void ARedAlertObjectBase::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ARedAlertObjectBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentHealth -= ReceivedTotalDamage;
	ReceivedTotalDamage = 0;

}

