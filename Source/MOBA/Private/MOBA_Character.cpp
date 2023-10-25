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

	// ABILITIES
	AbilityAutoAttack = CreateDefaultSubobject<UAbility_AutoAttack>(TEXT("Auto Attack"));
	AbilityFeatherOfRedemption = CreateDefaultSubobject <UAbility_FeatherOfRedemption>(TEXT("Feather Of Redemption"));
	AbilityBreezeOfTerror = CreateDefaultSubobject <UAbility_BreezeOfTerror>(TEXT("Breeze Of Terror"));
	AbilityThreeEyedCrow = CreateDefaultSubobject <UAbility_ThreeEyedCrow>(TEXT("Three-Eyed Crow"));
	AbilityVengefulRaven = CreateDefaultSubobject <UAbility_VengefulRaven>(TEXT("Vengeful Raven"));

	CooldownTimers.Add(AbilityAutoAttack, FTimerHandle());

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

bool AMOBA_Character::IsAbilityReady(UAbility* Ability)
{
	if (Ability && CooldownTimers.Contains(Ability))
	{
		return !CooldownTimers[Ability].IsValid();
	}

	return false;
}

void AMOBA_Character::ActivateAbility(UAbility* Ability)
{
	if (Ability && IsAbilityReady(Ability))
	{
		Ability->Activate();
		StartAbilityCooldown(Ability);
	}
}

void AMOBA_Character::HandleCooldowns()
{
	for (auto& Entry : CooldownTimers)
	{
		if (Entry.Value.IsValid() && GetWorldTimerManager().GetTimerRemaining(Entry.Value) <= 0.0f)
		{
			Entry.Value.Invalidate();
		}
	}
}

void AMOBA_Character::StartAbilityCooldown(UAbility* Ability)
{
	if (Ability)
	{
		FTimerHandle& TimerHandle = CooldownTimers[Ability];
		if (!TimerHandle.IsValid())
		{
			// Obtenez le temps de recharge spécifique à la compétence ici
			float CooldownTime = 0.0f;

			if (Ability == AbilityAutoAttack)
			{
				CooldownTime = AbilityAutoAttack->GetCooldownTime();
			}
			/*else if (Ability == AbilityFeatherOfRedemption)
			{
				CooldownTime = AbilityFeatherOfRedemption->GetCooldownTime();
			}*/
			// Ajoutez des vérifications pour les autres compétences ici

			// Ensuite, utilisez le temps de recharge obtenu
			GetWorldTimerManager().SetTimer(TimerHandle, this, &AMOBA_Character::HandleCooldowns, CooldownTime, false);
		}
	}
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
