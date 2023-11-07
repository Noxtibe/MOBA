#include "MOBA_Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "MOBA_PlayerController.h"

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

	// ABILITIES
	AbilityAutoAttack = CreateDefaultSubobject<UAbility_AutoAttack>(TEXT("Auto Attack"));
	AbilityFeatherOfRedemption = CreateDefaultSubobject <UAbility_FeatherOfRedemption>(TEXT("Feather Of Redemption"));
	AbilityBreezeOfTerror = CreateDefaultSubobject <UAbility_BreezeOfTerror>(TEXT("Breeze Of Terror"));
	AbilityThreeEyedCrow = CreateDefaultSubobject <UAbility_ThreeEyedCrow>(TEXT("Three-Eyed Crow"));
	AbilityVengefulRaven = CreateDefaultSubobject <UAbility_VengefulRaven>(TEXT("Vengeful Raven"));


	// Tick for pawn
	PrimaryActorTick.bCanEverTick = true;
}

void AMOBA_Character::BeginPlay()
{
    Super::BeginPlay();

	if (IsLocallyControlled())
	{
		AMOBA_PlayerController* PC = GetController <AMOBA_PlayerController>();
		check(PC);
	}
}

void AMOBA_Character::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
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
	AbilityAutoAttack->Activate();
}

void AMOBA_Character::Capacity1()
{
	AbilityFeatherOfRedemption->Activate();
}

void AMOBA_Character::Capacity2()
{
	AbilityBreezeOfTerror->Activate();
}

void AMOBA_Character::Capacity3()
{
	AbilityThreeEyedCrow->Activate();
}

void AMOBA_Character::Capacity4()
{
	AbilityVengefulRaven->Activate();
}
