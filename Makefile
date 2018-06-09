CC = g++
CCFLAGS = -g
OBJ = current.o

current : $(OBJ)
	$(CC) -o $@ $< $(CCFLAGS)

current.o : current.cpp
	$(CC) -c -o $@ $< $(CCFLAGS)

clean:
	rm -rf *.o *~ current
