#pragma once

#include "IState.h"

class IdleRunState : public IState
{
	public:
		//Methods
		void onEnterState() override;
		void onExitState() override;
		bool canSwitchTo(uint8 newState) const override;

		//Getters
		uint8 getState() const override;
};