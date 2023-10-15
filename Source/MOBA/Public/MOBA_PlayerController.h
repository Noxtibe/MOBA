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
    // Déclaration de la fonction pour ajouter le mappage contextuel
    void AddMappingContext();

public:

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* MoveForwardAction;  // Référence à l'action MoveForward

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* MoveRightAction;    // Référence à l'action MoveRight

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* TurnAction;         // Référence à l'action Turn

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* LookUpAction;       // Référence à l'action LookUp

    // Déclaration de votre action de mappage contextuel
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputMappingContext* MOBA_DefaultMappingContext;

    /** Action d'entrée pour le débogage */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* DebugAction;


    void MoveForward(const FInputActionValue& Value);
    void MoveRight(const FInputActionValue& Value);
    void Turn(const FInputActionValue& Value);
    void LookUp(const FInputActionValue& Value);

    // Déclaration de la fonction de débogage
    void DebugKeyPressed(const FInputActionValue& Value);
};
