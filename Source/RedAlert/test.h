// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include"Components/StaticMeshComponent.h"
#include "test.generated.h"

UCLASS()
class REDALERT_API Atest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Atest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Building)
		TAssetPtr<UStaticMesh> BaseMesh;

	UStaticMesh* GetLazyLoadedMesh();
	UFUNCTION(BlueprintCallable, Category = "Asset Loading")
		UStaticMesh * LoadMesh(const FString& Path);
	UStaticMeshComponent* Mesh;
};
