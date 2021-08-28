#ifndef SIMULATOR_HEADER
#define SIMULATOR_HEADER
#include "Event.h"
#include "../inc.h"

using namespace std;

class Simulator{
public:
    uint64_t clock;
    forward_list<Event*> events;
    forward_list<Event*> executedEvents;

    uint64_t now();
    
    void insert(Event * event);
    void push_front(Event * e);
    void reverse();
    void delay(int cycle, Event * event);
    void doAllEvent();
};


#endif