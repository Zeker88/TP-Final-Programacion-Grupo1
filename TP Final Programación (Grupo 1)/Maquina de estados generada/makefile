Main: Main.o FSM.o FSMtable.o FSM.h FSMtable.h
	gcc Main.o FSM.o FSMtable.o -o Main 
		
Main.o: Main.c
	gcc -c Main.c  FSMtable.h FSM.h

FSM.o: FSM.c FSM.h
	gcc -c FSM.c

FSMtable.o: FSMtable.c FSMtable.h FSM.h
	gcc -c FSMtable.c


