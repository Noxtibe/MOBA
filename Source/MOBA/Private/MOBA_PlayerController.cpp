#include "MOBA_PlayerController.h"
#include "MOBA_Character.h"
#include "EnhancedInputComponent.h"

AMOBA_PlayerController::AMOBA_PlayerController()
{
    // Initialisation de votre DefaultMappingContext
    //MOBA_DefaultMappingContext = CreateDefaultSubobject<UInputMappingContext>(TEXT("MOBA_DefaultMappingContext"));
    DebugAction = NewObject<UInputAction>();
}

void AMOBA_PlayerController::BeginPlay()
{
    // Call the base class  
    Super::BeginPlay();
}

void AMOBA_PlayerController::SetupInputComponent()
{
    //Super::SetupInputComponent();

    UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
    if (EnhancedInputComponent)
    {
        AddMappingContext();

        // Lier les actions d'entr�e aux fonctions correspondantes en utilisant les r�f�rences
        EnhancedInputComponent->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &AMOBA_PlayerController::MoveForward);
        EnhancedInputComponent->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &AMOBA_PlayerController::MoveRight);
        EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Triggered, this, &AMOBA_PlayerController::Turn);
        EnhancedInputComponent->BindAction(LookUpAction, ETriggerEvent::Triggered, this, &AMOBA_PlayerController::LookUp);

        // Lier l'action "DebugAction" � la fonction de d�bogage lorsque l'action est d�clench�e
        EnhancedInputComponent->BindAction(DebugAction, ETriggerEvent::Triggered, this, &AMOBA_PlayerController::DebugKeyPressed);
    }
}

void AMOBA_PlayerController::AddMappingContext()
{
    if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        Subsystem->AddMappingContext(MOBA_DefaultMappingContext, 0);
    }
}

void AMOBA_PlayerController::MoveForward(const FInputActionValue& Value)
{
    // Impl�mentez ici la logique de d�placement du personnage vers l'avant
    APawn* ControlledPawn = GetPawn();
    if (ControlledPawn)
    {
        ControlledPawn->AddMovementInput(FVector::ForwardVector, Value.Get<float>());
    }
}

void AMOBA_PlayerController::MoveRight(const FInputActionValue& Value)
{
    // Impl�mentez ici la logique de d�placement lat�ral du personnage
    APawn* ControlledPawn = GetPawn();
    if (ControlledPawn)
    {
        ControlledPawn->AddMovementInput(FVector::RightVector, Value.Get<float>());
    }
}

void AMOBA_PlayerController::Turn(const FInputActionValue& Value)
{
    // Impl�mentez ici la logique de rotation du personnage
    APawn* ControlledPawn = GetPawn();
    if (ControlledPawn)
    {
        ControlledPawn->AddControllerYawInput(Value.Get<float>());
    }
}

void AMOBA_PlayerController::LookUp(const FInputActionValue& Value)
{
    // Impl�mentez ici la logique de regard du personnage
    APawn* ControlledPawn = GetPawn();
    if (ControlledPawn)
    {
        ControlledPawn->AddControllerPitchInput(Value.Get<float>());
    }
}

void AMOBA_PlayerController::DebugKeyPressed(const FInputActionValue& Value)
{
    // Cette fonction sera appel�e lorsque l'action "DebugAction" sera d�clench�e
    // Vous pouvez ajouter ici le code de d�bogage que vous souhaitez
    // Par exemple, affichez un message � l'�cran

    if (Value.Get<bool>())
    {
        // Affiche un message de d�bogage � l'�cran lorsque la touche est enfonc�e
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Touche de d�bogage enfonc�e !"));
    }
}
