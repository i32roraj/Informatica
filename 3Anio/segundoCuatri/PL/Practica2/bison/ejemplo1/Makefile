VERSION=1
FUENTE = ejemplo$(VERSION)
LEXICO = lexico$(VERSION)

CC = gcc
CFLAGS = -c -g 
YFLAGS = -d    # Generar el fichero $(FUENTE).tab.h 
LFLAGS = -lfl 
OBJS= $(FUENTE).tab.o lex.yy.o 

(FUENTE).exe : $(OBJS) 
	$(CC) $(OBJS) $(LFLAGS) -o $(FUENTE).exe 

lex.yy.o:  lex.yy.c $(FUENTE).tab.h $(FUENTE).h
	$(CC) $(CFLAGS) lex.yy.c 

lex.yy.c: $(LEXICO).l $(FUENTE).tab.h  $(FUENTE).h 
	flex $(LEXICO).l

$(FUENTE).tab.o: $(FUENTE).tab.c  $(FUENTE).tab.h   $(FUENTE).h
	$(CC) $(CFLAGS)  $(FUENTE).tab.c

$(FUENTE).tab.c $(FUENTE).tab.h:  $(FUENTE).y $(FUENTE).h 
	bison $(YFLAGS) $(FUENTE).y

#Opcion para borrar los ficheros auxiliares y los objetos
clean: 
	rm  -f $(OBJS) $(FUENTE).tab.[ch] lex.yy.c $(FUENTE).exe

