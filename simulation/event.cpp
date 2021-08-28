#include "../inc.h"
#include "Simulator.h"
#include "Event.h"

using namespace std;

Event::Event(uint64_t clock, uint64_t sn):clock(clock), sn(sn){};
bool Event::operator < (const Event & e){
    return clock < e.clock;
}
bool Event::operator > (const Event & e){
    return clock > e.clock;
}
void Event::execute(Simulator * simulator){
    cout << clock <<" " << sn <<"\t";
    clock += 100;
    simulator -> insert(this);
}