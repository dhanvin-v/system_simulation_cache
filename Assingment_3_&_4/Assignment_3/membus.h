#include <cstdint>
#include <string>
#include <vector>
#include <bits/stdc++.h>

//Pipeline class stores the instruction, data and stage and its resective getter and setter functions


class packet
{
    public:
    std::vector<std::bitset<8>> valls;
    std::vector<int> addr_valls;
    int sp;
    std::string type;

    packet();
};

class membus
{
    public:
        std::vector<std::bitset<8>> *ram;
        int prev_state;
        int mem_check = 0;

        void set_ram(std::vector<std::bitset<8>> &rams);

        void sendPacket(packet &p, int &tickval);

        void check_memstate(int &tickval);

        void check_prevaddr(packet &p, int &tickval);

        void get_I_port_cpu0(packet &p);

        void get_I_port_cpu1(packet &p);

        void get_D_port_cpu(packet &p);

        void set_D_port_cpu(packet &p);
};
