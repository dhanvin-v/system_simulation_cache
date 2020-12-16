#ifndef _SYSTEM_H__
#define _SYSTEM_H_

#include "cpu.h"
#include<iostream>

//Class system schedules the events by storing it into the MEQ and prints the events inside a text file
class System
{
    private:
        Tick currentTick;
        std::vector<Event> MEQ;

    public:
        System()
        {
            currentTick = 0;
        }
        
        Tick currTick()
        {
            return currentTick;
        }

        void schedule(Event e, Tick t);

        void reschedule(Event e, Tick t);

};

#endif
