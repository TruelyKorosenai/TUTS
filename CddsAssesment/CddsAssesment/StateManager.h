#pragma once
#include "States.h"

class StateMachine {
public:
    StateMachine() : m_currState(nullptr) {}
    ~StateMachine() {}

    void setState(g_States newState) {
        g_States prevState = newState;

        if (m_currState != nullptr) {
            prevState = m_currState->getEnum();
            m_currState->onExit(newState);
            delete m_currState;
        }

        switch (newState) {
        case g_States::ListTest: m_currState = new ListTestState; break;
        case g_States::BinaryTest: m_currState = new BinaryTestState; break;
        case g_States::HashTableTest: m_currState = new HashTableTestState; break;
        }
        m_currState->onEnter(prevState);

    }

    void handleEvent(g_States event) {
        if (m_currState != nullptr) {
            m_currState->handleEvent(event);
        }
    }
    g_States GetState() {
        return m_currState->getEnum();
    }

     void StateUpdate() {
    m_currState->Update();
    }

	 static StateMachine &GetStateMachine() {
		 static StateMachine sm;
		 return sm;
	 }
private:
    State *m_currState;

    
};


