// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArmyUnit.h"
#include "MineTruck.generated.h"

/**
 * 
 */
UCLASS()
class REDALERT_API AMineTruck : public AArmyUnit
{
	GENERATED_BODY()
	
public:
	AMineTruck();
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	//use attack() to "attack" resources
	
};
