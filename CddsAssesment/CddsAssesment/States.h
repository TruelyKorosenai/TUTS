#pragma once
enum class g_States { ListTest, BinaryTest, HashTableTest };


/******************************************************************************
*******************************************************************************/
class State {
public:
    State() {}
    virtual ~State() {}

    virtual g_States getEnum() = 0;

    virtual void handleEvent(g_States) = 0; // Pure virtual

                                          // usually used to initialise resources
    virtual void onEnter(g_States fromState){}

    // usually used to clean up resources
    virtual void onExit(g_States toState){}

    virtual void Update() {}
};

/******************************************************************************
*******************************************************************************/
class ListTestState : public State {
public:
    ListTestState(){}
    ~ListTestState(){}

    virtual g_States getEnum() { return g_States::ListTest; }

    virtual void onEnter(g_States fromState);

    // usually used to clean up resources
    virtual void onExit(g_States toState){}

	virtual void Update(){}
    virtual void handleEvent(g_States) {}
private:
};


/******************************************************************************
*******************************************************************************/
class BinaryTestState : public State {
public:
	BinaryTestState(){}
    ~BinaryTestState(){}

    virtual void onEnter(g_States fromState);

    // usually used to clean up resources
    virtual void onExit(g_States toState){}

    virtual g_States getEnum() { return g_States::BinaryTest; }
	virtual void Update(){}
    virtual void handleEvent(g_States) {}
private:
};


/******************************************************************************
*******************************************************************************/
class HashTableTestState : public State {
public:
	HashTableTestState() {}
    ~HashTableTestState() {}

    virtual void onEnter(g_States fromState);

    // usually used to clean up resources
    virtual void onExit(g_States toState){}

    virtual g_States getEnum() { return g_States::HashTableTest; }
	virtual void Update(){}
    virtual void handleEvent(g_States) {}
private:

};

