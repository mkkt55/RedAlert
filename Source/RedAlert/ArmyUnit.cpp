// Fill out your copyright notice in the Description page of Project Settings.

#include "ArmyUnit.h"

#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Materials/Material.h"
#include "Engine/World.h"

#define AttackState 1
//might define or enum


AArmyUnit::AArmyUnit()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AArmyUnit::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AArmyUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (CurrentState == AttackState) {//1 stands for attacking state
		AttackTarget->ReceivedTotalDamage += DeltaTime*Damage;
	}
}


void AArmyUnit::MoveTo(FVector VecTarget)
{
	//to change the actor's Rotation (to let it see the target
	FVector VecNowLocation = GetActorLocation();
	FVector VecDirection = VecTarget - VecNowLocation;
	VecDirection.Normalize();
	FRotator R = VecDirection.Rotation();
	SetActorRotation(R);

	SetActorLocation(VecTarget);
	
}




void AArmyUnit::Attack(ARedAlertObjectBase *Target)
{

}
