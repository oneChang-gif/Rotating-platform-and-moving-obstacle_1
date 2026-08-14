#include "Cat.h"

ACat::ACat()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesg"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	 
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Fab/Low_Poly_Cat/low_poly_cat/StaticMeshes/low_poly_cat.low_poly_cat"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 800.0f;
}

void ACat::BeginPlay()
{
	Super::BeginPlay();
	
	SetActorLocation(FVector(300.0f, 200.0f, 100.0f));
	SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
	SetActorScale3D(FVector(0.5f));
}

void ACat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}

}

