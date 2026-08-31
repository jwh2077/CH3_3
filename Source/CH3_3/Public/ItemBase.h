// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"

class USphereComponent;

UCLASS()
class CH3_3_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	

	AItemBase();

	// 씬 컴포넌트
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	USceneComponent* SceneComponent;
	//스태틱 메시 컴포넌트
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	UStaticMeshComponent* StaticMeshComponent;
	//구	형 콜리전 컴포넌트
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	USphereComponent* SphereCollisionComponent;

	//아이템 오버랩 이벤트 함수
	virtual void OnItemOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
	//아이템 오버랩 종료 이벤트 함수
	virtual void OnItemEndOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
