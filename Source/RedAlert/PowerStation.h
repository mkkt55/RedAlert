// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RedAlertObjectBase.h"
#include "PowerStation.generated.h"

/**
 * 
 */
UCLASS()
class REDALERT_API APowerStation : public ARedAlertObjectBase
{
	GENERATED_BODY()
	
public:
	APowerStation();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	
};
