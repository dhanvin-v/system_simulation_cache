#include "cache.h"

//Constructor which accepts the cacheline,linesize and 
//calculates the value bitindex size, bitoffset size, 
//cache index size, tab block
void cache::cache_init(int cs, int ls, int ms)
{
    cachesize = cs;
    linesize = ls;
    memorysize = ms;
    no_lines = (cs/ls);
    bo_size = log2(linesize);
    //std::cout<<"bosize : "<<bo_size<<"\n";
    ci_size = log2(no_lines);
    std::cout<<"cisize : "<<ci_size<<"\n";
    tb_size = 13-(bo_size + ci_size);
}

//Cache init for simulation 1
void cache::init_sim1(std::vector<std::bitset<8>> &ram)
{
    cacheline cl;
    cl.tag_bit  = "01000";
    cl.ci = 0;
    int k = 0;
    cl.bit_index = "01000000";
    for(int i = 0x400; i<0x420;i++)
    {
        cl.line.at(k) = ram.at(i);
        k++;
    }
    data.push_back(cl);
    cd = 0;        
}

void cache::init_sim3(std::vector<std::bitset<8>> &ram)
{
    cacheline cl;
    cl.tag_bit  = "01000";
    cl.ci = 0;
    int k = 0;
    cl.bit_index = "01000000";
    for(int i = 0x400; i<0x420;i++)
    {
        cl.line.at(k) = ram.at(i);
        k++;
    }
    data.push_back(cl);
//    std::cout<<data.at(0).line.size()<<"first ";
    cd = 0;        
}

//Cache init for simulation 2
void cache::init_sim2(std::vector<std::bitset<8>> &ram)
{
    cacheline cl;
    cl.tag_bit  = "0100";
    cl.ci = 0;
    int k = 0;
    cl.bit_index = "01000000";
    for(int i = 0x400; i<0x420;i++)
    {
        cl.line.at(k) = ram.at(i);
        k++;
    }
//    std::cout<<"size"<<k;
    data.push_back(cl);
    cd = 1;
}

//Cache init for simulation 2
void cache::init_sim4(std::vector<std::bitset<8>> &ram)
{
    cacheline cl;
    cl.tag_bit  = "0100";
    cl.ci = 0;
    int k = 0;
    cl.bit_index = "01000000";
    for(int i = 0x400; i<0x420;i++)
    {
        cl.line.at(k) = ram.at(i);
        k++;
    }
    data.push_back(cl);
    cd = 1;
}

//Function used to get address fror direct mapping
void cache::getaddr(int addr , packet &p, int &cachehit, int &cachemiss, membus &mem, int &tickval)
{
    std::bitset<13> bit_addr = addr;
    std::string bit_addr_str;
    bit_addr_str = bit_addr.to_string();


    std::string tb_str;
    tb_str = bit_addr_str.substr(0,tb_size);

    std::string ci_str;
    ci_str = bit_addr_str.substr(tb_size,ci_size);
    std::bitset<5> ci_bit(ci_str);
    int ci = (int)(ci_bit.to_ulong());

    std::string bo_str;
    bo_str = bit_addr_str.substr(tb_size + ci_size,5);
    std::bitset<10> bo_bit(ci_str);
    int bo = (int)(bo_bit.to_ulong());

    std::string bi_str;
    bi_str = bit_addr_str.substr(0,tb_size + ci_size);
    check_data(ci,tb_str,bit_addr,mem,bi_str, cachehit, cachemiss, p, tickval);

    }

//Function used to check if address is present in cache for direct mapping
void cache::check_data(int ci, std::string tb_str, std::bitset<13> bit_addr, membus &mem, std::string bi_str, int &cachehit, int &cachemiss, packet &p, int &tickval)
{
    int blag = 0;
    for(int i = 0;i<data.size();i++)
    {
        if(data.at(i).ci == ci)
        {
            if(data.at(i).tag_bit == tb_str)
            {
                blag = 1;
            }
        }

    }

    if(blag == 0)
    {
        int a = bit_addr.to_ulong();
        cachemiss++;
        get_data(bit_addr,tb_str,ci,bi_str,mem,p);
        fill_data(bit_addr,tb_str,ci,bi_str,p);
        tickval = 100;
    }

    else if(blag == 1)
    {
        int a = bit_addr.to_ulong();
        cachehit++;
        fill_data(bit_addr,tb_str,ci,bi_str,p);
    }

}

//Function used to fill data to the arrived packer
void cache::fill_data(std::bitset<13> bit_addr, std::string tb_str, int ci, std::string bi_str,packet &p)
{
    int tval;
    if((p.type == "read") || (p.type == "fetch"))
    {
        for(int i = 0;i<data.size();i++)
        {
            if(data.at(i).ci == ci)
            {
                if(data.at(i).tag_bit == tb_str)
                {
                    tval = (p.addr_valls.at(0))%(linesize);
                    p.valls.at(0) = data.at(i).line.at(tval); 
                    p.valls.at(1) = data.at(i).line.at(tval+ 1);
                    p.valls.at(2) = data.at(i).line.at(tval+ 2);
                    p.valls.at(3) = data.at(i).line.at(tval+ 3);
                }
            }
        }    
    }

    if(p.type == "write")
    {

        for(int i = 0;i<data.size();i++)
        {
            if(data.at(i).ci == ci)
            {
                if(data.at(i).tag_bit == tb_str)
                {
                    data.at(i).dirty_bit = 1;
                    tval = (p.sp)%(linesize);
                    data.at(i).line.at(tval) = p.valls.at(0);
                    data.at(i).line.at(tval+1) = p.valls.at(1);
                    data.at(i).line.at(tval+2) = p.valls.at(2);
                    data.at(i).line.at(tval+3) = p.valls.at(3);
                }
            }
        }
    }

}
//Function used to get data if address is not present in the cache for direct mapping
void cache::get_data(std::bitset<13> bit_addr, std::string tb_str, int ci, std::string bi_str, membus &mem, packet &p)
{
    for(int i = 0;i<data.size();i++)
    {
        if(ci == data.at(i).ci)
        {
            if(data.at(i).dirty_bit == 1)
            {
                std::string st_dat,st_data;
                st_data = "0";
                st_dat = data.at(i).bit_index;
                for(int k = 0; k<bo_size; k++)
                {
                    st_dat = st_dat + st_data;
                }
                std::bitset<13> str_datas(st_dat);
                int begin = (int)(str_datas.to_ulong());
                int m= 0,tim;


                for(int j = 0;j <linesize; j+=4)
                {
                    packet p;
                    p.type = "write";
                    p.valls.at(0) = data.at(i).line.at(m);
                    p.valls.at(1) = data.at(i).line.at(m + 1);
                    p.valls.at(2) = data.at(i).line.at(m + 2);
                    p.valls.at(3) = data.at(i).line.at(m + 3);
                    p.sp = begin;
                    begin = begin + 4;

                    mem.sendPacket(p, tim);

                    m = m+4;
                }
            }
            data.erase(data.begin() + i);
            
            
        }
    }

     int simple;   
    int addrs = (int)(bit_addr.to_ulong());
    int val,start,stop;
    val = addrs/linesize;
    start = val * linesize;
    stop = start + linesize;
    cacheline cl;
    cl.tag_bit = tb_str;
    cl.ci = ci;
    int k = 0;
    if(cd == 0)
    {
        std::bitset<3> temp_ci = ci;
    std::string cistr;
    cistr = temp_ci.to_string();
    cl.bit_index = tb_str + cistr;
    }
    else
    {
        std::bitset<4> temp_ci = ci;
    std::string cistr;
    cistr = temp_ci.to_string();
    cl.bit_index = tb_str + cistr;
    }

    for(int i = start; i<stop;i+=4)
    {
        packet ps;
        
        if(p.type == "fetch")
        ps.type = "fetch";

        else
        ps.type = "read";

        ps.addr_valls.at(0) = i;
        ps.addr_valls.at(1) = i + 1;
        ps.addr_valls.at(2) = i + 2;
        ps.addr_valls.at(3) = i + 3;

        mem.sendPacket(ps,simple);

        cl.line.at(k) = ps.valls.at(0);
        cl.line.at(k+1) = ps.valls.at(1);
        cl.line.at(k+2) = ps.valls.at(2);
        cl.line.at(k+3) = ps.valls.at(3);
        k = k+4;  
    }

    data.push_back(cl); 
    lru.push_back(bi_str);  

}


//Function used to get address fror fully associative mapping
void cache::getaddr_full_ass(int addr , std::vector<std::bitset<8>> &ram, int &cachehit, int &cachemiss)
{
    std::bitset<13> bit_addr = addr;
    std::string bit_addr_str;
    bit_addr_str = bit_addr.to_string();


    std::string tb_str;
    tb_str = bit_addr_str.substr(0,5);

    std::string ci_str;
    ci_str = bit_addr_str.substr(5,3);
    std::bitset<3> ci_bit(ci_str);
    int ci = (int)(ci_bit.to_ulong());

    std::string bo_str;
    bo_str = bit_addr_str.substr(8,5);
    std::bitset<5> bo_bit(ci_str);
    int bo = (int)(bo_bit.to_ulong());

    std::string bi_str;
    bi_str = bit_addr_str.substr(0,8);

}

//Function used to check if address is present in cache for fully associative mapping
void cache::check_data_full_ass(int ci, std::string tb_str, std::bitset<13> bit_addr, std::vector<std::bitset<8>> &ram, std::string bi_str, int &cachehit, int &cachemiss)
{
    int blag = 0;
    for(int i = 0;i<data.size();i++)
    {
        if(data.at(i).ci == ci)
        {
            if(data.at(i).tag_bit == tb_str)
            {
                blag = 1;
                for(int i = 0;i<lru.size();i++)
                {
                    if(lru.at(i) == bi_str)
                    {
                        if(lru.size() <= no_lines)
                        {
                            lru.erase(lru.begin() + i);
                        }
                    }
                }
                lru.push_back(bi_str);
            }
        }

    }

    if(blag == 0)
    {
        int a = bit_addr.to_ulong();
        std::cout<<"cachemiss "<<std::hex<<a<<"\n";
        cachemiss++;
//        get_data(bit_addr,tb_str,ci,bi_str,ram);
    }

    else if(blag == 1)
    {
        int a = bit_addr.to_ulong();
        std::cout<<"cachehit "<<std::hex<<a<<"\n";
        cachehit++;
    }

}

//Function used to get data if address is not present in the cache for fully associative mapping
void cache::get_data_full_ass(std::bitset<13> bit_addr, std::string tb_str, int ci, std::string bi_str, std::vector<std::bitset<8>> &ram)
{

    if(lru.size() >= no_lines)
    {  
        for(int i = 0;i<data.size();i++)
        {
            if(lru.at(0) == data.at(i).bit_index)
            {
                data.erase(data.begin() + i);
            }
        }
        lru.erase(lru.begin());
    }
    
    int addrs = (int)(bit_addr.to_ulong());
    int val,start,stop;
    val = addrs/linesize;
    start = val * linesize;
    stop = start + linesize;
    cacheline cl;
    cl.tag_bit = tb_str;
    cl.ci = ci;
    int k = 0;
    std::bitset<3> temp_ci = ci;
    std::string cistr;
    cistr = temp_ci.to_string();
    cl.bit_index = tb_str + cistr;


    for(int i = start; i<stop;i++)
    {
        cl.line.at(k) = ram.at(i);
        k++;
    }
    data.push_back(cl); 
    lru.push_back(bi_str);  

}
