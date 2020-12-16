In order to compile and execute, use the folliwing two commands

1)make
2)./meq


This project contains the following files

membus.h
membus.cpp

pipeline.h
pipeline.cpp

event.h
event.cpp

system.h
system.cpp

main.cpp



The following classes in the assignment

class Pipeline

class port

class packet

class membus

class CPU

class Event

class system



Few of the classes and functions are mentioned below:

A) Class Pipeline:
            Pipeline class stores the instruction, data and stage, rs1, rs2, rd, imm values.

B) Class Events:
            Event class stores the the current event which contains a pipeline queue and its respective time and has a function to process the events.

    int process( std::vector<Pipeline> &pip, int &pc, std::vector<std::bitset<32>> &integer_reg, std::vector<std::bitset<32>> &float_reg, port &po, int &tickval, int &fc1) 
        : Function used to process the events.

    std::string find_reg_int(int rd_val)
        : Used to find the register name of 32bit integer registers
    
    std::string find_reg_float(int rd_val)
    	: Used to find the register name of 32bit float registers

    void decode(Pipeline &pipe)
    	: Function used to decode the given instruction

    int execute(port &po,  std::vector<Pipeline> &pip, int &pc, std::vector<std::bitset<32>> &integer_reg, std::vector<std::bitset<32>> &float_reg, int &tickval)
    	: Function used to execute the instruction

    int find_reg_float_val(std::string rd_string)
    	: Used to find the value of the 32bit float registers

    int find_reg_int_val(std::string rd_string)
    	: Used to find the value of the 32bit integer registers

    int find_val(std::bitset<32> val)
    	: Function used to find the content of the imm

    void fetch(port &po , std::vector<Pipeline> &pip, int &pc, int &tickval)
    	: Function used to fetch the instruction


C) Class System:
            Class system schedules the events by storing it into the MEQ and prints the events inside a text file.

    i) int System::schedule(Event e , Tick t) : Schedules the event by adding it to the MEQ.

D) Class port

    port(std::vector<std::bitset<8>> &rams);

    void sendPacket(packet &p, int &tickval);

    void checkval();

E) Class packet

F) Class membus

        void set_ram(std::vector<std::bitset<8>> &rams);

        void sendPacket(packet &p, int &tickval);

        void check_memstate(int &tickval);

        void check_prevaddr(packet &p, int &tickval);

        void get_I_port_cpu0(packet &p);

        void get_I_port_cpu1(packet &p);

        void get_D_port_cpu(packet &p);

        void set_D_port_cpu(packet &p);

G) Class CPU

H)  main.cpp file: 

	i)	void create_empty_vec(std::vector<std::bitset<8>> &ram, std::vector<std::bitset<32>> &integer_reg, std::vector<std::bitset<32>> &float_reg) :
    		Creating ram with all initial values assigned to zero.
    		
    	ii)	void create_ram(std::vector<std::bitset<8>> &ram) : Creating RAM by assigning the opcodes and filling array a and array b with random values.
    	
    	iii)	Event create_first_pipeline(std::vector<std::bitset<8>> ram , std::vector<Pipeline> &pip) : Creating the first event and pipeline.
    	
    	iv)	void print(std::vector<std::bitset<8>> ram) : Function for verifying if a + b = c.
    	


Answers for the questions asked in the assignment:


The RAM is byte addressable for which bitset<8> was used, contains the following:
	i)	instructions from CPU0.s from 0x0 - 0x93
	ii)	stack from 0x200 - 0x2FF
	iii)	random value generated for array a in 0x400 - 0x7FF
	iv)	random value generated for array a in 0x800 - 0xBFF
	v)	space allocated for array c 0xC00 - 0xFFF
	vi)	total space used for RAM, 0x0-0x13FF
	
The CPU contains 32 bit integer registers and float registers :     std::vector<std::bitset<32>> integer_reg, std::vector<std::bitset<32>> float_reg
The CPU also contains a program counter : int pc
One CPU cycle takes 10 sim ticks which is caluculated in the main function.

Verification of the array elements in ram will be printed when the program is executed.

The CPU0.s when converted to c is :

int main()
{
	float array_a[255];
	float array_b[255];
	float array_c[255];
	
	for(int i = 0;i<255;i++)
	{
		array_c[i] = array_a[i] + array_b[i];
	}
	
	return 0;
}

CPI for cpu0 : 5.04
CPI for cpu1 : 5.04