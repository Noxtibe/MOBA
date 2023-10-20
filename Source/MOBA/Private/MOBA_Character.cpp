#include "MOBA_Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "MOBA_PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "MOBA_DefaultWidget.h"

AMOBA_Character::AMOBA_Character()
{
	// CAMERA COMPONENT
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());

	// MESH COMPONENT
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;

	//HUD
	PlayerHUDClass = nullptr;
	PlayerHUD = nullptr;

	// Tick for pawn
	PrimaryActorTick.bCanEverTick = true;
}

void AMOBA_Character::BeginPlay()
{
    Super::BeginPlay();

	if (IsLocallyControlled() && PlayerHUDClass)
	{
		AMOBA_PlayerController* PC = GetController <AMOBA_PlayerController>();
		check(PC);
		PlayerHUD = CreateWidget<UMOBA_DefaultWidget>(PC, PlayerHUDClass);
		check(PlayerHUD);
		PlayerHUD->AddToPlayerScreen();
	}
}

void AMOBA_Character::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (PlayerHUD)
	{
		PlayerHUD->RemoveFromParent();
		// We can't destroy the widget here
		PlayerHUD = nullptr;
	}
	Super::EndPlay(EndPlayReason);
}

void AMOBA_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMOBA_Character::Move(const FInputActionValue& Value)
{
	// Input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// Add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void AMOBA_Character::Look(const FInputActionValue& Value)
{
	// Input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// Add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AMOBA_Character::AutoAttack()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Auto Attack"));
}

void AMOBA_Character::Capacity1()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("Capacity 1"));
}

void AMOBA_Character::Capacity2()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Capacity 2"));
}

void AMOBA_Character::Capacity3()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Capacity 3"));
}

void AMOBA_Character::Capacity4()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Magenta, TEXT("Capacity 4"));
}
