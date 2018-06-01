// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RedAlertObjectBase.h"
#include"PowerStation.h"
#include"MineFactory.h"
#include"SoldierCamp.h"
#include"VehicleFactory.h"
#include "BaseStation.generated.h"

/**
 * 
 */
UCLASS()
class REDALERT_API ABaseStation : public ARedAlertObjectBase
{
	GENERATED_BODY()
public:
	ABaseStation();
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	APowerStation *CreatePowerStation();
	AMineFactory *CreateMineFactory();
	ASoldierCamp *CreateSoldierCamp();
	AVehicleFactory *CreateVehicleFactory();
	
};
