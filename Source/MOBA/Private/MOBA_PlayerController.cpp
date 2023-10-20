#include "MOBA_PlayerController.h"
#include "MOBA_Character.h"

void AMOBA_PlayerController::BeginPlay()
{
    Super::BeginPlay();

    character = CastChecked<AMOBA_Character>(GetPawn());

    if (UEnhancedInputLocalPlayerSubsystem* input_subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        input_subsystem->AddMappingContext(DefaultMappingContext, 0);
    }
    if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(character->InputComponent))
    {
        // Moving
        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, character, &AMOBA_Character::Move);

        // Looking
        EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, character, &AMOBA_Character::Look);

        // Jumping
        EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, character, &ACharacter::Jump);
        EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, character, &ACharacter::StopJumping);

        // Abilities
        EnhancedInputComponent->BindAction(AAAction, ETriggerEvent::Triggered, character, &AMOBA_Character::AutoAttack);
        EnhancedInputComponent->BindAction(Capacity1Action, ETriggerEvent::Completed, character, &AMOBA_Character::Capacity1);
        EnhancedInputComponent->BindAction(Capacity2Action, ETriggerEvent::Triggered, character, &AMOBA_Character::Capacity2);
        EnhancedInputComponent->BindAction(Capacity3Action, ETriggerEvent::Completed, character, &AMOBA_Character::Capacity3);
        EnhancedInputComponent->BindAction(Capacity4Action, ETriggerEvent::Triggered, character, &AMOBA_Character::Capacity4);
    }
}