CC = gcc
CFLAGS = -Wall -std=c99
SOURCES = $(wildcard *.c)
OBJETS = $(SOURCES:.c=.o)
EXEC = undead

$(EXEC) : $(OBJETS)
	$(CC) -o $@ $^

depends.txt : $(SOURCES)
	$(CC) -M  $(SOURCES) > depends.txt

include depends.txt

.PHONY : clean apocalypse

clean :
	rm *.o

apocalypse:clean
	rm $(EXEC)
