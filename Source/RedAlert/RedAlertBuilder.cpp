// Fill out your copyright notice in the Description page of Project Settings.

#include "RedAlertBuilder.h"


// Sets default values
ARedAlertBuilder::ARedAlertBuilder()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Builder = CreateDefaultSubobject<URTSBuilderComponent>(TEXT("BuilderComponent"));
	
	Builder->ConstructibleBuildingClasses = TArray<TSubclassOf<AActor> >();
	Builder->ConstructibleBuildingClasses.Reserve(4);
	Builder->ConstructibleBuildingClasses.Add(APowerStation::StaticClass());
	Builder->ConstructibleBuildingClasses.Add(AMineFactory::StaticClass());
	Builder->ConstructibleBuildingClasses.Add(ASoldierCamp::StaticClass());
	Builder->ConstructibleBuildingClasses.Add(AVehicleFactory::StaticClass());
	
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));
	Movement->MaxSpeed = 300000;

	OwnerComponent = CreateDefaultSubobject<URTSOwnerComponent>(TEXT("Owner"));
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = Root;
}

// Called when the game starts or when spawned
void ARedAlertBuilder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARedAlertBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
/*
// Called to bind functionality to input
void ARedAlertBuilder::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
*/

