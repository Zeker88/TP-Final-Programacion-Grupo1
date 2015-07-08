#include <stdio.h>
#include "FSM.h"
#include "FSMtable.h"

STATE* p2state=NULL;

#define FIN_ARCHIVO 'Q'

int main(void)
{
    char evento;
    p2state=FSM_GetInitState();

    while(1)
    {
        evento = getchar();
        getchar();
        if (evento==FIN_ARCHIVO)
            return(0);
        p2state= myfsm(p2state, evento);
    }

    return 0;
}
