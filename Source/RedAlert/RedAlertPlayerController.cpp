// Fill out your copyright notice in the Description page of Project Settings.

#include "RedAlertPlayerController.h"




ARedAlertPlayerController::ARedAlertPlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
	CameraSpeed = 1000;
	CameraScrollThreshold = 20;
	TSubclassOf<URTSResourceType> ResrceType;
	static ConstructorHelpers::FObjectFinder<UBlueprint> MoneyClass(TEXT("Blueprint'/Game/Resources/Money.Money'"));
	if (MoneyClass.Object) {
		//ResrceType = (UClass*)MoneyClass.Object->GeneratedClass;
		//for (int i = 0; i < 3; i++) 
	}
}
void ARedAlertPlayerController::BeginPlay()
{
	Super::BeginPlay();
	MainPawn = Cast<ACameraPawn>(GetPawn());
	if (MainPawn == NULL) {
		UE_LOG(LogTemp, Warning, TEXT("Error"));
	}

}

ACameraPawn* ARedAlertPlayerController::GetCameraPawn()
{
	return MainPawn;
}

void ARedAlertPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ARedAlertPlayerController::MovePawnToLocation(float value)
{

}

void ARedAlertPlayerController::MoveScreenX(float AxisValue)
{
	if (MainPawn != NULL) {
		MainPawn->CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
	}
	else {
		MainPawn = Cast<ACameraPawn>(GetPawn());
		UE_LOG(LogTemp, Warning, TEXT("Error"));
	}
}

void ARedAlertPlayerController::MoveScreenY(float AxisValue)
{
	if (MainPawn != NULL) {
		MainPawn->CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
	}
	else {
		MainPawn = Cast<ACameraPawn>(GetPawn());
		UE_LOG(LogTemp, Warning, TEXT("Error"));
	}
}

void ARedAlertPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	

}




void ARedAlertPlayerController::LeftMouseClick()
{
	enum _EObject
	{
		BaseStation,
		PowerStation,
		MineFactory,
		SoldierCamp,
		VehicleFactory,

		Soldiers,
		Tank,
		MineTruck,
	};

	TEnumAsByte<_EObject> EObject;
	TArray<TEnumAsByte < EObjectTypeQuery >> FindArmyUnit;
	//FindArmyUnit.Add(EObject);
	TArray<TEnumAsByte < EObjectTypeQuery >> FindBaseStaion;
	TArray<TEnumAsByte < EObjectTypeQuery >> FindPowerStation;
	TArray<TEnumAsByte < EObjectTypeQuery >> FindMineFactory;
	TArray<TEnumAsByte < EObjectTypeQuery >> FindSoldierCamp;
	TArray<TEnumAsByte < EObjectTypeQuery >> FindVehicleFactory;
	FHitResult Hit(ForceInit);

	if (SelectionState == NothingSelected) {
		GetHitResultUnderCursorForObjects(FindArmyUnit, false, Hit);
	}
	else if (SelectionState == SelectBaseStation) {

	}
	else if (SelectionState == SelectPowerStation) {

	}
	else if (SelectionState == SelectMineFactory) {

	}
	else if (SelectionState == SelectSoldierCamp) {

	}
	else if (SelectionState == SelectVehicleFactory) {

	}
	else if (SelectionState == UISelectPowerStation) {

	}
	else if (SelectionState == UISelectMineFactory) {

	}
	else if (SelectionState == UISelectSoldierCamp) {

	}
	else if (SelectionState == UISelectVehicleFactory) {

	}
	else if (SelectionState == SingleSelectUnit) {

	}
	else if (SelectionState == MultipleSelectUnits) {

	}
	else if (SelectionState == SoldingSth) {

	}

	return;
}


APowerStation *ARedAlertPlayerController::CreatePowerStation()
{
	return NULL;
}

AMineFactory *ARedAlertPlayerController::CreateMineFactory()
{
	return NULL;
}

ASoldierCamp *ARedAlertPlayerController::CreateSoldierCamp()
{
	return NULL;
}


AVehicleFactory *ARedAlertPlayerController::CreateVehicleFactory()
{
	return NULL;
}

