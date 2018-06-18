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
	NumTeams = 2;

	GameStateClass = ARedAlertGameState::StaticClass();
	PlayerStateClass = ARedAlertPlayerState::StaticClass();


	TSubclassOf<AActor> IniCharas;
	static ConstructorHelpers::FObjectFinder<UBlueprint> CharacterClass(TEXT("Blueprint'/Game/Characters/Character.Character'"));
	if (CharacterClass.Object) {
		IniCharas = (UClass*)CharacterClass.Object->GeneratedClass;
		//for (int i = 0; i < 3; i++) 
		InitialActors.Add(IniCharas);
	}
	FVector Pos;
	Pos.X = 0;
	Pos.Y = 0;
	Pos.Z = 0;
	InitialActorPositions.Add(Pos);
	
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