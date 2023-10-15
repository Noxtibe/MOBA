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

        // Lier les actions d'entrée aux fonctions correspondantes en utilisant les références
        EnhancedInputComponent->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &AMOBA_PlayerController::MoveForward);
        EnhancedInputComponent->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &AMOBA_PlayerController::MoveRight);
        EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Triggered, this, &AMOBA_PlayerController::Turn);
        EnhancedInputComponent->BindAction(LookUpAction, ETriggerEvent::Triggered, this, &AMOBA_PlayerController::LookUp);

        // Lier l'action "DebugAction" à la fonction de débogage lorsque l'action est déclenchée
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
    // Implémentez ici la logique de déplacement du personnage vers l'avant
    APawn* ControlledPawn = GetPawn();
    if (ControlledPawn)
    {
        ControlledPawn->AddMovementInput(FVector::ForwardVector, Value.Get<float>());
    }
}

void AMOBA_PlayerController::MoveRight(const FInputActionValue& Value)
{
    // Implémentez ici la logique de déplacement latéral du personnage
    APawn* ControlledPawn = GetPawn();
    if (ControlledPawn)
    {
        ControlledPawn->AddMovementInput(FVector::RightVector, Value.Get<float>());
    }
}

void AMOBA_PlayerController::Turn(const FInputActionValue& Value)
{
    // Implémentez ici la logique de rotation du personnage
    APawn* ControlledPawn = GetPawn();
    if (ControlledPawn)
    {
        ControlledPawn->AddControllerYawInput(Value.Get<float>());
    }
}

void AMOBA_PlayerController::LookUp(const FInputActionValue& Value)
{
    // Implémentez ici la logique de regard du personnage
    APawn* ControlledPawn = GetPawn();
    if (ControlledPawn)
    {
        ControlledPawn->AddControllerPitchInput(Value.Get<float>());
    }
}

void AMOBA_PlayerController::DebugKeyPressed(const FInputActionValue& Value)
{
    // Cette fonction sera appelée lorsque l'action "DebugAction" sera déclenchée
    // Vous pouvez ajouter ici le code de débogage que vous souhaitez
    // Par exemple, affichez un message à l'écran

    if (Value.Get<bool>())
    {
        // Affiche un message de débogage à l'écran lorsque la touche est enfoncée
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Touche de débogage enfoncée !"));
    }
}
