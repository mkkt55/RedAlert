// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"

#include "RTSPluginPCH.h"
#include "RTSGameMode.h"

#include "Builder.h"
#include "RedAlertPlayerController.h"
#include "RTSGameMode.h"
#include "Blueprint/UserWidget.h"
#include "RedAlertGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class REDALERT_API ARedAlertGameModeBase : public ARTSGameMode
{
	GENERATED_BODY()
	
	
public:
	ARedAlertGameModeBase();


public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RTS")
		TSubclassOf<APawn> Builder;

protected:
	/** Called when the game starts. */
	virtual void BeginPlay() override;

	
	
};
