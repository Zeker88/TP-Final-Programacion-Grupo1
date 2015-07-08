#include <stdio.h>
#include "FSM.h"

STATE* myfsm (STATE* statep, char event)
{
    while(statep -> evento != event && statep -> evento != 0)
        ++statep;
    (*statep -> rutaction)();
    statep = statep -> nextstate;
    return (statep);
}
