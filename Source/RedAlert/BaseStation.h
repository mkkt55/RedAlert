// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RedAlertObjectBase.h"
#include "RTSPluginPCH.h"
#include "RTSAttackComponent.h"
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

	URTSAttackComponent* AttackComponent;
	
};
