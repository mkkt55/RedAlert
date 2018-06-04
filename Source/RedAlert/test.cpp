// Fill out your copyright notice in the Description page of Project Settings.

#include "test.h"


// Sets default values
Atest::Atest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	UStaticMesh* Mh = LoadMesh("/Game/StarterContent/Props/SM_Rock.SM_Rock");
	Mesh->SetStaticMesh(Mh);
}
UStaticMesh* Atest::LoadMesh(const FString& Path)
{
	FStringAssetReference assetRef(Path);
	return Cast<UStaticMesh>(assetRef.TryLoad());
}

// Called when the game starts or when spawned
void Atest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Atest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



UStaticMesh* Atest::GetLazyLoadedMesh()
{
	if (BaseMesh.IsPending())
	{
		const FStringAssetReference& AssetRef = BaseMesh.ToStringReference();
		//BaseMesh = Cast< UStaticMesh>(Streamable.SynchronousLoad(AssetRef));
	}
	return BaseMesh.Get();
}