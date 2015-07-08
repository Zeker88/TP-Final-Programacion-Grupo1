#include <allegro5/allegro.h>
#include<allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h> 
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "Links_States.h"
extern STATE* statedir;
extern LINK* linkdir;


/*Funciones de Links*/
LINK* getlink(char* origin, char* destiny)
{
    LINK* linkfound;
    for(linkfound=linkdir; linkfound!=NULL;linkfound=linkfound->p2next)
    {
        if(!((strcmp(linkfound->origen,origin)!=0)|| ((strcmp(linkfound->destino, destiny))!=0)))
        {
         return linkfound;
        }


    }
    return(linkfound);

}

LINK* addlink (char* fun,char ev,char* str, char* str2,ALLEGRO_DISPLAY *dis)
{
    LINK* clon;
    
    if (!strcmp(str,str2)) {
    
        al_show_native_message_box(dis, "ERROR!", "ERROR!", "Cannot create this kind of link",NULL, ALLEGRO_MESSAGEBOX_ERROR);
                  return NULL;
    
    }
    
    
    if (linkdir==NULL)
        {    if(getstate(str)==NULL)
            {
                return NULL;
            }
             if(getstate(str2)==NULL)
            {
                
                return NULL;
            }
            if(getlink(str,str2)!=NULL)
            {
             
                return NULL;
            }

            linkdir=calloc(1,sizeof(LINK));
            linkdir->p2next=NULL;
            strcpy(linkdir->origen, str);
            strcpy(linkdir->destino, str2);
            
            strcpy(linkdir->fun_transf,fun);
            (linkdir->evento)=ev;
            ++linknumb;
            al_show_native_message_box(dis, "SUCCESS!", "Link created successfully", "",NULL, ALLEGRO_MESSAGEBOX_WARN);
                  
            return(linkdir);
        }
    else
        {
            for(clon=linkdir;clon->p2next!=NULL;clon=clon->p2next);
              if(getstate(str)==NULL)
            {
               al_show_native_message_box(dis, "ERROR!", "ERROR!", "That link does not exist!",NULL, ALLEGRO_MESSAGEBOX_ERROR);
                  return NULL;
            }
             if(getstate(str2)==NULL)
            {
                al_show_native_message_box(dis, "ERROR!", "ERROR!", "El estado de origen no existe(Linkdir).",NULL, ALLEGRO_MESSAGEBOX_ERROR);
                return NULL;
            }
          //  if(getlink(str,str2)!=NULL)
          //  {
          //      al_show_native_message_box(dis, "ERROR!", "ERROR!", "El enlace ya existe!",NULL, ALLEGRO_MESSAGEBOX_ERROR);
          //      return NULL;
          //  }
            clon->p2next=calloc(1,sizeof(LINK));
            clon->p2next->p2next=NULL;
            strcpy(clon->p2next->origen, str);
            strcpy(clon->p2next->destino, str2);
            strcpy(clon->p2next->fun_transf,fun);
            clon->p2next->evento=ev;
            ++linknumb;
            al_show_native_message_box(dis, "SUCCESS!", "Link created successfully", "",NULL, ALLEGRO_MESSAGEBOX_WARN);
            return(clon->p2next);

        }
}

LINK* getorigin(char* origin)
{
    LINK* linkfound;
    for(linkfound=linkdir; linkfound!=NULL;linkfound=linkfound->p2next)
    {
        if(!((strcmp(linkfound->origen,origin)!=0)))
        {
            return linkfound;
        }


    }
    return(linkfound);

}

LINK* getdestiny(char* destiny)
{
    LINK* linkfound;
    for(linkfound=linkdir; linkfound!=NULL;linkfound=linkfound->p2next)
    {
        if(! ((strcmp(linkfound->destino, destiny))!=0))
        {
            return linkfound;
        }


    }
    return(linkfound);

}

int eraselink (char* str, char* str2)
{
    
    LINK* clon;
    LINK* aux;
    if (getlink(str,str2)==NULL)
    {
        return(0);
    }
    if (linkdir==NULL)
    {
        return(0);
    }
    if((linkdir->p2next)==NULL)
    {

       if(((strcmp(linkdir->origen,str)!=0)|| (strcmp(linkdir->destino, str2)!=0)))
       {

       }
        else
        {
            free(linkdir);
            linkdir=NULL;
            --linknumb;
        }
        return(1);
    }
    if(!((strcmp(linkdir->origen,str)!=0)|| (strcmp(linkdir->destino, str2)!=0)))
    {
    aux=linkdir->p2next;
    
    free(linkdir);
    linkdir = aux;
    --linknumb;
    return(1);
    }
    for(clon=linkdir;((strcmp(clon->p2next->origen,str)!=0)|| (strcmp(clon->p2next->destino, str2)!=0));clon=clon->p2next)
    {
        if(clon->p2next==NULL)
        {

               return(1);
        }

    }
    aux=clon->p2next->p2next;
    free(clon->p2next);
    clon->p2next = aux;
    --linknumb;
    return(1);



}

void deletedep (char* state)
{
    while(getorigin(state)!=NULL)
        eraselink(getorigin(state)->origen, getorigin(state)->destino);
    while(getdestiny(state)!=NULL)
        eraselink(getdestiny(state)->origen, getdestiny(state)->destino);
}

int linksofstate (char* state)
{
    int linkcount=0;
    LINK* linkfound;
    for(linkfound=linkdir; linkfound!=NULL;linkfound=linkfound->p2next)
    {
        if(!((strcmp(linkfound->origen,state)!=0)))
        {
            ++linkcount;
        }
    }
    /*printf("Linkcount=%d",linkcount);*/
    return(linkcount);
}

/*Funciones de State*/

STATE* getstate(char* statename)
{
    STATE* statefound;
    for(statefound=statedir; statefound!=NULL;statefound=statefound->p2next)
    {
        if(!strcmp(statefound->nombre,statename))
            return statefound;

    }
    return(statefound);

}

STATE* getstate2(int x, int y)
{
    STATE* statefound;
    for(statefound=statedir; statefound!=NULL;statefound=statefound->p2next)
    {
        if((x>=((*statefound).x-DIAM)) && (x<(((*statefound).x)+DIAM)) && (y>=((*statefound).y-DIAM)) && (y<(((*statefound).y)+DIAM)))
            return statefound;

    }
    return (statefound);

}


STATE* addstate (void)
{
    STATE* clon;
    if (statedir==NULL)
        {
            
     
            if(getstate(wordd)!=NULL)
            {
                printf("\nEl estado ya existe!");
                return NULL;
            }
            statedir=calloc(1,sizeof(STATE));
            statedir->p2next=NULL;
            strcpy(statedir->nombre, wordd);
            ++statesnumb;
            return(statedir);
        }
    else
        {
            for(clon=statedir;clon->p2next!=NULL;clon=clon->p2next);
            
            
            if(getstate(wordd)!=NULL)
            {
                return NULL;
            }
            clon->p2next=calloc(1,sizeof(STATE));
            clon->p2next->p2next=NULL;
            strcpy(clon->p2next->nombre, wordd);
            ++statesnumb;
            return(clon->p2next);

        }
}

void removestate (int x, int y)
{
    char str[20];
    STATE* clon;
    STATE* clon1;
    STATE* aux;

    if (statedir==NULL)
    {
        
        return;
    }
    
    for (clon1 = statedir; clon1 !=NULL; clon1= clon1->p2next) {
          if((x>=(clon1->x)) && (x<((clon1->x)+DIAM)) && (y>=(clon1->y)) && (y<(clon1->y)+DIAM))
           break; 

}

     if(!clon1){return;}       
    
    
   
    clon=clon1;
    strcpy(str,clon->nombre);
    
    if (getstate(str)==NULL)
    {
        return;
    }
    
    if((statedir->p2next)==NULL)
    {

        if(strcmp(statedir->nombre, str))
        {
        }
        else
        {
            deletedep(str);
            free(statedir);
            statedir=NULL;
            --statesnumb;
        }
        return;
    }
    if(!strcmp(statedir->nombre,str))
    {
    deletedep(str);
    aux=statedir->p2next;
    free(statedir);
    statedir = aux;
    --statesnumb;
    return;
    }
    for(clon=statedir;strcmp(clon->p2next->nombre,str);clon=clon->p2next)
    {
    
        if(clon->p2next==NULL)    return;

    }
    deletedep(str);
    aux=clon->p2next->p2next;
    free(clon->p2next);
    clon->p2next = aux;
    --statesnumb;
    return;
}

STATE* returnstate(void)
{
    return(statedir);

}

int linkcount (int x, int y, int x2, int y2)
{
	int counter=0;
	LINK* clone;
	for (clone=linkdir; clone!=NULL; clone= clone->p2next)
	{
		if((!strcmp(clone->origen, getstate2(x,y)->nombre)) && (!strcmp(clone->destino, getstate2(x2,y2)->nombre)))
		counter++;
		if((!strcmp(clone->destino, getstate2(x,y)->nombre)) && (!strcmp(clone->origen, getstate2(x2,y2)->nombre)))
                    if(counter==1) counter=2;
	}
	return counter;
	
}
void clear_all(void){

    STATE* clon;
    STATE* clbup;
    LINK* clon1;
    LINK* cl1bup;
    
    if(statedir == NULL) return;
    
    
    
        for(clon=statedir; (clon->p2next) != NULL; ){
        clbup=clon;
        clon=clon->p2next;        
        free(clbup);   }
   
        clbup=clon;
        clon=clon->p2next;        
        free(clbup);
        statedir=NULL;
     
    if (linkdir == NULL) return;
    
    
        for(clon1=linkdir; (clon1->p2next) !=NULL; ){
        cl1bup=clon1;
        clon1=clon1->p2next;
        free(cl1bup);}
    
        cl1bup=clon1;
        clon1=clon1->p2next;
        free(cl1bup);
        linkdir=NULL;
        
}
int linkcount2 (int x, int y, int x2, int y2)
{
	int counter=0;
	LINK* clone;
	for (clone=linkdir; clone!=NULL; clone= clone->p2next)
	{
		if((!strcmp(clone->origen, getstate2(x,y)->nombre)) && (!strcmp(clone->destino, getstate2(x2,y2)->nombre)))
		counter++;

	}
	return counter;

}

STATE* statelinked (STATE* clon)
{   
    LINK* linkclon;
    
    if (clon == NULL) return NULL;
    
    linkclon= getorigin( clon->nombre );
    
    if( linkclon != NULL )    return(getstate(linkclon->destino));    
    
    linkclon=getdestiny( clon->nombre );
    
    if(linkclon != NULL) return(getstate(linkclon->origen));
    
    return NULL;
    
}


