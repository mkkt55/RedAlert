// Fill out your copyright notice in the Description page of Project Settings.

#include "RedAlertPlayerController.h"

#include "Net/UnrealNetwork.h"
#include "RTSAttackComponent.h"
#include "RTSAttackableComponent.h"
#include "RTSBuilderComponent.h"
#include "RTSBuildingCursor.h"
#include "RTSCameraBoundsVolume.h"
#include "RTSCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "RTSCharacterAIController.h"
#include "RTSConstructionSiteComponent.h"
#include "RTSFogOfWarActor.h"
#include "RTSGathererComponent.h"
#include "RTSNameComponent.h"
#include "RTSOwnerComponent.h"
#include "RTSPlayerAdvantageComponent.h"
#include "RTSPlayerResourcesComponent.h"
#include "RTSPlayerState.h"
#include "RTSProductionComponent.h"
#include "RTSProductionCostComponent.h"
#include "RTSResourceSourceComponent.h"
#include "RTSSelectableComponent.h"
#include "RTSTeamInfo.h"
#include "RTSUtilities.h"
#include "RTSVisionInfo.h"
#include "RTSResourceType.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/GameMode.h"
#include "RTSGameMode.h"
#include "Engine/World.h"




ARedAlertPlayerController::ARedAlertPlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
	CameraSpeed = 1000;
	CameraScrollThreshold = 20;
}
void ARedAlertPlayerController::BeginPlay()
{
	Super::BeginPlay();
	MainPawn = Cast<ACameraPawn>(GetPawn());
	if (MainPawn == NULL) {
		UE_LOG(LogTemp, Warning, TEXT("Error"));
	}
	ServerSpawnBuilderPawn();
}

void ARedAlertPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ARedAlertPlayerController, Builder);
}


void ARedAlertPlayerController::ServerSpawnBuilderPawn_Implementation()
{

}

bool ARedAlertPlayerController::ServerSpawnBuilderPawn_Validate()
{
	return true;
}

ACameraPawn* ARedAlertPlayerController::GetCameraPawn()
{
	return MainPawn;
}

void ARedAlertPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}


void ARedAlertPlayerController::MovePawnToLocation(AActor* Actor, const FVector& Location)
{
	UCharacterMovementComponent* MovementComponent = Actor->FindComponentByClass<UCharacterMovementComponent>();
	if (!MovementComponent)
	{
		Actor->SetActorLocation(Location);
	}
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

	InputComponent->BindAction(TEXT("Select"), IE_Pressed, this, &ARedAlertPlayerController::LeftMouseClick);
	InputComponent->BindAction(TEXT("Select"), IE_Released, this, &ARedAlertPlayerController::FinishLeftMouseClick);
	InputComponent->BindAction(TEXT("CancelSelect"), IE_Released, this, &ARedAlertPlayerController::RightMouseClick);

}


void ARedAlertPlayerController::RightMouseClick()
{
	MultipleSelectedUnits.Reset();
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
		if (Hit.GetActor())
		{
			SingleSelect(Hit.GetActor());
		}
		//Create SelectionFrame
	}
	else if (SelectionState == SelectBaseStation) {
		//
	}
	else if (SelectionState == SelectPowerStation) {
		//Show energy.
	}
	else if (SelectionState == SelectMineFactory) {
		//what to do?
	}
	else if (SelectionState == SelectSoldierCamp) {
		//select a location to create soldier there or create directly
	}
	else if (SelectionState == SelectVehicleFactory) {
		//same as former.
	}
	else if (SelectionState == UISelectPowerStation) {
		ServerConfirmBuilding(APowerStation::StaticClass());
	}
	else if (SelectionState == UISelectMineFactory) {
		ServerConfirmBuilding(AMineFactory::StaticClass());
	}
	else if (SelectionState == UISelectSoldierCamp) {
		ServerConfirmBuilding(ASoldierCamp::StaticClass());
	}
	else if (SelectionState == UISelectVehicleFactory) {
		ServerConfirmBuilding(AVehicleFactory::StaticClass());
	}
	
	else if (SelectionState == SingleSelectUnit) {
		FVector MousePosition;
		GetMousePosition(MousePosition.X, MousePosition.Y);

		MovePawnToLocation(SingleSelectedActor, MousePosition);

	}
	else if (SelectionState == MultipleSelectUnits) {
		FVector MousePosition;
		GetMousePosition(MousePosition.X, MousePosition.Y);
		for (int i = 0; i < MultipleSelectedUnits.Num(); i++)
		{
			MovePawnToLocation(MultipleSelectedUnits[i], MousePosition);
		}
	}
	else if (SelectionState == SoldingSth) {

	}

	return;
}
void ARedAlertPlayerController::FinishLeftMouseClick()
{
	if (SelectionState == SingleSelectUnit)
	{
		SingleSelectedActor = NULL;
	}
	if (SelectionState == MultipleSelectUnits)
	{
		MultipleSelectedUnits.Reset();
	}
}

void ARedAlertPlayerController::CreatePowerStation()
{
	AGameMode* GameModeInstance = Cast<AGameMode>(UGameplayStatics::GetGameMode(this));
	FTransform SpawnTransform;
	FActorSpawnParameters SpawnParams;
	APowerStation* Actor = GetWorld()->SpawnActor<APowerStation>(APowerStation::StaticClass(), SpawnTransform, SpawnParams);

	if (!Actor)
	BuilderPawn = Cast<ARedAlertBuilder>(Actor);
}


void ARedAlertPlayerController::ServerConfirmBuilding_Implementation(UClass* BuildingClass)
{
	BuildingAwaiting = BuildingClass;
	FVector MousePosition;
	GetMousePosition(MousePosition.X, MousePosition.Y);
	FHitResult Hit(ForceInit);
	FTransform SpawnTransform;
	SpawnTransform.SetLocation(MousePosition);
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	if (!Hit.GetActor()) {
		GetWorld()->SpawnActor<AActor>(BuildingClass, SpawnTransform, SpawnParams);
	}
}

bool ARedAlertPlayerController::ServerConfirmBuilding_Validate(UClass* BuildingClass)
{
	return true;
}
bool ARedAlertPlayerController::SingleSelect(AActor* Actor)
{
	if (!Actor)
	{
		return false;
	}
	SingleSelectedActor = Actor;
	return true;
}