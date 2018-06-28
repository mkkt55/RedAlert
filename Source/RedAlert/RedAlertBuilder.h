// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "RTSPluginPCH.h"
#include "RTSBuilderComponent.h"
#include "RTSOwnerComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "BaseStation.h"
#include "PowerStation.h"
#include "SoldierCamp.h"
#include "MineFactory.h"
#include "VehicleFactory.h"

#include "RedAlertBuilder.generated.h"

UCLASS()
class REDALERT_API ARedAlertBuilder : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARedAlertBuilder();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
	UFloatingPawnMovement* Movement;
	UPROPERTY(EditAnywhere)
	URTSBuilderComponent* Builder;
	UPROPERTY(EditAnywhere)
	URTSOwnerComponent* OwnerComponent;
	UPROPERTY(EditAnywhere)
	USceneComponent* Root;
	
};
