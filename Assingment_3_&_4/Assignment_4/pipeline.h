#include "cache.h"

//Pipeline class stores the instruction, data and stage and its resective getter and setter functions
class Pipeline
{
    public:
        std::bitset<32> op_instruction;
        std::string instruction;
        std::string stage;
        int int_data;
        float float_data;
        std::string rs1;
        std::string rs2;
        std::string rd;
        int type;
};





class port
{
    public:
    cache inst_cache_cpu0;
    cache data_cache_cpu0;
    cache inst_cache_cpu1;
    cache data_cache_cpu1;
    int cachehit1 = 0, cachemiss1 = 0,cachehit2 = 0, cachemiss2 = 0,cachehit3 = 0, cachemiss3 = 0,cachehit4 = 0, cachemiss4 = 0;
    membus mem;


    port(std::vector<std::bitset<8>> &rams);

    void sendPacket(packet &p, int &tickval, int cno, cacheval &cv);


};
