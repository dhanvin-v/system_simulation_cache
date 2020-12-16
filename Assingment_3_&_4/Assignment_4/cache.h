#include "membus.h"

class cacheline
{
    public:
    std::vector<std::bitset<8>> line;
    std::string tag_bit;
    int ci;
    std::string bit_index;
    int dirty_bit;

    cacheline()
    {
        for(int i = 0;i<32;i++)
        {
            line.push_back(0);
        }
        dirty_bit = 0;
    }

};


class cache
{
    public:
    int cachesize, linesize, memorysize; 
    std::vector<std::string>lru;
    std::vector<cacheline> data;
    int no_lines;
    int ci_size, tb_size, bo_size;
    int cd;


    void cache_init(int cs, int ls, int ms);

    void init_sim1(std::vector<std::bitset<8>> &ram);

    void init_sim2(std::vector<std::bitset<8>> &ram);

    void init_sim3(std::vector<std::bitset<8>> &ram);

    void init_sim4(std::vector<std::bitset<8>> &ram);

    void getaddr(int addr , packet &p, int &cachehit, int &cachemiss, membus &mem, int &tickval);

    void check_data(int ci, std::string tb_str, std::bitset<13> bit_addr, membus &mem, std::string bi_str, int &cachehit, int &cachemiss, packet &p, int &tickval);

    void get_data(std::bitset<13> bit_addr, std::string tb_str, int ci, std::string bi_str, membus &mem, packet &p);

    void getaddr_full_ass(int addr , std::vector<std::bitset<8>> &ram, int &cachehit, int &cachemiss);

    void check_data_full_ass(int ci, std::string tb_str, std::bitset<13> bit_addr, std::vector<std::bitset<8>> &ram, std::string bi_str, int &cachehit, int &cachemiss);

    void get_data_full_ass(std::bitset<13> bit_addr, std::string tb_str, int ci, std::string bi_str, std::vector<std::bitset<8>> &ram);

    void fill_data(std::bitset<13> bit_addr, std::string tb_str, int ci, std::string bi_str,packet &p);



};


class cacheval
{
    public:
    int cachemiss1,cachehit1;
    int cachemiss2,cachehit2;
    int cachemiss3,cachehit3;
    int cachemiss4,cachehit4;
};
