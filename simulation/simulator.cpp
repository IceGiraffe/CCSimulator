#include "../inc.h"
#include "Event.h"
#include "Simulator.h"

/*
 * Simulator is for a FIB chip, a MAC chip and others 
 * It's suggested to use public 
 * 
 */
using namespace std;

uint64_t Simulator::now(){
    return clock;
}
void Simulator::insert(Event * event){
    auto loc = events.before_begin();
    for(Event * e: events){
        if(*event < *e) break;
        loc ++;
    }
    events.insert_after(loc, event);
}
void Simulator::push_front(Event * e){
    events.push_front(e);
}
void Simulator::reverse(){
    events.reverse();
}
void Simulator::delay(int cycle, Event * event){
    event->clock += cycle;
    event->delay += cycle;
    insert(event);
}
void Simulator::doAllEvent(){
    while(!events.empty()){
        auto * e = events.front();
        events.pop_front();
        e->execute(this);
    }
}