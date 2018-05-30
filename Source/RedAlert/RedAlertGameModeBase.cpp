// Fill out your copyright notice in the Description page of Project Settings.

#include "RedAlertGameModeBase.h"
#include"CameraPawn.h"
#include"ControllerForAPlayer.h"

ARedAlertGameModeBase::ARedAlertGameModeBase()
{
	DefaultPawnClass = ACameraPawn::StaticClass();
	PlayerControllerClass = AControllerForAPlayer::StaticClass();
}




