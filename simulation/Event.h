#ifndef EVENT_HEADER
#define EVENT_HEADER
#include "../inc.h"

class Simulator;

class Event{
public:
    uint64_t clock;
    uint64_t sn;
    int state = 0;
    uint64_t delay = 0;

    Event(uint64_t clock, uint64_t sn);
    bool operator < (const Event & e);
    bool operator > (const Event & e);
    virtual void execute(Simulator * simulator);
};


#endif