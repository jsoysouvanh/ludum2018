#include "StateMachine.h"
#include "Characters/MainCharacter.h"

StateMachine::StateMachine(AMainCharacter* chara, StateType initState):
	_currentState{ nullptr }
{
	initStates(chara);
	
	_currentState = _states[static_cast<uint8>(initState)];
	_currentState->onEnterState();
}

StateMachine::~StateMachine()
{
	delete _states[0];
	delete _states[1];
	delete _states[2];
	delete _states[3];
}

void StateMachine::initStates(AMainCharacter* chara)
{
	_states[0] = new IdleRunState(chara);
	_states[1] = new RAttackState(chara);
	_states[2] = new LAttackState(chara);
	_states[3] = new JumpState(chara);
}

bool StateMachine::switchTo(StateType nextState)
{
	IState* state = _states[static_cast<uint8>(nextState)];

	if (_currentState && _currentState->canSwitchTo(state->getState()))
	{
		_currentState->onExitState();
		_currentState = state;
		_currentState->onEnterState();

		return true;
	}

	return false;
}

uint8 StateMachine::getState() const
{
	return _currentState->getState();
}