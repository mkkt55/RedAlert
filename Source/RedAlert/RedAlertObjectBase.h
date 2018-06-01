// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include"Components/StaticMeshComponent.h"
#include"ControllerForAPlayer.h"
#include "RedAlertObjectBase.generated.h"

UCLASS()
class REDALERT_API ARedAlertObjectBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARedAlertObjectBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//other actors who are attacking this actor will directly add this number via pointer
	float ReceivedTotalDamage;
	float CurrentHealth;

	AControllerForAPlayer *Controller;

	/*
	//add component to be showed in the level.
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent *Mesh;
	*/
private:
	bool GetDestroyed();

};