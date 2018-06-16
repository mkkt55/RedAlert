// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RTSPlayerController.h"
#include "GameFramework/PlayerController.h"
#include"Components/InputComponent.h"
#include"CameraPawn.h"


#include "RedAlertObjectBase.h"
#include"BaseStation.h"
#include"PowerStation.h"
#include"MineFactory.h"
#include"SoldierCamp.h"
#include"VehicleFactory.h"

#include"ArmyUnit.h"
#include"Soldiers.h"
#include"Tank.h"
#include"MineTruck.h"

#include"RTSResourceType.h"

#include "ConstructorHelpers.h"
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

class USkeletalMesh;

class ARTSBuildingCursor;
class ARTSCameraBoundsVolume;
class URTSPlayerAdvantageComponent;
class URTSPlayerResourcesComponent;
class ARTSPlayerState;
class URTSResourceType;
class ARTSTeamInfo;
class ARTSVisionInfo;


/**
 * 
 */
UCLASS()
class REDALERT_API ARedAlertPlayerController : public ARTSPlayerController
{
	GENERATED_BODY()
	
protected:
	//virtual void BeginPlay() override;
public:
	ARedAlertPlayerController();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupInputComponent() override;

	ACameraPawn* GetCameraPawn();

private:


	/*Screen control*/
	void MovePawnToLocation(float AxisValue);
	void MoveScreenX(float AxisValue);
	void MoveScreenY(float AxisValue);

	ACameraPawn* MainPawn;
	float MousePositionX;
	float MousePositionY;

	void LeftMouseClick();




	/*Selection related datas and functions*/

	//Select function and state
	ARedAlertObjectBase *SingleSelect();
	AArmyUnit *MultipleSelect();

	//Selection is single, multiple or via UI, if single, stores witch type of object is selected. If multiple, those must all be armyunits.
	int32 SelectionState;
	//if single, store the actor in the pointer.
	ARedAlertObjectBase* SingleSelectedObj;
	//else, a TArray impleted.
	TArray<AArmyUnit*> MultipleSelectedUnits;




	/*Buiding related datas*/

	//Pointers store buildings.
	ABaseStation*  BaseStationPtr;
	APowerStation* PowerStationPtr;
	AMineFactory* MineFactoryPtr;
	ASoldierCamp* SoldierCampPtr;
	AVehicleFactory* VehicleFactoryPtr;


	APowerStation *CreatePowerStation();
	AMineFactory *CreateMineFactory();
	ASoldierCamp *CreateSoldierCamp();
	AVehicleFactory *CreateVehicleFactory();


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
