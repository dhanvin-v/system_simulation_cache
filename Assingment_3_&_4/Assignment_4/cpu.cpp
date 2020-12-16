#include "cpu.h"

//CPU constructor used to load empty values
CPU::CPU(int sp_addr)
{
    for(int i = 0;i<32;i++)
    {
        integer_reg.push_back(0);
    }
    integer_reg.at(2) = sp_addr;

    for(int i = 0;i<32; i++)
    {
        float_reg.push_back(0);
    }

}
