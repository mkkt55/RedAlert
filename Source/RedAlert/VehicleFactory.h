// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RedAlertObjectBase.h"
#include"Tank.h"
#include"MineTruck.h"
#include "VehicleFactory.generated.h"

/**
 * 
 */
UCLASS()
class REDALERT_API AVehicleFactory : public ARedAlertObjectBase
{
	GENERATED_BODY()
public:
	AVehicleFactory();
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	
	
};
