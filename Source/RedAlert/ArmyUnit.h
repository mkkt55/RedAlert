// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RedAlertObjectBase.h"
#include "ArmyUnit.generated.h"

#define AttackState 0
#define MovingState 1
#define StoppedState 2
//might define or enum


/**
*
*/
UCLASS()
class REDALERT_API AArmyUnit : public ARedAlertObjectBase
{
	GENERATED_BODY()
public:
	AArmyUnit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Will be called by controller.may need a funtion to stop all action when receive another order from controller or attack target has been destroyed.
	void MoveTo(float x, float y);//may need to set member variable and enable movement actually in Tick() function--you need to move a little bit every frame according to speed.
	void Attack(ARedAlertObjectBase *Target);
	void Stop();


	float Damage;
	float Speed;
	float AttackDistance;

	int8 ActionState;

	FVector MoveTarget;
	ARedAlertObjectBase *AttackTarget;
};