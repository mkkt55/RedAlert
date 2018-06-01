// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArmyUnit.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class REDALERT_API ATank : public AArmyUnit
{
	GENERATED_BODY()
	

public:
	ATank();
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	
	
};
