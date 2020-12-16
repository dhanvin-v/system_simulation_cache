#include "membus.h"

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
    membus mem;
    int val;

    port(std::vector<std::bitset<8>> &rams);

    void sendPacket(packet &p, int &tickval);

    void checkval();

};

