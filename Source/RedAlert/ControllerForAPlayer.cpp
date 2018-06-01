// Fill out your copyright notice in the Description page of Project Settings.

#include "ControllerForAPlayer.h"
#include"Components/InputComponent.h"





AControllerForAPlayer::AControllerForAPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
	bShowMouseCursor = true;

	InputComponent = CreateDefaultSubobject<UInputComponent>(TEXT("InputComponent"));
	//unreal editor crash because of the two sentences above.
	
	GetMousePosition(MousePositionX, MousePositionY);
}
void AControllerForAPlayer::BeginPlay()
{
	Super::BeginPlay();
	MainPawn = Cast<ACameraPawn>(GetPawn());
	if (MainPawn == NULL) {
		UE_LOG(LogTemp, Warning, TEXT("Error"));
	}
}

ACameraPawn* AControllerForAPlayer::GetCameraPawn()
{
	return MainPawn;
}

void AControllerForAPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AControllerForAPlayer::MovePawnToLocation(float value)
{

}

void AControllerForAPlayer::MoveScreenX(float AxisValue)
{
	if (MainPawn != NULL) {
		MainPawn->CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
	}
	else {
		MainPawn = Cast<ACameraPawn>(GetPawn());
		UE_LOG(LogTemp, Warning, TEXT("Error"));
	}
}

void AControllerForAPlayer::MoveScreenY(float AxisValue)
{
	if (MainPawn != NULL) {
		MainPawn->CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
	}
	else {
		MainPawn = Cast<ACameraPawn>(GetPawn());
		UE_LOG(LogTemp, Warning, TEXT("Error"));
	}
}

void AControllerForAPlayer::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("MoveX", this, &AControllerForAPlayer::MoveScreenX);
	InputComponent->BindAxis("MoveY", this, &AControllerForAPlayer::MoveScreenY);

}