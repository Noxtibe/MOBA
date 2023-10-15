#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "MOBA_PlayerController.generated.h"

UCLASS()
class MOBA_API AMOBA_PlayerController : public APlayerController
{
    GENERATED_BODY()

public:

    AMOBA_PlayerController();

protected:

    virtual void BeginPlay();
    virtual void SetupInputComponent() override;
    // D�claration de la fonction pour ajouter le mappage contextuel
    void AddMappingContext();

public:

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* MoveForwardAction;  // R�f�rence � l'action MoveForward

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* MoveRightAction;    // R�f�rence � l'action MoveRight

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* TurnAction;         // R�f�rence � l'action Turn

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* LookUpAction;       // R�f�rence � l'action LookUp

    // D�claration de votre action de mappage contextuel
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputMappingContext* MOBA_DefaultMappingContext;

    /** Action d'entr�e pour le d�bogage */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* DebugAction;


    void MoveForward(const FInputActionValue& Value);
    void MoveRight(const FInputActionValue& Value);
    void Turn(const FInputActionValue& Value);
    void LookUp(const FInputActionValue& Value);

    // D�claration de la fonction de d�bogage
    void DebugKeyPressed(const FInputActionValue& Value);
};
