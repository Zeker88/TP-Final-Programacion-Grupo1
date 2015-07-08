#include "PrintFSM.h"
#include "Links_States.h"
extern STATE* statedir;
extern LINK* linkdir;

void printfsm (void)
{
STATE* stateclon;
LINK* linkclon;
LINK* linkclon2;

    FILE* p=fopen("FSMtable.c","w+");

    fprintf(p,"%s\n%s\n%s\n\n/*Foward Declarations*/\n\n","#include <stdio.h>","#include \"FSM.h\"","#include \"FSMtable.h\"");
    
    

    for(stateclon=statedir;stateclon!=NULL;stateclon=stateclon->p2next)
        fprintf(p,"%s %s[];\n","extern STATE",stateclon->nombre);


     fprintf(p,"\n\n/* Prototipos */\n\nvoid reset (void);\n");
     for(linkclon2=linkdir;linkclon2!=NULL;linkclon2=linkclon2->p2next)
    {
        fprintf(p,"void %s (void);\n",linkclon2->fun_transf);
        
    }
    
    fprintf(p,"\n\n/*** tablas de estado ***/\n\n");
             
    for(stateclon=statedir;stateclon!=NULL;stateclon=stateclon->p2next)
    {
        fprintf(p,"/*** ESTADO: %s ***/\n\nSTATE %s[]=\n{\n\t",stateclon->nombre,stateclon->nombre);

        for(linkclon=linkdir;linkclon!=NULL;linkclon=linkclon->p2next)
        {
            if(!strcmp(linkclon->origen,stateclon->nombre))
            {
                fprintf(p,"{'%c',%s,%s},\n\t",linkclon->evento,linkclon->destino,linkclon->fun_transf);
            }   
        }
        fprintf(p,"{FIN_TABLA,%s,reset}\n};\n",statedir->nombre);
    }

    fprintf(p,"\n\n/* Interfaz */\n\nSTATE *FSM_GetInitState(void)\n{\nreturn (%s);\n}",statedir->nombre);
    
    fprintf(p,"\n\n/* Rutinas de accion */\n\nvoid reset (void)\n{\nprintf(\"Reset\\n\");\n}");
    
    for(linkclon2=linkdir;linkclon2!=NULL;linkclon2=linkclon2->p2next)
    {
        fprintf(p,"\n\nvoid %s (void)\n{\n\n}\n",linkclon2->fun_transf);
        
    }
    
    fclose(p);

}


