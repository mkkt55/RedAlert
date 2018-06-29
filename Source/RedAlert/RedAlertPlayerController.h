// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RTSPlayerController.h"
#include "GameFramework/PlayerController.h"
#include"CameraPawn.h"
#include "EngineUtils.h"
#include "Landscape.h"
#include "Components/InputComponent.h"
#include "Engine/Engine.h"
#include "Engine/LocalPlayer.h"
#include "Kismet/GameplayStatics.h"

#include "RedAlertObjectBase.h"
#include"BaseStation.h"
#include"PowerStation.h"
#include"MineFactory.h"
#include"SoldierCamp.h"
#include"VehicleFactory.h"
#include"RedAlertBuilder.h"

#include"ArmyUnit.h"
#include"Soldiers.h"
#include"Tank.h"
#include"MineTruck.h"

#include"Engine/Scene.h"
#include "RedAlertPlayerController.generated.h"


#define NothingSelected -1

#define SelectBaseStation 0
#define SelectPowerStation 1
#define SelectMineFactory 2
#define SelectSoldierCamp 3
#define SelectVehicleFactory 4

#define UISelectPowerStation 10
#define UISelectMineFactory 11
#define UISelectSoldierCamp 12
#define UISelectVehicleFactory 13

#define SingleSelectUnit 20
#define MultipleSelectUnits 21

#define SoldingSth 31

/**
*
*/
UCLASS()
class REDALERT_API ARedAlertPlayerController : public ARTSPlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
public:
	ARedAlertPlayerController();
	virtual void PlayerTick(float DeltaTime) override;

	ACameraPawn* GetCameraPawn();

	UPROPERTY(Replicated)
	ARedAlertBuilder* BuilderPawn;
	UFUNCTION(Reliable, Server, WithValidation)
	void ServerSpawnBuilderPawn();
	void ServerSpawnBuilderPawn_Implementation();
	bool ServerSpawnBuilderPawn_Validate();


	/*Screen control*/
	void MovePawnToLocation(AActor* Actor, const FVector& Location);
	void MoveScreenX(float AxisValue);
	void MoveScreenY(float AxisValue);

	ACameraPawn* MainPawn;
	float MousePositionX;
	float MousePositionY;

	void LeftMouseClick();
	void FinishLeftMouseClick();
	void RightMouseClick();




	/*Selection related datas and functions*/

	//Select function and state
	bool SingleSelect(AActor*);
	bool MultipleSelect();

	//Selection is single, multiple or via UI, if single, stores witch type of object is selected. If multiple, those must all be armyunits.
	int32 SelectionState;
	//if single, store the actor in the pointer.
	AActor* SingleSelectedActor;
	//else, a TArray impleted.
	TArray<AArmyUnit*> MultipleSelectedUnits;




	/*Buiding related datas*/
	UFUNCTION(Reliable, Server, WithValidation)
	void ServerConfirmBuilding(UClass* BuildingClass);
	void ServerConfirmBuilding_Implementation(UClass* BuildingClass);
	bool ServerConfirmBuilding_Validate(UClass* BuildingClass);

	UClass* BuildingAwaiting;
	
	//Pointers store buildings.
	ABaseStation*  BaseStationPtr;
	APowerStation* PowerStationPtr;
	AMineFactory* MineFactoryPtr;
	ASoldierCamp* SoldierCampPtr;
	AVehicleFactory* VehicleFactoryPtr;


	void CreatePowerStation();

	void CreateMineFactory();
	void CreateSoldierCamp();
	void CreateVehicleFactory();


	bool CreateSoldier(); // And do not forget to cut the player's money.
	int32 SdrAwaitngCreation;
	//stands for the time needed to creat a soldier. 
	int32 SdrTimeCost;

	bool CreateTank();
	int32 TkAwaitngCreation;
	int32 TkTimeCost;

	bool CreateMineTruck();
	int32 MTAwaitngCreation;
	int32 MTimeCost;


};