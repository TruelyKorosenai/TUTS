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
        case g_States::INIT: m_currState = new InitState; break;
        case g_States::MAIN: m_currState = new MainState; break;
        case g_States::RUNNING: m_currState = new RunningState; break;
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

    //static StateMachine* GetStateMachine(){
    //    if (thisGSM) return thisGSM;
    //    return thisGSM = new StateMachine();
    //}

    void StateUpdate() {
    m_currState->Update();
    }
private:
    State *m_currState;

    //static StateMachine* thisGSM;
};

//StateMachine* StateMachine::thisGSM = nullptr;

bool getEvent(g_States & event) {
    event = g_States::MAIN;
    return true;
}

