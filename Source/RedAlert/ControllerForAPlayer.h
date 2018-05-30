// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include"Components/InputComponent.h"
#include"CameraPawn.h"
#include"Engine/Scene.h"
#include "ControllerForAPlayer.generated.h"

/**
 * 
 */
UCLASS()
class REDALERT_API AControllerForAPlayer : public APlayerController
{
	GENERATED_BODY()
protected:
	//virtual void BeginPlay() override;
public:
	AControllerForAPlayer();
	//virtual void Tick(float DeltaTime) override;
	//virtual void SetupInputComponent(class UInputComponent* PlayerInputComponent) override;

	ACameraPawn* GetCameraPawn();
private:
	void MoveScreenAlongX(float value);
	void MoveScreenAlongY(float value);
	void MoveToDestination(float X, float Y);
	ACameraPawn* MainPawn;
	float MousePositionX;
	float MousePositionY;
};
