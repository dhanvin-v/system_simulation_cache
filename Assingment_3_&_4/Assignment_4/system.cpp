#include "system.h"
#include <fstream>


//Schedules the event by adding it to the MEQ
void System::schedule(Event e , Tick t)
{
    MEQ.push_back(e);
}


