#pragma once

#include "IdleRunState.h"
#include "JumpState.h"
#include "LAttackState.h"
#include "RAttackState.h"

class StateMachine
{
	private:
		//Variables
		IState*		_currentState;
		IState*		_states[5];

		//Methods
		void initStates(AMainCharacter* chara);

	public:
		//Constructors
		StateMachine(AMainCharacter* chara, StateType initState = StateType::IDLE);

		//Destructor
		~StateMachine();

		//Methods
		bool switchTo(StateType nextState);

		uint8 getState() const;
};