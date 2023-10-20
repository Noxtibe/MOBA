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

    // FPS CAMERA
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    UCameraComponent* FirstPersonCameraComponent;

public:

    AMOBA_Character();

    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

    virtual void Tick(float DeltaTime) override;

    // DEFAULT MOVEMENTS

    void Move(const FInputActionValue& Value);
    void Look(const FInputActionValue& Value);

    void AutoAttack();
    void Capacity1();
    void Capacity2();
    void Capacity3();
    void Capacity4();

private:

    // HUD

    UPROPERTY(EditAnywhere)
    TSubclassOf<class UMOBA_DefaultWidget> PlayerHUDClass;

    UPROPERTY()
    class UMOBA_DefaultWidget* PlayerHUD;
};
