#include "event.h"
#include<iostream>

//Function used to process the events
int Event::process(std::vector<Pipeline> &pip, int &pc, std::vector<std::bitset<32>> &integer_reg, std::vector<std::bitset<32>> &float_reg, port &po, int &tickval, int cno, cacheval &cv, int &fc)
{
    int flag = 0, cnt = 0, slag = 0,count = 0,dlag = 0, clag = 0, glag = 0, currtime = 0, maxtime = 0, schedule = 0;


    if((pip.at(0).stage == "stall") && (slag == 0))
    {   
        if(pip.at(1).stage == "stall")
        {
            pip.erase(pip.begin());
            glag = 1;
        }

        else
        {
            pip.erase(pip.begin());
        }
        
    }

    if(pip.at(0).stage == "execute"  && (glag == 0))
    {
        if(pip.at(0).instruction == "ret")
        {
            cnt = 2;
            flag = 1;
            slag = 1;
            clag = 1;
            pip.erase(pip.begin());
        }

        else
        {
            if(pip.at(0).type == 0)
            {
                pip.erase(pip.begin());
                Pipeline p;
                p.stage = "stall";
                pip.insert(pip.begin(),p);
                glag = 1;
            }

            else if(pip.at(0).type == 1)
            {
                pip.erase(pip.begin());
                for(int i = 0;i<5;i++)
                {
                    Pipeline p;
                    p.stage = "stall";
                    pip.insert(pip.begin(),p);        
                }
                glag = 1;
            }

            else
            {
                pip.erase(pip.begin());
            }
            
        }
        
    }

    if((slag == 0) && (glag == 0))
    {    
        for(int i = 0;i<pip.size(); i++)
        {
            if(pip.at(i).stage == "fetch")
            {
                decode(pip.at(i));
            }

            else if(pip.at(i).stage == "decode")
            {
                flag = execute(po, pip, pc, integer_reg, float_reg, currtime, cno, cv);
                fc++;
                if(currtime > maxtime)
                maxtime = currtime;
                currtime = 0;
                count++;

            }
        }
    }


    if(flag == 0 && dlag == 0 && glag == 0)
    {
        fetch(po,pip,pc,currtime,cno,cv);
        if(currtime > maxtime)
        maxtime = currtime;
        currtime = 0;
        pc = pc + 4;
    }

    if(maxtime < 10)
    tickval = tickval + 10 + schedule ;

    else 
    tickval = tickval + maxtime + schedule;

    if(clag == 0)
    std::cout<<tickval<<"\t"<<pip.at(0).instruction<<"\t"<<pip.at(0).stage<<"\n";

    return cnt;
}

//Used to find the register name of 32bit integer registers
std::string Event::find_reg_int(int rd_val)
{
    std::string reg;
    switch(rd_val)
    {
        case 0:
        reg = "zero";
        break;

        case 1:
        reg = "ra";
        break;

        case 2:
        reg = "sp";
        break;

        case 3:
        reg = "gp";
        break;

        case 4:
        reg = "tp";
        break;

        case 5:
        reg = "t0";
        break;

        case 6:
        reg = "t1";
        break;

        case 7:
        reg = "t2";
        break;

        case 8:
        reg = "s0";
        break;

        case 9:
        reg = "s1";
        break;

        case 10:
        reg = "a0";
        break;

        case 11:
        reg = "a1";
        break;

        case 12:
        reg = "a2";
        break;

        case 13:
        reg = "a3";
        break;

        case 14:
        reg = "a4";
        break;

        case 15:
        reg = "a5";
        break;

        case 16:
        reg = "a6";
        break;

        case 17:
        reg = "a7";
        break;

        case 18:
        reg = "s2";
        break;

        case 19:
        reg = "s3";
        break;

        case 20:
        reg = "s4";
        break;

        case 21:
        reg = "s5";
        break;

        case 22:
        reg = "s6";
        break;

        case 23:
        reg = "s7";
        break;

        case 24:
        reg = "s8";
        break;

        case 25:
        reg = "s9";
        break;

        case 26:
        reg = "s10";
        break;

        case 27:
        reg = "s11";
        break;

        case 28:
        reg = "t3";
        break;

        case 29:
        reg = "t4";
        break;

        case 30:
        reg = "t5";
        break;

        case 31:
        reg = "t6";
        break;

    }
    return reg;
}

//Used to find the value of the 32bit integer registers
int Event::find_reg_int_val(std::string rd_string)
{
    int reg;
    
    if(rd_string == "zero")
    reg = 0;
    
    else if(rd_string == "ra")
    reg = 1;

    else if(rd_string == "sp")
    reg = 2;

    else if(rd_string == "gp")
    reg = 3;

    else if(rd_string == "tp")
    reg = 4;

    else if(rd_string == "t0")
    reg = 5;

    else if(rd_string == "t1")
    reg = 6;

    else if(rd_string == "t2")
    reg = 7;

    else if(rd_string == "s0")
    reg = 8;

    else if(rd_string == "s1")
    reg = 9;

    else if(rd_string == "a0")
    reg = 10;

    else if(rd_string == "a1")
    reg = 11;

    else if(rd_string == "a2")
    reg = 12;

    else if(rd_string == "a3")
    reg = 13;

    else if(rd_string == "a4")
    reg = 14;

    else if(rd_string == "a5")
    reg = 15;

    else if(rd_string == "a6")
    reg = 16;

    else if(rd_string == "a7")
    reg = 17;

    else if(rd_string == "s2")
    reg = 18;

    else if(rd_string == "s3")
    reg = 19;

    else if(rd_string == "s4")
    reg = 20;

    else if(rd_string == "s5")
    reg = 21;

    else if(rd_string == "s6")
    reg = 22;

    else if(rd_string == "s7")
    reg = 23;

    else if(rd_string == "s8")
    reg = 24;

    else if(rd_string == "s9")
    reg = 25;

    else if(rd_string == "s10")
    reg = 26;

    else if(rd_string == "s11")
    reg = 27;

    else if(rd_string == "t3")
    reg = 28;

    else if(rd_string == "t4")
    reg = 29;

    else if(rd_string == "t5")
    reg = 30;

    else if(rd_string == "t6")
    reg = 31;

    return reg;
}

//Used to find the register name of 32bit float registers
std::string Event::find_reg_float(int rd_val)
{
    std::string reg;
    switch(rd_val)
    {
        case 0:
        reg = "ft0";
        break;

        case 1:
        reg = "ft1";
        break;

        case 2:
        reg = "ft2";
        break;

        case 3:
        reg = "ft3";
        break;

        case 4:
        reg = "ft4";
        break;

        case 5:
        reg = "ft5";
        break;

        case 6:
        reg = "ft6";
        break;

        case 7:
        reg = "ft7";
        break;

        case 8:
        reg = "fs0";
        break;

        case 9:
        reg = "fs1";
        break;

        case 10:
        reg = "fa0";
        break;

        case 11:
        reg = "fa1";
        break;

        case 12:
        reg = "fa2";
        break;

        case 13:
        reg = "fa3";
        break;

        case 14:
        reg = "fa4";
        break;

        case 15:
        reg = "fa5";
        break;

        case 16:
        reg = "fa6";
        break;

        case 17:
        reg = "fa7";
        break;

        case 18:
        reg = "fs2";
        break;

        case 19:
        reg = "fs3";
        break;

        case 20:
        reg = "fs4";
        break;

        case 21:
        reg = "fs5";
        break;

        case 22:
        reg = "fs6";
        break;

        case 23:
        reg = "fs7";
        break;

        case 24:
        reg = "fs8";
        break;

        case 25:
        reg = "fs9";
        break;

        case 26:
        reg = "fs10";
        break;

        case 27:
        reg = "fs11";
        break;

        case 28:
        reg = "ft8";
        break;

        case 29:
        reg = "ft9";
        break;

        case 30:
        reg = "ft10";
        break;

        case 31:
        reg = "ft11";
        break;

    }
    return reg;
}

//Used to find the value of the 32bit integer registers
int Event::find_reg_float_val(std::string rd_string)
{
    int reg;
    
    if(rd_string == "ft0")
    reg = 0;
    
    else if(rd_string == "ft1")
    reg = 1;

    else if(rd_string == "ft2")
    reg = 2;

    else if(rd_string == "ft3")
    reg = 3;

    else if(rd_string == "ft4")
    reg = 4;

    else if(rd_string == "ft5")
    reg = 5;

    else if(rd_string == "ft6")
    reg = 6;

    else if(rd_string == "ft7")
    reg = 7;

    else if(rd_string == "fs0")
    reg = 8;

    else if(rd_string == "fs1")
    reg = 9;

    else if(rd_string == "fa0")
    reg = 10;

    else if(rd_string == "fa1")
    reg = 11;

    else if(rd_string == "fa2")
    reg = 12;

    else if(rd_string == "fa3")
    reg = 13;

    else if(rd_string == "fa4")
    reg = 14;

    else if(rd_string == "fa5")
    reg = 15;

    else if(rd_string == "fa6")
    reg = 16;

    else if(rd_string == "fa7")
    reg = 17;

    else if(rd_string == "fs2")
    reg = 18;

    else if(rd_string == "fs3")
    reg = 19;

    else if(rd_string == "fs4")
    reg = 20;

    else if(rd_string == "fs5")
    reg = 21;

    else if(rd_string == "fs6")
    reg = 22;

    else if(rd_string == "fs7")
    reg = 23;

    else if(rd_string == "fs8")
    reg = 24;

    else if(rd_string == "fs9")
    reg = 25;

    else if(rd_string == "fs10")
    reg = 26;

    else if(rd_string == "fs11")
    reg = 27;

    else if(rd_string == "ft8")
    reg = 28;

    else if(rd_string == "ft9")
    reg = 29;

    else if(rd_string == "ft10")
    reg = 30;

    else if(rd_string == "ft11")
    reg = 31;

    return reg;
}

//Function used to decode the given instruction
void Event::decode(Pipeline &pipe)
{
    pipe.stage = "decode";
    std::string inst_op, inst;
    inst_op = pipe.op_instruction.to_string();
    inst = inst_op.substr(25,7);

    if(inst == "0010011")
    {
        std::string inst_op_extn = inst_op.substr(17,3);

        //addi
        if(inst_op_extn == "000")
        {
 
            pipe.type = 0;
            pipe.instruction = "addi";

            std::string rd = inst_op.substr(20,5);
            std::bitset<5> rd_op(rd);
            int rd_val = (int)(rd_op.to_ulong());
            pipe.rd = find_reg_int(rd_val);

            std::string rs1 = inst_op.substr(12,5);
            std::bitset<5> rs1_op(rs1);
            int rs1_val = (int)(rs1_op.to_ulong());
            pipe.rs1 = find_reg_int(rs1_val);

            std::string imm = inst_op.substr(0,12);
            std::bitset<12> imm_op(imm);
            if(imm_op[8] == 1)
            {
                imm_op.flip();
                pipe.int_data = ((int)(imm_op.to_ulong()) + 1)*(-1);
            }
            else
            {
                pipe.int_data = (int)(imm_op.to_ulong());
            }     
            
        }

        //slli
        else if(inst_op_extn == "001")
        {
            pipe.type = 0;
            pipe.instruction = "slli";

            std::string rd = inst_op.substr(20,5);
            std::bitset<5> rd_op(rd);
            int rd_val = (int)(rd_op.to_ulong());
            pipe.rd = find_reg_int(rd_val);

            std::string rs1 = inst_op.substr(12,5);
            std::bitset<5> rs1_op(rs1);
            int rs1_val = (int)(rs1_op.to_ulong());
            pipe.rs1 = find_reg_int(rs1_val);

            std::string imm = inst_op.substr(7,5);
            std::bitset<12> imm_op(imm);
            pipe.int_data = (int)(imm_op.to_ulong());
        }

    }

    //sw
    else if (inst == "0100011")
    {
        pipe.type = 0;
        pipe.instruction = "sw";

        std::string rs1 = inst_op.substr(12,5);
        std::bitset<5> rs1_op(rs1);
        int rs1_val = (int)(rs1_op.to_ulong());
        pipe.rs1 = find_reg_int(rs1_val);

        std::string rs2 = inst_op.substr(7,5);
        std::bitset<5> rs2_op(rs2);
        int rs2_val = (int)(rs2_op.to_ulong());
        pipe.rs2 = find_reg_int(rs2_val);
            
        std::string imm1 = inst_op.substr(0,7);
        std::string imm2 = inst_op.substr(20,5);
        std::string imm = imm1 + imm2;
        std::bitset<12> imm_op(imm);
        if(imm_op[8] == 1)
        {
            imm_op.flip();
            pipe.int_data = ((int)(imm_op.to_ulong()) + 1)*(-1);
        }
        else
        {
            pipe.int_data = (int)(imm_op.to_ulong());
        }     

    }

    //j
    else if (inst == "1101111")
    {
        pipe.type = 2;
        pipe.instruction = "j";

        std::string rd = inst_op.substr(20,5);
        std::bitset<5> rd_op(rd);
        int rd_val = (int)(rd_op.to_ulong());
        pipe.rd = find_reg_int(rd_val);

        std::string imm1 = inst_op.substr(0,1);
        std::string imm2 = inst_op.substr(12,8);
        std::string imm3 = inst_op.substr(11,1);
        std::string imm4 = inst_op.substr(1,10);
        std::string imm = imm1 + imm2 + imm3 + imm4;
        std::bitset<20> imm_op(imm);
        pipe.int_data = (int)(imm_op.to_ulong());
        
    }

    //lw
    else if (inst == "0000011")
    {
        pipe.type = 0;
        pipe.instruction = "lw";

        std::string rd = inst_op.substr(20,5);
        std::bitset<5> rd_op(rd);
        int rd_val = (int)(rd_op.to_ulong());
        pipe.rd = find_reg_int(rd_val);

        std::string rs1 = inst_op.substr(12,5);
        std::bitset<5> rs1_op(rs1);
        int rs1_val = (int)(rs1_op.to_ulong());
        pipe.rs1 = find_reg_int(rs1_val);

        std::string imm = inst_op.substr(0,12);
        std::bitset<12> imm_op(imm);
        if(imm_op[8] == 1)
        {
            imm_op.flip();
            pipe.int_data = ((int)(imm_op.to_ulong()) + 1)*(-1);
        }
        else
        {
            pipe.int_data = (int)(imm_op.to_ulong());
        }     

    }

    //blt
    else if (inst == "1100011")
    {
        pipe.type = 2;
        pipe.instruction = "blt";

        std::string rs1 = inst_op.substr(12,5);
        std::bitset<5> rs1_op(rs1);
        int rs1_val = (int)(rs1_op.to_ulong());
        pipe.rs1 = find_reg_int(rs1_val);

        std::string rs2 = inst_op.substr(7,5);
        std::bitset<5> rs2_op(rs2);
        int rs2_val = (int)(rs2_op.to_ulong());
        pipe.rs2 = find_reg_int(rs2_val);

        std::string imm1 = inst_op.substr(0,1);
        std::string imm2 = inst_op.substr(24,1);
        std::string imm3 = inst_op.substr(1,6);
        std::string imm4 = inst_op.substr(20,4);
        std::string imm = imm1 + imm2 + imm3 + imm4;
        std::bitset<12> imm_op(imm);
        pipe.int_data = (int)(imm_op.to_ulong());

    }

    //lui
    else if (inst == "0110111")
    {
        pipe.type = 0;
        pipe.instruction = "lui";

        std::string rd = inst_op.substr(20,5);
        std::bitset<5> rd_op(rd);
        int rd_val = (int)(rd_op.to_ulong());
        pipe.rd = find_reg_int(rd_val);

        std::string imm = inst_op.substr(0,20);
        std::bitset<20> imm_op(imm);
        if(imm_op[0] == 1)
        {
            imm_op = 4096;
        }
        pipe.int_data = (int)(imm_op.to_ulong());
//        std::cout<<pipe.int_data<<"\n";

    }

    //add
    else if (inst == "0110011")
    {
        pipe.type = 0;
        pipe.instruction = "add";

        std::string rd = inst_op.substr(20,5);
        std::bitset<5> rd_op(rd);
        int rd_val = (int)(rd_op.to_ulong());
        pipe.rd = find_reg_int(rd_val);

        std::string rs1 = inst_op.substr(12,5);
        std::bitset<5> rs1_op(rs1);
        int rs1_val = (int)(rs1_op.to_ulong());
        pipe.rs1 = find_reg_int(rs1_val);

        std::string rs2 = inst_op.substr(7,5);
        std::bitset<5> rs2_op(rs2);
        int rs2_val = (int)(rs2_op.to_ulong());
        pipe.rs2 = find_reg_int(rs2_val);
//        std::cout<<rd_val<<"\n";
    }

    //flw
    else if (inst == "0000111")
    {
        pipe.type = 1;
        pipe.instruction = "flw";

        std::string rd = inst_op.substr(20,5);
        std::bitset<5> rd_op(rd);
        int rd_val = (int)(rd_op.to_ulong());
        pipe.rd = find_reg_float(rd_val);

        std::string rs1 = inst_op.substr(12,5);
        std::bitset<5> rs1_op(rs1);
        int rs1_val = (int)(rs1_op.to_ulong());
        pipe.rs1 = find_reg_int(rs1_val);

        std::string imm = inst_op.substr(0,12);
        std::bitset<12> imm_op(imm);
        pipe.int_data = (int)(imm_op.to_ulong());
    }

    else if (inst == "1010011")
    {

        pipe.type = 1;
        std::string inst_op_extn = inst_op.substr(0,7);

        //fadd.s
        if(inst_op_extn == "0000000")
        {        
            pipe.instruction = "fadd.s";

            std::string rd = inst_op.substr(20,5);
            std::bitset<5> rd_op(rd);
            int rd_val = (int)(rd_op.to_ulong());
            pipe.rd = find_reg_float(rd_val);

            std::string rs1 = inst_op.substr(12,5);
            std::bitset<5> rs1_op(rs1);
            int rs1_val = (int)(rs1_op.to_ulong());
            pipe.rs1 = find_reg_float(rs1_val);

            std::string rs2 = inst_op.substr(7,5);
            std::bitset<5> rs2_op(rs2);
            int rs2_val = (int)(rs2_op.to_ulong());
            pipe.rs2 = find_reg_float(rs2_val);
        }

        //fsub.s
        else if (inst_op_extn == "0000100")
        {
            pipe.instruction = "fsub.s";

            std::string rd = inst_op.substr(20,5);
            std::bitset<5> rd_op(rd);
            int rd_val = (int)(rd_op.to_ulong());
            pipe.rd = find_reg_float(rd_val);

            std::string rs1 = inst_op.substr(12,5);
            std::bitset<5> rs1_op(rs1);
            int rs1_val = (int)(rs1_op.to_ulong());
            pipe.rs1 = find_reg_float(rs1_val);

            std::string rs2 = inst_op.substr(7,5);
            std::bitset<5> rs2_op(rs2);
            int rs2_val = (int)(rs2_op.to_ulong());
            pipe.rs2 = find_reg_float(rs2_val);
        }
    }

    //fsw
    else if (inst == "0100111")
    {
        pipe.type = 1;
        pipe.instruction = "fsw";

        std::string rs1 = inst_op.substr(12,5);
        std::bitset<5> rs1_op(rs1);
        int rs1_val = (int)(rs1_op.to_ulong());
        pipe.rs1 = find_reg_int(rs1_val);

        std::string rs2 = inst_op.substr(7,5);
        std::bitset<5> rs2_op(rs2);
        int rs2_val = (int)(rs2_op.to_ulong());
        pipe.rs2 = find_reg_float(rs2_val);
            
        std::string imm1 = inst_op.substr(0,7);
        std::string imm2 = inst_op.substr(20,5);
        std::string imm = imm1 + imm2;
        std::bitset<12> imm_op(imm);
        if(imm_op[11] == 1)
        {
            imm_op.flip();
            pipe.int_data = ((int)(imm_op.to_ulong()) + 1)*(-1);
        }
        else
        {
            pipe.int_data = (int)(imm_op.to_ulong());
        }     
    }
        
    //ret
    else if (inst == "1100111")
    {
        pipe.type = 0;
        pipe.instruction = "ret";

        std::string rd = inst_op.substr(20,5);
        std::bitset<5> rd_op(rd);
        int rd_val = (int)(rd_op.to_ulong());
        pipe.rd = find_reg_int(rd_val);

        std::string rs1 = inst_op.substr(12,5);
        std::bitset<5> rs1_op(rs1);
        int rs1_val = (int)(rs1_op.to_ulong());
        pipe.rs1 = find_reg_int(rs1_val);

        std::string imm = inst_op.substr(0,12);
        std::bitset<12> imm_op(imm);
        pipe.int_data = (int)(imm_op.to_ulong());

    }

}

//Function used to execute the instruction
int Event::execute(port &po, std::vector<Pipeline> &pip, int &pc, std::vector<std::bitset<32>> &integer_reg, std::vector<std::bitset<32>> &float_reg, int &tickval, int cno, cacheval &cv)
{
    int rs1reg, rs2reg, rdreg, imm, rs1val, rs2val, rdval;
    int ret_val = 0;

    pip.at(0).stage = "execute";

    //addi
    if(pip.at(0).instruction == "addi")
    {
        rs1reg = find_reg_int_val(pip.at(0).rs1);
        rdreg = find_reg_int_val(pip.at(0).rd);

        rs1val = find_val(integer_reg.at(rs1reg));

        rdval = rs1val + pip.at(0).int_data;
        
        std::bitset<32> temp = rdval;
        integer_reg.at(rdreg) = temp;
    }

    //add
    else if(pip.at(0).instruction == "add")
    {
        rs2reg = find_reg_int_val(pip.at(0).rs2);
        rs1reg = find_reg_int_val(pip.at(0).rs1);
        rdreg = find_reg_int_val(pip.at(0).rd);

        rs2val = find_val(integer_reg.at(rs2reg));
        rs1val = find_val(integer_reg.at(rs1reg));

        rdval = rs1val + rs2val;
        std::bitset<32> temp = rdval;
        integer_reg.at(rdreg) = temp;
    }

    //slli
    else if(pip.at(0).instruction == "slli")
    {
        rs1reg = find_reg_int_val(pip.at(0).rs1);
        rdreg = find_reg_int_val(pip.at(0).rd);

        rs1val = find_val(integer_reg.at(rs1reg));

        rdval = rs1val<<pip.at(0).int_data;


        std::bitset<32> temp = rdval;
        integer_reg.at(rdreg) = temp;
    }

    //sw
    else if(pip.at(0).instruction == "sw")
    {
        rs2reg = find_reg_int_val(pip.at(0).rs2);
        rs1reg = find_reg_int_val(pip.at(0).rs1);

        rs2val = find_val(integer_reg.at(rs2reg));
        rs1val = find_val(integer_reg.at(rs1reg));

        int sp = rs1val + pip.at(0).int_data;

        std::bitset<32> temp = rs2val;

        std::bitset<8> num_bit4;
        std::bitset<8> num_bit1;
        std::bitset<8> num_bit2;
        std::bitset<8> num_bit3;
        std::string num_string = temp.to_string();
    
        int i = 0;
        for(int j = 0;j<8;j++)
        {
            num_bit1[i] = temp[j];
            i++;
        }

        i = 0;
        for(int j = 8;j<16;j++)
        {
            num_bit2[i] = temp[j];
            i++;
        }

        i = 0;
        for(int j = 16;j<24;j++)
        {
            num_bit3[i] = temp[j];
            i++;
        }

        i = 0;
        for(int j = 24;j<32;j++)
        {
            num_bit4[i] = temp[j];
            i++;
        }

        packet ps;

        ps.type = "write";
        ps.valls.at(0) = num_bit4;
        ps.valls.at(1) = num_bit3;
        ps.valls.at(2) = num_bit2;
        ps.valls.at(3) = num_bit1;
        ps.sp = sp;

        po.sendPacket(ps,tickval,cno,cv);

    }

    //j
    else if(pip.at(0).instruction == "j")
    {
        pip.erase(pip.begin() + 1, pip.begin() + pip.size());
        pc = pip.at(0).int_data;
        ret_val = 1;
    }

    //lw
    else if(pip.at(0).instruction == "lw")
    {
        rs1reg = find_reg_int_val(pip.at(0).rs1);
        rdreg = find_reg_int_val(pip.at(0).rd);

        rs1val = find_val(integer_reg.at(rs1reg));

        int pos = rs1val + pip.at(0).int_data;
        std::bitset<32> temp_val;

        packet ps;
        ps.type = "read";
        ps.addr_valls.at(0) = pos;
        ps.addr_valls.at(1) = pos + 1;
        ps.addr_valls.at(2) = pos + 2;
        ps.addr_valls.at(3) = pos + 3; 

        po.sendPacket(ps,tickval,cno,cv);

        int i = 0;
        for(int j = 0;j<8;j++)
        {
            temp_val[j] = ps.valls.at(3)[i];
            i++;
        }

        i = 0;
        for(int j = 8;j<16;j++)
        {
            temp_val[j] = ps.valls.at(2)[i];
            i++;
        }

        i = 0;
        for(int j = 16;j<24;j++)
        {
            temp_val[j] = ps.valls.at(1)[i];
            i++;
        }

        i = 0;
        for(int j = 24;j<32;j++)
        {
            temp_val[j] = ps.valls.at(0)[i];
            i++;
        }

        integer_reg.at(rdreg) = temp_val;

    }

    //blt
    else if(pip.at(0).instruction == "blt")
    {
        rs2reg = find_reg_int_val(pip.at(0).rs2);
        rs1reg = find_reg_int_val(pip.at(0).rs1);

        rs2val = find_val(integer_reg.at(rs2reg));
        rs1val = find_val(integer_reg.at(rs1reg));

        if(rs1val<rs2val)
        {
            pip.erase(pip.begin() + 1, pip.begin() + pip.size());
            pc = pip.at(0).int_data;
            ret_val = 1;
        }
    }

    //lui
    else if(pip.at(0).instruction == "lui")
    {
        rdreg = find_reg_int_val(pip.at(0).rd);

        std::bitset<32> temp = pip.at(0).int_data;

        integer_reg.at(rdreg) = temp;
    }

    //flw
    else if(pip.at(0).instruction == "flw")
    {
        rs1reg = find_reg_int_val(pip.at(0).rs1);
        rdreg = find_reg_float_val(pip.at(0).rd);

        rs1val = find_val(integer_reg.at(rs1reg));

        std::bitset<32> temp_val;

        packet ps;
        ps.type = "read";
        ps.addr_valls.at(0) = rs1val;
        ps.addr_valls.at(1) = rs1val + 1;
        ps.addr_valls.at(2) = rs1val + 2;
        ps.addr_valls.at(3) = rs1val + 3; 

        po.sendPacket(ps,tickval,cno,cv);


        int i = 0;
        for(int j = 0;j<8;j++)
        {
            temp_val[j] = ps.valls.at(3)[i];
            i++;
        }

        i = 0;
        for(int j = 8;j<16;j++)
        {
            temp_val[j] = ps.valls.at(2)[i];
            i++;
        }

        i = 0;
        for(int j = 16;j<24;j++)
        {
            temp_val[j] = ps.valls.at(1)[i];
            i++;
        }

        i = 0;
        for(int j = 24;j<32;j++)
        {
            temp_val[j] = ps.valls.at(0)[i];
            i++;
        }

        float_reg.at(rdreg) = temp_val;
    }

    //fadd.s
    else if(pip.at(0).instruction == "fadd.s")
    {
        rs2reg = find_reg_float_val(pip.at(0).rs2);
        rs1reg = find_reg_float_val(pip.at(0).rs1);
        rdreg = find_reg_float_val(pip.at(0).rd);

        rs2val = find_val(float_reg.at(rs2reg));
        rs1val = find_val(float_reg.at(rs1reg));

        rdval = rs1val + rs2val;

        std::bitset<32> temp = rdval;
        float_reg.at(rdreg) = temp;
    }

    //fsub.s
    else if(pip.at(0).instruction == "fsub.s")
    {
        rs2reg = find_reg_float_val(pip.at(0).rs2);
        rs1reg = find_reg_float_val(pip.at(0).rs1);
        rdreg = find_reg_float_val(pip.at(0).rd);

        rs2val = find_val(float_reg.at(rs2reg));
        rs1val = find_val(float_reg.at(rs1reg));

        rdval = rs1val - rs2val;

        std::bitset<32> temp = rdval;
        float_reg.at(rdreg) = temp;
//        std::cout<<"check"<<"\n";
    }

    //fsw
    else if(pip.at(0).instruction == "fsw")
    {
        rs2reg = find_reg_float_val(pip.at(0).rs2);
        rs1reg = find_reg_int_val(pip.at(0).rs1);

        rs2val = find_val(float_reg.at(rs2reg));
        rs1val = find_val(integer_reg.at(rs1reg));

        int sp = rs1val + pip.at(0).int_data;

        std::bitset<32> temp = rs2val;

        std::bitset<8> num_bit4;
        std::bitset<8> num_bit1;
        std::bitset<8> num_bit2;
        std::bitset<8> num_bit3;
        std::string num_string = temp.to_string();
    
        int i = 0;
        for(int j = 0;j<8;j++)
        {
            num_bit1[i] = temp[j];
            i++;
        }

        i = 0;
        for(int j = 8;j<16;j++)
        {
            num_bit2[i] = temp[j];
            i++;
        }

        i = 0;
        for(int j = 16;j<24;j++)
        {
            num_bit3[i] = temp[j];
            i++;
        }

        i = 0;
        for(int j = 24;j<32;j++)
        {
            num_bit4[i] = temp[j];
            i++;
        }

        packet ps;

        ps.type = "write";
        ps.valls.at(0) = num_bit4;
        ps.valls.at(1) = num_bit3;
        ps.valls.at(2) = num_bit2;
        ps.valls.at(3) = num_bit1;
        ps.sp = sp;

        po.sendPacket(ps,tickval,cno,cv);

    }

    //ret
    else if(pip.at(0).instruction == "ret")
    {
        rs1reg = find_reg_int_val(pip.at(0).rs1);
        rdreg = find_reg_int_val(pip.at(0).rd);

        rdval = find_val(integer_reg.at(rdreg));

        integer_reg.at(rs1reg) = rdval + pip.at(0).int_data;
    }


   return ret_val; 

        
}

//Function used to find the content of the imm
int Event::find_val(std::bitset<32> val)
{
    int a;
    if(val[31] == 1)
    {
        val.flip();
        a = ((int)(val.to_ulong()) + 1) * (-1);
    }
    
    else
    a = ((int)(val.to_ulong()));
    return a;
}

//Function used to fetch the instruction
void Event::fetch(port &po , std::vector<Pipeline> &pip, int &pc, int &tickval, int cno, cacheval &cv)
{
    packet ps;
    ps.type = "fetch";
    ps.addr_valls.at(0) = pc;
    ps.addr_valls.at(1) = pc + 1;
    ps.addr_valls.at(2) = pc + 2;
    ps.addr_valls.at(3) = pc + 3;

    po.sendPacket(ps,tickval,cno,cv);


    for(int i = 0;i<4;i+=4)
    {
        Pipeline pl;
        std::bitset<32> op;
        int k = 0;

        for(int j = 0; j<8; j++)
        {
            op[k] = ps.valls.at(3)[j];
            k++;
        }

        for(int j = 0; j<8; j++)
        {
            op[k] = ps.valls.at(2)[j];
            k++;
        }

        for(int j = 0; j<8; j++)
        {
            op[k] = ps.valls.at(1)[j];
            k++;
        }

        for(int j = 0; j<8; j++)
        {
            op[k] = ps.valls.at(0)[j];
            k++;
        }
        pl.op_instruction = op;
        pl.stage = "fetch";
        pip.push_back(pl);
    }

}

