// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include"GameFramework/SpringArmComponent.h"
#include"Camera/CameraComponent.h"
#include"Components/InputComponent.h"
#include"Components/InputComponent.h"
#include"Engine/Scene.h"

#include "CameraPawn.generated.h"

UCLASS()
class REDALERT_API ACameraPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACameraPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Move_XAxis(float AxisValue);
	void Move_YAxis(float AxisValue);
	FVector CurrentVelocity;

private:
	UPROPERTY(EditAnyWhere)
		class UCameraComponent* Camera;
	UPROPERTY(EditAnyWhere)
		class USpringArmComponent* Arm;

	
	
};
