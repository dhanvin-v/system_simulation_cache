#ifndef _EVENT_H_
#define _EVENT_H_

#include "pipeline.h"
#define Tick uint64_t


//Event class stores the the current event which contains a pipeline queue and its respective time and has a function to process the events
class Event
{
    private:
        Tick time;
        Pipeline pl;

    public:
        std::vector<Pipeline> plines;
        Event(Tick t)
        {
            setTime(t);
        }

        void setTime(Tick t)
        {
            time = t;
        }

        Tick getTime()
        {
            return time;
        }

        void set_pipeline(Pipeline p)
        {
            pl = p;
        }

        Pipeline get_pipeline()
        {
            return pl;
        }


    int process( std::vector<Pipeline> &pip, int &pc, std::vector<std::bitset<32>> &integer_reg, std::vector<std::bitset<32>> &float_reg, port &po, int &tickval, int cno, cacheval &cv, int &fc);

    std::string find_reg_int(int rd_val);
    
    std::string find_reg_float(int rd_val);

    void decode(Pipeline &pipe);

    int execute(port &po,  std::vector<Pipeline> &pip, int &pc, std::vector<std::bitset<32>> &integer_reg, std::vector<std::bitset<32>> &float_reg, int &tickval, int cno, cacheval &cv);

    int find_reg_float_val(std::string rd_string);

    int find_reg_int_val(std::string rd_string);

    int find_val(std::bitset<32> val);

    void fetch(port &po , std::vector<Pipeline> &pip, int &pc, int &tickval, int cno, cacheval &cv);

};


#endif