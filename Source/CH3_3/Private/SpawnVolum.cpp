// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnVolum.h"
#include "Components/BoxComponent.h"


// Sets default values
ASpawnVolum::ASpawnVolum()
	:ItemDataTable(nullptr)
{
	//씬 컴퍼넌트 생성
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	//루트 컴퍼넌트로 설정
	SetRootComponent(SceneComp);
	//박스 컴퍼넌트 생성
	SpawningBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawningBox"));
	//박스 컴퍼넌트 루트에 부착
	SpawningBox->SetupAttachment(RootComponent);
}

AActor* ASpawnVolum::SpawnRandomItem()
{
	//렌덤 아이템 저장
	if (FItemSpawnRow* SelectedRow = GetRandomItem())
	{
		//렌덤 아이템의 class를 넘기기
		if (UClass* ACtyalClass = SelectedRow->ItemClass.Get())
		{
			//아이템 스폰 함수로 class 전달
			SpawnItem(ACtyalClass);
		}
	}
	return nullptr;
}

FItemSpawnRow* ASpawnVolum::GetRandomItem() const
{
	//데이터 테이블 유효성 검사
	if (!ItemDataTable)return nullptr;
	
	//아이템 구조체로 이루어진 배열 선언
	TArray<FItemSpawnRow*> AllRows;
	//함수내의 스태틱 변수 선언 한번 선언후 지워지거나 변하지 않음
	static const FString ContextString(TEXT("ItemSpawnContext"));
	//데이터 테이블의 정보를 AllRows 배열안에 넣고 실패시 로그에 ContextString를 함깨 출력
	ItemDataTable->GetAllRows(ContextString, AllRows);
	//배열이 비었는지 확인
	if (AllRows.IsEmpty())return nullptr;
	//전체 확률 값
	float TotalChance = 0.0f;
	//전체 확률 값 더하기
	for (const FItemSpawnRow* Row : AllRows)
	{
		if (Row)
		{
			TotalChance += Row->Spawnchance;
		}
	}

	//0 ~ 전체 확률 사이의 랜덤 확률(숫자) 반환
	const float RandValue = FMath::FRandRange(0.0f, TotalChance);
	//확률 확인용 숫자
	float AccumlateChace = 0.0f;
	//확율을 더하기
	for (FItemSpawnRow* Row : AllRows)
	{
		AccumlateChace += Row->Spawnchance;
		//확률을 확인용 숫자가 반환된 확률을 넘어설경우 배열안의 값 하나를 리턴
		if (RandValue <= AccumlateChace)
		{
			return Row;
		}
	}
	return nullptr;
}

FVector ASpawnVolum::GetRandomPointInVolume() const
{
	//상자의 반지름
	FVector BoxExtent = SpawningBox->GetScaledBoxExtent();
	//상자의 좌표
	FVector BoxOrigin = SpawningBox->GetComponentLocation();

	return BoxOrigin + FVector(
		FMath::FRandRange(-BoxExtent.X, BoxExtent.X),
		FMath::FRandRange(-BoxExtent.Y, BoxExtent.Y),
		FMath::FRandRange(-BoxExtent.Z, BoxExtent.Z)
	);
}

AActor* ASpawnVolum::SpawnItem(TSubclassOf<AActor> ItemClass)
{
	//class의 유효성 검사
	if (!ItemClass)return nullptr;
	//받은 class를 랜덤 좌표에 회전 값 0으로 생성
	AActor* SpawndActor = GetWorld()->SpawnActor<AActor>(
		ItemClass,
		GetRandomPointInVolume(),
		FRotator::ZeroRotator
	);
	return SpawndActor;
}