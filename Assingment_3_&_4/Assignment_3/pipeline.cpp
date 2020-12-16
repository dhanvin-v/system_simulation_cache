#include "pipeline.h"

    //Constructor class for ports used to set membus
    port::port(std::vector<std::bitset<8>> &rams)
    {
        mem.set_ram(rams);
    }

    //Function used to send packet to membus
    void port::sendPacket(packet &p, int &tickval)
    {
        mem.sendPacket(p, tickval);
    }

    //Function used to check data for memory contention from membus
    void port::checkval()
    {
        if(mem.mem_check == 1)
        {
            val = 1;
            mem.mem_check = 0;
        }
    }
