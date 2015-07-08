#ifndef LS
#define LS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <allegro5/allegro.h>
#include<allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h> 
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#define RADIO 50
#define DIAM 100
#define TRUE 1
#define FALSE 0
extern char wordd[20];
extern int contw;
extern int writen;

/*Estructuras y Variables P�blicas*/

typedef struct vinculo LINK;
struct vinculo
{
    char origen[20];
    char destino[20];
    char fun_transf[20];
    char evento;
    LINK* p2next;
};

typedef struct estado STATE;
struct estado{
    char nombre[20];
    int x;
    int y;
    STATE* p2next;

};

//STATE* statedir=NULL; /*Direcci�n de inicio del arreglo de estados*/
//LINK* linkdir=NULL; /*Idem, pero de v�nculos*/
int statesnumb; /*Contador del n�mero de estados*/
int linknumb;/*Ideam, pero de v�nculos*/

/*Prototipos*/
LINK* getlink(char*,char*); /*Busca la direcci�n del vinculo en funci�n de su origen y destino*/
LINK* getorigin(char*); /*Busca la direcci�n del vinculo solo en funci�n de su origen*/
LINK* getdestiny(char*);/*Idem, pero en funci�n del destino*/
LINK* addlink (char* fun,char ev,char* str, char* str2,ALLEGRO_DISPLAY *dis);
int linksofstate (char*);/*Devuelve el n�mero de vinculos que salen de un estado*/
//void removelink (void);/*Elimina un vinculo*/
int eraselink (char*,char*);/*Idem, pero no contempla errores. Funci�n de uso interno*/
void deletedep (char*);/*Elimina todos los v�nculos que dependen de un estado determinado*/
int linkcount (int x, int y, int x2, int y2);
STATE* getstate(char*);/*Busca la direcci�n del estado en funci�n de su nombre*/
STATE* addstate(void);/*Agrega un nuevo estado, contemplando errores, repetici�n, etc*/
STATE* returnstate(void);/*Devuelve la direcci�n de inicio del arreglo de estados*/
STATE* getstate2(int x, int y);/*Busca la direccioon del estado en funcion de sus coordenadas*/
void removestate(int, int);/*Elimina un estado, junto a todos los v�nculos que lo involucran*/
void clear_all(void);
int linkcount2 (int x, int y, int x2, int y2);
STATE* statelinked (STATE* clon);
#endif /*LS included*/
