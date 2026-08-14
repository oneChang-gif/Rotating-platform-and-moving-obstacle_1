#include "Obstacle.h"

AObstacle::AObstacle()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesg"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_CornerFrame.SM_CornerFrame"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> MatetialAsset(TEXT("/Game/Resources/Materials/M_Metal_Gold.M_Metal_Gold"));
	if (MatetialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MatetialAsset.Object);
	}

	PrimaryActorTick.bCanEverTick = true;
	LocationSpeed = 100.0f;

}

void AObstacle::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(600.0f, - 600.0f, 100.0f));
	SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
	SetActorScale3D(FVector(15.0f));
	
}

void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(LocationSpeed))
	{
		AddActorWorldOffset(FVector(0.0f, LocationSpeed * DeltaTime, 0.0f));
	}
}

