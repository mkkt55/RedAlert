// Fill out your copyright notice in the Description page of Project Settings.

#include "RedAlertObjectBase.h"


// Sets default values
ARedAlertObjectBase::ARedAlertObjectBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


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

	if (CurrentHealth <= 0) {
		GetDestroyed();
	}
}

bool ARedAlertObjectBase::GetDestroyed()
{
	Controller;
	return Destroy();
}