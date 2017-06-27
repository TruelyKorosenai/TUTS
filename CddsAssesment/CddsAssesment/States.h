#pragma once
#include <iostream>

enum class g_States { INIT, MAIN, RUNNING };


/******************************************************************************
*******************************************************************************/
class State {
public:
    State() {}
    virtual ~State() {}

    virtual g_States getEnum() = 0;

    virtual void handleEvent(g_States) = 0; // Pure virtual

                                          // usually used to initialise resources
    virtual void onEnter(g_States fromState) {}

    // usually used to clean up resources
    virtual void onExit(g_States toState) {}

    virtual void Update() {}
};

/******************************************************************************
*******************************************************************************/
class InitState : public State {
public:
    InitState(){}
    ~InitState(){}

    virtual g_States getEnum() { return g_States::INIT; }

    virtual void onEnter(g_States fromState) {
        std::cout << "State:Init" << std::endl; 
        system ("timeout 3 >nul");
    }
    virtual void handleEvent(g_States) {}
private:
};


/******************************************************************************
*******************************************************************************/
class MainState : public State {
public:
    MainState(){}
    ~MainState(){}

    virtual g_States getEnum() { return g_States::MAIN; }
    virtual void Update() {
        std::cout << "State:Main" << std::endl;
    }
    virtual void handleEvent(g_States) {}
private:
};


/******************************************************************************
*******************************************************************************/
class RunningState : public State {
public:
    RunningState() {}
    ~RunningState() {}

    virtual g_States getEnum() { return g_States::RUNNING; }

    virtual void handleEvent(g_States) {}
private:

};

