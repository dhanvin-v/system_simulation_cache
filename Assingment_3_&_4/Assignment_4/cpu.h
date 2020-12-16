#include "event.h"

class CPU
{
    public:
    int pc;
    std::vector<std::bitset<32>> integer_reg;
    std::vector<std::bitset<32>> float_reg;
    std::vector<Pipeline> pip;

    CPU(int sp_addr);
};
