#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "MOBA_Character.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class USceneComponent;
class UCameraComponent;


UCLASS()
class MOBA_API AMOBA_Character : public ACharacter
{
    GENERATED_BODY()

    /** Pawn mesh: 1st person view (arms; seen only by self) */
    UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
    USkeletalMeshComponent* Mesh1P;

    /** First person camera */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    UCameraComponent* FirstPersonCameraComponent;

public:

    AMOBA_Character();

    virtual void Tick(float DeltaTime) override;

    // DEFAULT MOVEMENTS
    void Move(const FInputActionValue& Value);
    void Look(const FInputActionValue& Value);

protected:

    virtual void BeginPlay() override;
};
