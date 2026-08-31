// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemInterface.h"
#include "ItemBase.generated.h"

class USphereComponent;


UCLASS()
class CH3_3_API AItemBase : public AActor, public IItemInterface
{
	GENERATED_BODY()
	
public:	

	AItemBase();

protected:

	//씬 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
	USceneComponent* SceneComponent;
	//스태틱 메시 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
	UStaticMeshComponent* StaticMeshComponent;
	//구	형 콜리전 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
	USphereComponent* CollisionComponent;
	//아이템 획득 이펙트
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Effects")
	UParticleSystem* PickupEffect;
	//아이템 획득 사운드
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Effects")
	USoundBase* PickupSound;


	//아이템 오버랩 이벤트 함수
	virtual void OnItemOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult) override;

	//아이템 오버랩 종료 이벤트 함수
	virtual void OnItemEndOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex) override;

	//아이템 작동 함수
	virtual void ActivateItem(AActor* OtherActor);

	//아이템 삭제 함수
	virtual void DestroyItem();


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//아이템 타입 Get 함수
	virtual FName GetItemType() const override;


	//아이템 타입
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName ItemType;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
