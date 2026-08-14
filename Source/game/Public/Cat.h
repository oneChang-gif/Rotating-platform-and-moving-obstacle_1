#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cat.generated.h"

UCLASS()
class GAME_API ACat : public AActor
{
	GENERATED_BODY()
	
public:	
	ACat();

protected:
	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
