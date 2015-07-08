#ifndef FSM_H_
#define FSM_H_


#define FIN_TABLA 0


typedef struct tabla_estado STATE;

struct tabla_estado

{
	char evento;
    	STATE* nextstate;
    	void (*rutaction) (void);
};

// Interfaz //

STATE* myfsm (STATE* statep, char event);

#endif /* FSM_H_ */
