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

    // Tableau nécessaire pour un plus grand nombre de capacités.
    // Dans notre cas, ce n'est pas nécessaire, le nombre de 
    // capacités ne va pas augmenter au fur et à mesure du jeu.
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

    // Map pour stocker les gestionnaires de temps de recharge des compétences
    UPROPERTY()
    TMap<UAbility*, FTimerHandle> CooldownTimers; 

    // Fonction pour vérifier si une compétence est prête à être activée
    bool IsAbilityReady(UAbility* Ability);

    // Fonction pour activer une compétence
    void ActivateAbility(UAbility* Ability);

    // Fonction pour gérer le temps de recharge des compétences
    void HandleCooldowns();

    // Fonction pour commencer le temps de recharge d'une compétence
    void StartAbilityCooldown(UAbility* Ability);
};
