#include <stdio.h>
#include "FSM.h"
#include "FSMtable.h"

/*Foward Declarations*/

extern STATE estado1[];
extern STATE estado2[];
extern STATE etado3[];


/* Prototipos */

void reset (void);
void func1 (void);
void func2 (void);


/*** tablas de estado ***/

/*** ESTADO: estado1 ***/

STATE estado1[]=
{
	{'a',estado2,func1},
	{FIN_TABLA,estado1,reset}
};
/*** ESTADO: estado2 ***/

STATE estado2[]=
{
	{'b',estado1,func2},
	{FIN_TABLA,estado1,reset}
};
/*** ESTADO: etado3 ***/

STATE etado3[]=
{
	{FIN_TABLA,estado1,reset}
};


/* Interfaz */

STATE *FSM_GetInitState(void)
{
return (estado1);
}

/* Rutinas de accion */

void reset (void)
{
printf("Reset\n");
}

void func1 (void)
{
printf("Hola\n");
}


void func2 (void)
{
printf("chau\n");
}
