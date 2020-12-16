#include "system.h"
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <random>

//Creating ram with all initial values assigned to zero
void create_empty_vec(std::vector<std::bitset<8>> &ram) 
{
    for(int i = 0;i<5120;i++)
    {
        ram.push_back(0);
    }

}

//Creating RAM by assigning the opcodes and filling array a and array b with random values
void create_ram(std::vector<std::bitset<8>> &ram)
{
    ram.at(0) = 0xFF;
    ram.at(1) =  0x01;
    ram.at(2) =  0x01;
    ram.at(3) =  0x13;

    ram.at(4) =  0x00;
    ram.at(5) =  0x11;
    ram.at(6) = 0x26;
    ram.at(7) =  0x23;

    ram.at(8) =  0x00;
    ram.at(9) =  0x81;
    ram.at(10) =   0x24;
    ram.at(11) =   0x23;

    ram.at(12) =   0x01;
    ram.at(13) =   0x01;
    ram.at(14) =   0x04;
    ram.at(15) =   0x13;

    ram.at(16) =   0x00;
    ram.at(17) =   0x00;
    ram.at(18) =   0x05;
    ram.at(19) =   0x13;

    ram.at(20) =   0xFE;
    ram.at(21) =   0xA4;
    ram.at(22) =   0x2A;
    ram.at(23) =   0x23;

    ram.at(24) =   0xFE;
    ram.at(25) =   0xA4;
    ram.at(26) =   0x28;
    ram.at(27) =   0x23;

    ram.at(28) =   0x04;
    ram.at(29) =   0x00;
    ram.at(30) =   0x00;
    ram.at(31) =   0x6F;

    ram.at(32) =   0xFF;
    ram.at(33) =   0x04;
    ram.at(34) =   0x25;
    ram.at(35) =   0x03;

    ram.at(36) =   0x0F;
    ram.at(37) =   0xF0;
    ram.at(38) =   0x05;
    ram.at(39) =   0x93;

    ram.at(40) =   0x10;
    ram.at(41) =   0xA5;
    ram.at(42) =   0xC0;
    ram.at(43) =   0x63;

    ram.at(44) =   0x06;
    ram.at(45) =   0x00;
    ram.at(46) =   0x00;
    ram.at(47) =   0x6F;

    ram.at(48) =   0x00;
    ram.at(49) =   0x00;
    ram.at(50) =   0x05;
    ram.at(51) =   0x37;

    ram.at(52) =   0x40;
    ram.at(53) =   0x05;
    ram.at(54) =   0x05;
    ram.at(55) =   0x13;

    ram.at(56) =   0xFF;
    ram.at(57) =   0x04;
    ram.at(58) =   0x25;
    ram.at(59) =   0x83;

    ram.at(60) =   0x00;
    ram.at(61) =   0x25;
    ram.at(62) =   0x95;
    ram.at(63) =   0x93;

    ram.at(64) =   0x00;
    ram.at(65) =   0xB5;
    ram.at(66) =   0x05;
    ram.at(67) =   0x33;

    ram.at(68) =   0x00;
    ram.at(69) =   0x05;
    ram.at(70) =   0x20;
    ram.at(71) =   0x07;

    ram.at(72) =   0x00;
    ram.at(73) =   0x00;
    ram.at(74) =   0x05;
    ram.at(75) =   0x37;

    ram.at(76) =   0x80;
    ram.at(77) =   0x05;
    ram.at(78) =   0x05;
    ram.at(79) =   0x13;

    ram.at(80) =   0x00;
    ram.at(81) =   0xB5;
    ram.at(82) =   0x05;
    ram.at(83) =   0x33;

    ram.at(84) =   0x00;
    ram.at(85) =   0x05;
    ram.at(86) =   0x20;
    ram.at(87) =   0x87;

    ram.at(88) =   0x00;
    ram.at(89) =   0x10;
    ram.at(90) =   0x70;
    ram.at(91) =   0x53;

    ram.at(92) =   0x00;
    ram.at(93) =   0x00;
    ram.at(94) =   0x05;
    ram.at(95) =   0x37;

    ram.at(96) =   0xC0;
    ram.at(97) =   0x05;
    ram.at(98) =   0x05;
    ram.at(99) =   0x13;

    ram.at(100) =  0x00;
    ram.at(101) =  0xB5;
    ram.at(102) =  0x05;
    ram.at(103) =  0x33;

    ram.at(104) =  0x00;
    ram.at(105) =  0x05;
    ram.at(106) =  0x20;
    ram.at(107) =  0x27;

    ram.at(108) =  0x0E;
    ram.at(109) =  0x00;
    ram.at(110) =  0x00;
    ram.at(111) =  0x6F;

    ram.at(112) =  0xFF;
    ram.at(113) =  0x04;
    ram.at(114) =  0x25;
    ram.at(115) =  0x03;

    ram.at(116) =  0x00;
    ram.at(117) =  0x15;
    ram.at(118) =  0x05;
    ram.at(119) =  0x13;

    ram.at(120) =  0xFE;
    ram.at(121) =  0xA4;
    ram.at(122) =  0x28;
    ram.at(123) =  0x23;

    ram.at(124) =  0x04;
    ram.at(125) =  0x00;
    ram.at(126) =  0x00;
    ram.at(127) =  0x6F;

    ram.at(128) =  0xFF;
    ram.at(129) =  0x44;
    ram.at(130) =  0x25;
    ram.at(131) =  0x03;

    ram.at(132) =  0x00;
    ram.at(133) =  0x81;
    ram.at(134) =  0x24;
    ram.at(135) =  0x03;

    ram.at(136) =  0x00;
    ram.at(137) =  0xC0;
    ram.at(138) =  0xA4;
    ram.at(139) =  0x03;

    ram.at(140) =  0x01;
    ram.at(141) =  0x01;
    ram.at(142) =  0x01;
    ram.at(143) =  0x13;

    ram.at(144) =  0x00;
    ram.at(145) =  0x00;
    ram.at(146) =  0x80;
    ram.at(147) =  0x67;

    ram.at(256) = 0xFF;
    ram.at(257) =  0x01;
    ram.at(258) =  0x01;
    ram.at(259) =  0x13;

    ram.at(260) =  0x00;
    ram.at(261) =  0x11;
    ram.at(262) = 0x26;
    ram.at(263) =  0x23;

    ram.at(264) =  0x00;
    ram.at(265) =  0x81;
    ram.at(266) =   0x24;
    ram.at(267) =   0x23;

    ram.at(268) =   0x01;
    ram.at(269) =   0x01;
    ram.at(270) =   0x04;
    ram.at(271) =   0x13;

    ram.at(272) =   0x00;
    ram.at(273) =   0x00;
    ram.at(274) =   0x05;
    ram.at(275) =   0x13;

    ram.at(276) =   0xFE;
    ram.at(277) =   0xA4;
    ram.at(278) =   0x2A;
    ram.at(279) =   0x23;

    ram.at(280) =   0xFE;
    ram.at(281) =   0xA4;
    ram.at(282) =   0x28;
    ram.at(283) =   0x23;

    ram.at(284) =   0x24;
    ram.at(285) =   0x00;
    ram.at(286) =   0x00;
    ram.at(287) =   0x6F;

    ram.at(288) =   0xFF;
    ram.at(289) =   0x04;
    ram.at(290) =   0x25;
    ram.at(291) =   0x03;

    ram.at(292) =   0x0F;
    ram.at(293) =   0xF0;
    ram.at(294) =   0x05;
    ram.at(295) =   0x93;

    ram.at(296) =   0x10;
    ram.at(297) =   0xA5;
    ram.at(298) =   0xC0;
    ram.at(299) =   0x63;

    ram.at(300) =   0x26;
    ram.at(301) =   0x00;
    ram.at(302) =   0x00;
    ram.at(303) =   0x6F;

    ram.at(304) =   0x00;
    ram.at(305) =   0x00;
    ram.at(306) =   0x05;
    ram.at(307) =   0x37;

    ram.at(308) =   0x40;
    ram.at(309) =   0x05;
    ram.at(310) =   0x05;
    ram.at(311) =   0x13;

    ram.at(312) =   0xFF;
    ram.at(313) =   0x04;
    ram.at(314) =   0x25;
    ram.at(315) =   0x83;

    ram.at(316) =   0x00;
    ram.at(317) =   0x25;
    ram.at(318) =   0x95;
    ram.at(319) =   0x93;

    ram.at(320) =   0x00;
    ram.at(321) =   0xB5;
    ram.at(322) =   0x05;
    ram.at(323) =   0x33;

    ram.at(324) =   0x00;
    ram.at(325) =   0x05;
    ram.at(326) =   0x20;
    ram.at(327) =   0x07;

    ram.at(328) =   0x00;
    ram.at(329) =   0x00;
    ram.at(330) =   0x05;
    ram.at(331) =   0x37;

    ram.at(332) =   0x80;
    ram.at(333) =   0x05;
    ram.at(334) =   0x05;
    ram.at(335) =   0x13;

    ram.at(336) =   0x00;
    ram.at(337) =   0xB5;
    ram.at(338) =   0x05;
    ram.at(339) =   0x33;

    ram.at(340) =   0x00;
    ram.at(341) =   0x05;
    ram.at(342) =   0x20;
    ram.at(343) =   0x87;

    ram.at(344) =   0x08;
    ram.at(345) =   0x10;
    ram.at(346) =   0x70;
    ram.at(347) =   0x53;

    ram.at(348) =   0x00;
    ram.at(349) =   0x00;
    ram.at(350) =   0x15;
    ram.at(351) =   0x37;

    ram.at(352) =   0x00;
    ram.at(353) =   0x05;
    ram.at(354) =   0x05;
    ram.at(355) =   0x13;

    ram.at(356) =  0x00;
    ram.at(357) =  0xB5;
    ram.at(358) =  0x05;
    ram.at(359) =  0x33;

    ram.at(360) =  0x00;
    ram.at(361) =  0x05;
    ram.at(362) =  0x20;
    ram.at(363) =  0x27;

    ram.at(364) =  0x2E;
    ram.at(365) =  0x00;
    ram.at(366) =  0x00;
    ram.at(367) =  0x6F;

    ram.at(368) =  0xFF;
    ram.at(369) =  0x04;
    ram.at(370) =  0x25;
    ram.at(371) =  0x03;

    ram.at(372) =  0x00;
    ram.at(373) =  0x15;
    ram.at(374) =  0x05;
    ram.at(375) =  0x13;

    ram.at(376) =  0xFE;
    ram.at(377) =  0xA4;
    ram.at(378) =  0x28;
    ram.at(379) =  0x23;

    ram.at(380) =  0x24;
    ram.at(381) =  0x00;
    ram.at(382) =  0x00;
    ram.at(383) =  0x6F;

    ram.at(384) =  0xFF;
    ram.at(385) =  0x44;
    ram.at(386) =  0x25;
    ram.at(387) =  0x03;

    ram.at(388) =  0x00;
    ram.at(389) =  0x81;
    ram.at(390) =  0x24;
    ram.at(391) =  0x03;

    ram.at(392) =  0x00;
    ram.at(393) =  0xC0;
    ram.at(394) =  0xA4;
    ram.at(395) =  0x03;

    ram.at(396) =  0x01;
    ram.at(397) =  0x01;
    ram.at(398) =  0x01;
    ram.at(399) =  0x13;

    ram.at(400) =  0x00;
    ram.at(401) =  0x00;
    ram.at(402) =  0x80;
    ram.at(403) =  0x67;


    for(int k = 1024; k<2048; k+=4)
    {
        int num = (rand() % 25);
//        int num = 5;
        std::bitset<32> num_bit = num;
        std::bitset<8> num_bit4;
        std::bitset<8> num_bit1;
        std::bitset<8> num_bit2;
        std::bitset<8> num_bit3;
        std::string num_string = num_bit.to_string();
    
        int i = 0;
        for(int j = 0;j<8;j++)
        {
            num_bit1[i] = num_bit[j];
            i++;
        }

        i = 0;
        for(int j = 8;j<16;j++)
        {
            num_bit2[i] = num_bit[j];
            i++;
        }

        i = 0;
        for(int j = 16;j<24;j++)
        {
            num_bit3[i] = num_bit[j];
            i++;
        }

        i = 0;
        for(int j = 24;j<32;j++)
        {
            num_bit4[i] = num_bit[j];
            i++;
        }

        ram.at(k) =  num_bit4;
        ram.at(k+1) =  num_bit3;
        ram.at(k+2) = num_bit2;
        ram.at(k+3) =  num_bit1;


    }

    for(int k = 2048; k<3072; k+=4)
    {
        float num = (rand() % 25);
//        int num = 3;
        std::bitset<32> num_bit = num;
        std::bitset<8> num_bit4;
        std::bitset<8> num_bit1;
        std::bitset<8> num_bit2;
        std::bitset<8> num_bit3;
        std::string num_string = num_bit.to_string();
    
        int i = 0;
        for(int j = 0;j<8;j++)
        {
            num_bit1[i] = num_bit[j];
            i++;
        }

        i = 0;
        for(int j = 8;j<16;j++)
        {
            num_bit2[i] = num_bit[j];
            i++;
        }

        i = 0;
        for(int j = 16;j<24;j++)
        {
            num_bit3[i] = num_bit[j];
            i++;
        }

        i = 0;
        for(int j = 24;j<32;j++)
        {
            num_bit4[i] = num_bit[j];
            i++;
        }

        ram.at(k) = num_bit4;
        ram.at(k+1) =  num_bit3;
        ram.at(k+2) =  num_bit2;
        ram.at(k+3) =  num_bit1;


    }

}

//Creating the first event and pipeline
Event create_first_pipeline(std::vector<std::bitset<8>> ram , CPU &cpus)
{
    for(int i = 0;i<4;i+=4)
    {
        Pipeline pl;
        std::bitset<32> op;
        int k = 0;

        for(int j = 0; j<8; j++)
        {
            op[k] = ram.at(i+3)[j];
            k++;
        }

        for(int j = 0; j<8; j++)
        {
            op[k] = ram.at(i+2)[j];
            k++;
        }

        for(int j = 0; j<8; j++)
        {
            op[k] = ram.at(i+1)[j];
            k++;
        }

        for(int j = 0; j<8; j++)
        {
            op[k] = ram.at(i)[j];
            k++;
        }
        pl.op_instruction = op;
        pl.stage = "fetch";
        cpus.pip.push_back(pl);
    }

    Event e(0);
    e.plines = cpus.pip;

    return e;


}

Event create_first_pipeline2(std::vector<std::bitset<8>> ram , CPU &cpus)
{
    for(int i = 0;i<4;i+=4)
    {
        Pipeline pl;
        std::bitset<32> op;
        int k = 0;

        for(int j = 0; j<8; j++)
        {
            op[k] = ram.at(256+3)[j];
            k++;
        }

        for(int j = 0; j<8; j++)
        {
            op[k] = ram.at(256+2)[j];
            k++;
        }

        for(int j = 0; j<8; j++)
        {
            op[k] = ram.at(256+1)[j];
            k++;
        }

        for(int j = 0; j<8; j++)
        {
            op[k] = ram.at(256)[j];
            k++;
        }
        pl.op_instruction = op;
        pl.stage = "fetch";
        cpus.pip.push_back(pl);
    }

    Event e(0);
    e.plines = cpus.pip;

    return e;


}


//Function for verifying if a + b = c
void print(std::vector<std::bitset<8>> ram)
{
    std::vector<int> array_a;
    std::vector<float> array_b;
    std::vector<float> array_c;
    std::vector<float> array_d;

    int aa;
    float bb;
    float cc;
    float dd;
    std::cout<<"\nVerification of cpu0.s and cpu1.s\n";

    for(int c = 1024; c<2048; c+=4)
    {
        std::bitset<32> temp_val;

        int i = 0;
        for(int j = 0;j<8;j++)
        {
            temp_val[j] = ram.at(c + 3)[i];
            i++;
        }

        i = 0;
        for(int j = 8;j<16;j++)
        {
            temp_val[j] = ram.at(c + 2)[i];
            i++;
        }

        i = 0;
        for(int j = 16;j<24;j++)
        {
            temp_val[j] = ram.at(c + 1)[i];
            i++;
        }

        i = 0;
        for(int j = 24;j<32;j++)
        {
            temp_val[j] = ram.at(c)[i];
            i++;
        }

        aa = (int)(temp_val.to_ulong());
        array_a.push_back(aa);
    }

    for(int c = 2048; c<3072; c+=4)
    {
        std::bitset<32> temp_val;

        int i = 0;
        for(int j = 0;j<8;j++)
        {
            temp_val[j] = ram.at(c + 3)[i];
            i++;
        }

        i = 0;
        for(int j = 8;j<16;j++)
        {
            temp_val[j] = ram.at(c + 2)[i];
            i++;
        }

        i = 0;
        for(int j = 16;j<24;j++)
        {
            temp_val[j] = ram.at(c + 1)[i];
            i++;
        }

        i = 0;
        for(int j = 24;j<32;j++)
        {
            temp_val[j] = ram.at(c)[i];
            i++;
        }

        bb = (float)(temp_val.to_ulong());
        array_b.push_back(bb);
    }

    for(int c = 3072; c<4096; c+=4)
    {
        std::bitset<32> temp_val;

        int i = 0;
        for(int j = 0;j<8;j++)
        {
            temp_val[j] = ram.at(c + 3)[i];
            i++;
        }

        i = 0;
        for(int j = 8;j<16;j++)
        {
            temp_val[j] = ram.at(c + 2)[i];
            i++;
        }

        i = 0;
        for(int j = 16;j<24;j++)
        {
            temp_val[j] = ram.at(c + 1)[i];
            i++;
        }

        i = 0;
        for(int j = 24;j<32;j++)
        {
            temp_val[j] = ram.at(c)[i];
            i++;
        }

        cc = (float)(temp_val.to_ulong());
        array_c.push_back(cc);
    }

    for(int d = 4096; d<5120; d+=4)
    {
        std::bitset<32> temp_val;

        int i = 0;
        for(int j = 0;j<8;j++)
        {
            temp_val[j] = ram.at(d + 3)[i];
            i++;
        }

        i = 0;
        for(int j = 8;j<16;j++)
        {
            temp_val[j] = ram.at(d + 2)[i];
            i++;
        }

        i = 0;
        for(int j = 16;j<24;j++)
        {
            temp_val[j] = ram.at(d + 1)[i];
            i++;
        }

        i = 0;
        for(int j = 24;j<32;j++)
        {
            temp_val[j] = ram.at(d)[i];
            i++;
        }

        if(temp_val[31] == 1)
        {
            temp_val.flip();
            dd = ((float)(temp_val.to_ulong()) + 1) * (-1);
        }
    
        else
        dd = (float)(temp_val.to_ulong());

        array_d.push_back(dd);
    }

    for(int s = 0; s<array_c.size();s++)
    {
    std::cout<<array_a.at(s)<<"\t"<<"+"<<"\t"<<array_b.at(s)<<"\t"<<"="<<"\t"<<array_c.at(s)<<"\t"<<array_d.at(s)<<"\n";
    }
}

int main()
{
    System s;
    int cpu_cycle = 0;
    std::vector<std::bitset<8>> ram;
    create_empty_vec(ram);
    create_ram(ram);
    
    membus mem;
    mem.set_ram(ram);

    port po(ram);

    CPU cpu0(767);
    CPU cpu1(1023);

    Event ei(0);
    Event ej(0);
    ei = create_first_pipeline(ram,cpu0);
    ej = create_first_pipeline2(ram,cpu1);

    s.schedule(ei, 0);
    s.schedule(ej,0);

    int cnt = 0,cnt2 = 0;
    int i = 35,j=35;
    int ss = 0;
    int fc1 = 1;
    int fc2 = 1;

    cpu0.pc = 4;
    cpu1.pc = 260;

    while(cnt != 2)
    {
        Event e(i);
        Event e2(i);
        cnt2 = e.process(cpu0.pip,cpu0.pc,cpu0.integer_reg,cpu0.float_reg,po,i,fc1);
        cnt = e2.process(cpu1.pip,cpu1.pc,cpu1.integer_reg,cpu1.float_reg,po,j,fc2);
        s.schedule(e,i);
        s.schedule(e2,j);
        ss++;
        std::cout<<"\n";
    }
    
    std::cout<<"cpu0 CPI = "<<(i/fc1)/10<<"\n";
    std::cout<<"cpu1 CPI = "<<(j/fc2)/10<<"\n";
    print(ram);
    
  return 0;
}


