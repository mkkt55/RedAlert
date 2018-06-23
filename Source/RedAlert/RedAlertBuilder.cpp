// Fill out your copyright notice in the Description page of Project Settings.

#include "RedAlertBuilder.h"


// Sets default values
ARedAlertBuilder::ARedAlertBuilder()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARedAlertBuilder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARedAlertBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARedAlertBuilder::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

