// Fill out your copyright notice in the Description page of Project Settings.

#include "RedAlertGameModeBase.h"
#include"CameraPawn.h"
#include"ControllerForAPlayer.h"

ARedAlertGameModeBase::ARedAlertGameModeBase()
{
	BuildingCursor = GetWorld()->SpawnActor<ARTSBuildingCursor>(BuildingCursorClass, SpawnParams);
	Builder=GetWorld()->SpawnActor()
}


void ARedAlertGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
}
