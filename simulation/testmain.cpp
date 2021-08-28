#include "../inc.h"
#include "Simulator.h"
#include "Event.h"
#include "Packet.h"
#include "Event.cpp"
#include "Simulator.cpp"

// class Chip{
//     public:
//     int tileNum;
//     PacketEvent * transfer;
//     int turn = 0;

//     // every Simulator represents a tile
//     // parameter tileNum is requested while constructing Chip
//     vector<Simulator *> tile;
//     Chip(int _tileNum):tileNum(_tileNum){
//         for(int i = 0; i < tileNum; i++){
//             tile.emplace_back(new Simulator());
//         }
//         transfer = nullptr;
//         turn = 0;
//     }
//     void executeChip(){
        
//     }
//     ~Chip(){
//         transfer = nullptr;
//         for(auto & c: tile){
//             delete c;
//         }
//     }
// };

class Chip: public Simulator{
public:
    int tileNum;
    Chip(int _tileNum):tileNum(_tileNum){
        
    }
    ~Chip(){

    }
};

int main(){
    int clock = 0;
    int sn = 0;
    Chip * chip = new Chip(16);
    
    chip->insert(new PacketEvent(new PacketDescriptor(new Packet()), 0, 0));
    chip->doAllEvent();
    return 0;
}