#pragma once

#include "GameFramework/Character.h"
#include "StateMachine/StateMachine.h"

#include "GlobalCharacter.generated.h"

UCLASS()
class LDJ43_API AGlobalCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	//Custom Methods
	void registerToGameEvents();
	void setupStats();

protected:
	//Variables
	StateMachine		_sMachine		= StateMachine(this);

	//Overriden Methods
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float sacrificeRate = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	FVector color = FVector(1);

	//Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float maxHp = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float hp = maxHp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float basicAttackPower = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float basicAttackSpeed = 1.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Stats")
	float attackSpeedMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float attackCooldown = 0.1f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float attackRange = 70.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool canAttack = true;

	class UMainAnimInstance*	_animInstance = nullptr;

	//Constructors
	AGlobalCharacter();

	//Overriden Methods
	virtual void Tick(float DeltaTime) override;
	
	//Custom Methods
	UFUNCTION(BlueprintCallable)
	virtual void LAttack();

	UFUNCTION(BlueprintCallable)
	virtual void RAttack();

	UFUNCTION(BlueprintCallable)
	virtual bool canHit(AGlobalCharacter const* other);

	UFUNCTION(BlueprintCallable)
	void takeDamageFrom(AGlobalCharacter* other, float damages);

	UFUNCTION()
	virtual void onTakeDamageFrom(AGlobalCharacter* other);

	UFUNCTION()
	virtual void onDie(AGlobalCharacter* deadChar, AGlobalCharacter* other);

	virtual void startAttack();
	virtual void endAttack();

	UFUNCTION(BlueprintCallable)
	virtual void endAttackCooldown();

	UFUNCTION(BlueprintCallable, Category = "Player")
	uint8 GetState() const;

	UFUNCTION(BlueprintCallable)
	virtual float getAttackPower(bool isRightSlot) const;

	UFUNCTION(BlueprintCallable, Category = "Player")
	void SetState(uint8 state);

	float GetMaxHP() const;
	void SetMaxHP(float _maxHp);
};
