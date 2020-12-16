#include "pipeline.h"

//Constructor class for ports used to set membus and initialise cache
port::port(std::vector<std::bitset<8>> &rams)
{
    inst_cache_cpu0.cache_init(256,32,0);
    inst_cache_cpu0.init_sim1(rams);
    data_cache_cpu0.cache_init(512,32,0);
    data_cache_cpu0.init_sim2(rams);
    inst_cache_cpu1.cache_init(256,32,0);
    inst_cache_cpu1.init_sim3(rams);
    data_cache_cpu1.cache_init(512,32,0);
    data_cache_cpu1.init_sim4(rams);

    mem.set_ram(rams);
}

//Function used to check the packet as to instruction or data and send it to cache
void port::sendPacket(packet &p, int &tickval, int cno, cacheval &cv)
{
        
    if(cno == 1)
    {
        if(p.type == "fetch")
        {
            inst_cache_cpu0.getaddr(p.addr_valls.at(0), p, cachehit1, cachemiss1, mem, tickval);
            tickval = tickval + 3;
            cv.cachehit1 = cachehit1;
            cv.cachemiss1 = cachemiss1;
        }

        else if(p.type == "read")
        {
            data_cache_cpu0.getaddr(p.addr_valls.at(0), p, cachehit2, cachemiss2, mem, tickval);
            tickval = tickval + 4;
            cv.cachehit2 = cachehit2;
            cv.cachemiss2 = cachemiss2;
        }

            else
        {
            data_cache_cpu0.getaddr(p.sp, p, cachehit2, cachemiss2, mem, tickval);
            tickval = tickval + 4;
            cv.cachehit2 = cachehit2;
            cv.cachemiss2 = cachemiss2;
        }
    }

    if(cno == 2)
    {
        if(p.type == "fetch")
        {
            inst_cache_cpu1.getaddr(p.addr_valls.at(0), p, cachehit3, cachemiss3, mem, tickval);
            tickval = tickval + 3;
            cv.cachehit3 = cachehit3;
            cv.cachemiss3 = cachemiss3;
        }

        else if(p.type == "read")
        {
            data_cache_cpu1.getaddr(p.addr_valls.at(0), p, cachehit4, cachemiss4, mem, tickval);
            tickval = tickval + 4;
            cv.cachehit4 = cachehit4;
            cv.cachemiss4 = cachemiss4;
        }

        else
        {
            data_cache_cpu1.getaddr(p.sp, p, cachehit4, cachemiss4, mem, tickval);
            tickval = tickval + 4;
            cv.cachehit4 = cachehit4;
            cv.cachemiss4 = cachemiss4;
        }
    }

        
}


