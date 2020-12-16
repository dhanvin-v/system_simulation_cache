In order to compile and execute, use the folliwing two commands

1)make
2)./meq

The classes present are:

class Pipeline

class port

class packet

class membus

class CPU

class Event

class system

class cache

class cacheline


This project contains 6 files

1)pipeline.h
2)event.h
3)event.cpp
4)system.h
5)system.cpp
6)main.cpp

Few of the classes and functions are mentioned below:

A) Class Pipeline:
            Pipeline class stores the instruction, data and stage, rs1, rs2, rd, imm values.

B) Class Events:
            Event class stores the the current event which contains a pipeline queue and its respective time and has a function to process the events.

    int process( std::vector<Pipeline> &pip, int &pc, std::vector<std::bitset<32>> &integer_reg, std::vector<std::bitset<32>> &float_reg, port &po, int &tickval, int cno, cacheval &cv, int &fc);

    std::string find_reg_int(int rd_val);
    
    std::string find_reg_float(int rd_val);

    void decode(Pipeline &pipe);

    int execute(port &po,  std::vector<Pipeline> &pip, int &pc, std::vector<std::bitset<32>> &integer_reg, std::vector<std::bitset<32>> &float_reg, int &tickval, int cno, cacheval &cv);

    int find_reg_float_val(std::string rd_string);

    int find_reg_int_val(std::string rd_string);

    int find_val(std::bitset<32> val);

    void fetch(port &po , std::vector<Pipeline> &pip, int &pc, int &tickval, int cno, cacheval &cv);

C) Class System:
            Class system schedules the events by storing it into the MEQ and prints the events inside a text file.

    i) int System::schedule(Event e , Tick t) : Schedules the event by adding it to the MEQ.


D) Class CPU

E) Class packet

F) Class port
    void sendPacket(packet &p, int &tickval, int cno, cacheval &cv);

G) Class membus

        void set_ram(std::vector<std::bitset<8>> &rams);

        void sendPacket(packet &p, int &tickval);

        void check_memstate(int &tickval);

        void check_prevaddr(packet &p, int &tickval);

        void get_I_port_cpu0(packet &p);

        void get_I_port_cpu1(packet &p);

        void get_D_port_cpu(packet &p);

        void set_D_port_cpu(packet &p);

H) Class cache

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





H)  main.cpp file: 

	i)	void create_empty_vec(std::vector<std::bitset<8>> &ram, std::vector<std::bitset<32>> &integer_reg, std::vector<std::bitset<32>> &float_reg) :
    		Creating ram with all initial values assigned to zero.
    		
    	ii)	void create_ram(std::vector<std::bitset<8>> &ram) : Creating RAM by assigning the opcodes and filling array a and array b with random values.
    	
    	iii)	Event create_first_pipeline(std::vector<std::bitset<8>> ram , std::vector<Pipeline> &pip) : Creating the first event and pipeline.
    	
    	iv)	void print(std::vector<std::bitset<8>> ram) : Function for verifying if a + b = c.
    	


Answers for the questions asked in the assignment:

1) CPI after re-running assignment 3 with 100 sim ticks for memory access:
 
 CPI for cpu0 13.47
 CPI for cpu1 13.47

2) Average CPI after implementaing cache 

CPI for cpu0 3.955
CPI for cpu1 3.956


 