// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RedAlertObjectBase.h"
#include "RTSPluginPCH.h"
#include "RTSProductionComponent.h"
#include "SoldierCamp.generated.h"

/**
 * 
 */
UCLASS()
class REDALERT_API ASoldierCamp : public ARedAlertObjectBase
{
	GENERATED_BODY()
	
public:

	ASoldierCamp();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

	URTSProductionComponent* ProductionComponent;

};
