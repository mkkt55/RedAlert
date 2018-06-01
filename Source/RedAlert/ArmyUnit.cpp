// Fill out your copyright notice in the Description page of Project Settings.

#include "ArmyUnit.h"


// Sets default values
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
	if (CurrentState == 1) {//1 stands for attacking state
		AttackTarget->ReceivedTotalDamage += DeltaTime*Damage;
	}
	//SetActorLocation(); using something like --Speed * DeltaTime--and to set direction you might call some funtion like GetActorLocation() as well.
}


void AArmyUnit::MoveTo(float x, float y)
{
	MoveTarget.X = x;
	MoveTarget.Y = y;
}

void AArmyUnit::Attack(ARedAlertObjectBase *Target)
{
	AttackTarget = Target;
}

