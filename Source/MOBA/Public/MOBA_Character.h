#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Ability_AutoAttack.h"
#include "Ability_FeatherOfRedemption.h"
#include "Ability_BreezeOfTerror.h"
#include "Ability_ThreeEyedCrow.h"
#include "Ability_VengefulRaven.h"
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

    // ABILITIES

    // AUTO ATTACK
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Ability, meta = (AllowPrivateAccess = "true"))
    UAbility_AutoAttack* AbilityAutoAttack;
    // CAPACITY 1
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Ability, meta = (AllowPrivateAccess = "true"))
    UAbility_FeatherOfRedemption* AbilityFeatherOfRedemption;
    // CAPACITY 2
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Ability, meta = (AllowPrivateAccess = "true"))
    UAbility_BreezeOfTerror* AbilityBreezeOfTerror;
    // CAPACITY 3
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Ability, meta = (AllowPrivateAccess = "true"))
    UAbility_ThreeEyedCrow* AbilityThreeEyedCrow;
    // CAPACITY 4 (ULTIMATE)
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Ability, meta = (AllowPrivateAccess = "true"))
    UAbility_VengefulRaven* AbilityVengefulRaven;

    // Tableau n�cessaire pour un plus grand nombre de capacit�s.
    // Dans notre cas, ce n'est pas n�cessaire, le nombre de 
    // capacit�s ne va pas augmenter au fur et � mesure du jeu.
    // 
    //UPROPERTY(EditAnywhere, Category = "Abilities")
    //TArray<UAbility*> Abilities;

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

    UPROPERTY(EditAnywhere)
    TSubclassOf<class UMOBA_DefaultWidget> PlayerHUDClass;

    UPROPERTY()
    class UMOBA_DefaultWidget* PlayerHUD;

    // Map pour stocker les gestionnaires de temps de recharge des comp�tences
    UPROPERTY()
    TMap<UAbility*, FTimerHandle> CooldownTimers; 

    // Fonction pour v�rifier si une comp�tence est pr�te � �tre activ�e
    bool IsAbilityReady(UAbility* Ability);

    // Fonction pour activer une comp�tence
    void ActivateAbility(UAbility* Ability);

    // Fonction pour g�rer le temps de recharge des comp�tences
    void HandleCooldowns();

    // Fonction pour commencer le temps de recharge d'une comp�tence
    void StartAbilityCooldown(UAbility* Ability);
};
