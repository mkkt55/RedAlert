// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "RedAlertPlayerController.h"
#include "RTSGameMode.h"
#include "Blueprint/UserWidget.h"
#include "CameraPawn.h"
#include "ControllerForAPlayer.h"
#include "ConstructorHelpers.h"
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
	/** Remove the current menu widget and create a new one from the specified class, if provided. */
	UFUNCTION(BlueprintCallable, Category = "UMG Game")
		void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

protected:
	/** Called when the game starts. */
	virtual void BeginPlay() override;

	/** The widget class we will use as our menu when the game starts. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG Game")
		TSubclassOf<UUserWidget> StartingWidgetClass;

	/** The widget instance that we are using as our menu. */
	UPROPERTY()
		UUserWidget* CurrentWidget;
	
};
