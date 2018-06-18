// Fill out your copyright notice in the Description page of Project Settings.

#include "ControllerForAPlayer.h"
#include"Components/InputComponent.h"





AControllerForAPlayer::AControllerForAPlayer()
{
	//PrimaryActorTick.bCanEverTick = true;
	

	//InputComponent = CreateDefaultSubobject<UInputComponent>(TEXT("InputComponent"));
	//unreal editor crash because of the two sentences above.
	
	//GetMousePosition(MousePositionX, MousePositionY);
}
void AControllerForAPlayer::BeginPlay()
{
	Super::BeginPlay();
	MainPawn = Cast<ACameraPawn>(GetPawn());
	if (MainPawn == NULL) {
		UE_LOG(LogTemp, Warning, TEXT("Error"));
	}

}

ACameraPawn* AControllerForAPlayer::GetCameraPawn()
{
	return MainPawn;
}

void AControllerForAPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AControllerForAPlayer::MovePawnToLocation(float value)
{

}

void AControllerForAPlayer::MoveScreenX(float AxisValue)
{
	if (MainPawn != NULL) {
		MainPawn->CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
	}
	else {
		MainPawn = Cast<ACameraPawn>(GetPawn());
		UE_LOG(LogTemp, Warning, TEXT("Error"));
	}
}

void AControllerForAPlayer::MoveScreenY(float AxisValue)
{
	if (MainPawn != NULL) {
		MainPawn->CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
	}
	else {
		MainPawn = Cast<ACameraPawn>(GetPawn());
		UE_LOG(LogTemp, Warning, TEXT("Error"));
	}
}

void AControllerForAPlayer::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	APlayerController::bShowMouseCursor = true;
	APlayerController::bEnableClickEvents = true;
	APlayerController::bEnableMouseOverEvents = true;


	/*
	//InputComponent->BindAxis("MoveX", this, &AControllerForAPlayer::MoveScreenX);
	//InputComponent->BindAxis("MoveY", this, &AControllerForAPlayer::MoveScreenY);

	//InputComponent->BindAction("LeftClick", IE_Pressed, this, &AControllerForAPlayer::LeftMouseClick);
	//InputComponent->BindAction("LeftClick", IE_Released, this, &AControllerForAPlayer::LeftMouseClick);


	
	InputComponent->BindAxis(TEXT("MoveCameraLeftRight"), this, &ARTSPlayerController::MoveCameraLeftRight);
	InputComponent->BindAxis(TEXT("MoveCameraUpDown"), this, &ARTSPlayerController::MoveCameraUpDown);
	*/
}




void AControllerForAPlayer::LeftMouseClick()
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
	else if (SelectionState==SoldingSth) {
		
	}

	return;
}


APowerStation *AControllerForAPlayer::CreatePowerStation()
{
	return NULL;
}

AMineFactory *AControllerForAPlayer::CreateMineFactory()
{
	return NULL;
}

ASoldierCamp *AControllerForAPlayer::CreateSoldierCamp()
{
	return NULL;
}


AVehicleFactory *AControllerForAPlayer::CreateVehicleFactory()
{
	return NULL;
}
















