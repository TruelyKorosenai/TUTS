
#include "StateManager.h"

int main() {
    //*********************************************************************************************************************
    //*******************************************GAME STATES****************************************************************
    //*********************************************************************************************************************

	StateMachine::GetStateMachine().setState(g_States::ListTest);

	StateMachine::GetStateMachine().StateUpdate();
	StateMachine::GetStateMachine().StateUpdate();
	StateMachine::GetStateMachine().StateUpdate();

   return 0;
}