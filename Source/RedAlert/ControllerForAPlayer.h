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
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	ACameraPawn* GetCameraPawn();
private:
	void MovePawnToLocation(float AxisValue);
	void MoveScreenX(float AxisValue);
	void MoveScreenY(float AxisValue);

	ACameraPawn* MainPawn;
	float MousePositionX;
	float MousePositionY;
};
