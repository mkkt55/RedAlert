// Fill out your copyright notice in the Description page of Project Settings.

#include "ControllerForAPlayer.h"






AControllerForAPlayer::AControllerForAPlayer()
{
	//uint32 bMoveToMouseCursor = 1;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
	bShowMouseCursor = true;
	MainPawn = Cast<ACameraPawn>(GetPawn());
	//InputComponent->BindAxis("MoveX", MainPawn, &ACameraPawn::Move_XAxis);
	//InputComponent->BindAxis("MoveY", MainPawn, &ACameraPawn::Move_YAxis);
	
	GetMousePosition(MousePositionX, MousePositionY);
}

ACameraPawn* AControllerForAPlayer::GetCameraPawn()
{
	return MainPawn;
}