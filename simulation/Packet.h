#ifndef PACKET_HEADER
#define PACKET_HEADER

#include "../inc.h"
#include "Event.h"
#include "Simulator.h"

using namespace std;

class Packet{
public:
    uint64_t srcAddr;
    uint64_t dstAddr;
    Packet(uint64_t s = 0, uint64_t d = 0):srcAddr(s), dstAddr(d){};
};

class PacketDescriptor{
public:
    Packet * packet;
    uint64_t timestamp_in = 0;
    uint32_t ingress_port = -1;
    uint32_t ingress_tile = -1;
    uint32_t egress_port = -1;
    uint32_t egress_tile = -1;
    int state = 0;
    int learn_delay = 0;
    int lookup_delay = 0;

    PacketDescriptor(Packet * p, uint32_t in_port = 0, uint32_t in_tile = 0):packet(p),ingress_port(in_port),ingress_tile(in_tile){};
};

class PacketEvent: public Event {
public:
    PacketDescriptor * pd;
    PacketEvent(PacketDescriptor * pd, uint64_t clock, int sn):Event(clock, sn){
        this->pd = pd;
        pd->timestamp_in = clock;
        state = 0;
    }
};

#endif