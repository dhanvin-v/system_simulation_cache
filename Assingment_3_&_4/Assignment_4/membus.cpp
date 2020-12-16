#include "membus.h"

void membus::set_ram(std::vector<std::bitset<8>> &rams)
{
    ram = &rams;
}

//Function used to send receive packet from port and assign it accordingly
void membus::sendPacket(packet &p, int &tickval)
{
    tickval = tickval + 5;
    tickval = tickval + 20;
    if(p.type == "fetch")
    {
        if((p.addr_valls.at(0) <= 0x93) && (p.addr_valls.at(0) >= 0))
        {
           get_I_port_cpu0(p);

        }

        else if((p.addr_valls.at(0) <= 0x193) && (p.addr_valls.at(0) >= 0x100))
        {
           get_I_port_cpu1(p);
        }
    }

    else if(p.type == "read")
    {
            
        if((p.addr_valls.at(0) >=0x200) && (p.addr_valls.at(0) <=0x3FF))
        {
            get_D_port_cpu(p);
        }

        else 
        {
            get_D_port_cpu(p);
            prev_state = p.addr_valls.at(0);
        }
                
    }

    else if(p.type == "write")
    {
        set_D_port_cpu(p);
    }
}

void membus::check_memstate(int &tickval)
{
    if (mem_check==1)
    {
        tickval = tickval + 5;
        mem_check = 0;
    }
}

//Function used to check for memory contention    
void membus::check_prevaddr(packet &p, int &tickval)
{
    if(prev_state == p.addr_valls.at(0))
    {
        tickval = tickval + 5;
        mem_check = 1;
    }
}

//Function to get instruction port data from cpu0
void membus::get_I_port_cpu0(packet &p)
{
    p.valls.at(0) = ram->at(p.addr_valls.at(0));
    p.valls.at(1) = ram->at(p.addr_valls.at(1));
    p.valls.at(2) = ram->at(p.addr_valls.at(2));
    p.valls.at(3) = ram->at(p.addr_valls.at(3));
}

//Function to get instruction port data from cpu1
void membus::get_I_port_cpu1(packet &p)
{
    p.valls.at(0) = ram->at(p.addr_valls.at(0));
    p.valls.at(1) = ram->at(p.addr_valls.at(1));
    p.valls.at(2) = ram->at(p.addr_valls.at(2));
    p.valls.at(3) = ram->at(p.addr_valls.at(3));
}

//Function used to get data port data for cpu0 & cpu1
void membus::get_D_port_cpu(packet &p)
{
    p.valls.at(0) = ram->at(p.addr_valls.at(0));
    p.valls.at(1) = ram->at(p.addr_valls.at(1));
    p.valls.at(2) = ram->at(p.addr_valls.at(2));
    p.valls.at(3) = ram->at(p.addr_valls.at(3));
}

//Function used to write data to memory from cpu0 & cpu1
void membus::set_D_port_cpu(packet &p)
{
    ram->at(p.sp) = p.valls.at(0);
    ram->at(p.sp + 1) = p.valls.at(1);
    ram->at(p.sp + 2) = p.valls.at(2);
    ram->at(p.sp + 3) = p.valls.at(3);
}
