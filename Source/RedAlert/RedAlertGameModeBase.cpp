// Fill out your copyright notice in the Description page of Project Settings.

#include "RedAlertGameModeBase.h"

ARedAlertGameModeBase::ARedAlertGameModeBase()
{
	DefaultPawnClass = ACameraPawn::StaticClass();
	PlayerControllerClass = ARedAlertPlayerController::StaticClass();

	
	static ConstructorHelpers::FObjectFinder<UBlueprint> MyHUD(TEXT("Blueprint'/Game/UI/RedAlertHUD.RedAlertHUD'"));
	if (MyHUD.Object) {
		HUDClass = (UClass*)MyHUD.Object->GeneratedClass;
	}
}


void ARedAlertGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	ChangeMenuWidget(StartingWidgetClass);
}

void ARedAlertGameModeBase::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}
	if (NewWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}