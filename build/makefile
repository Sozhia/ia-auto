CC=g++
CFLAGS=-I.
DEPS = ../include/*.cpp
OBJ = ../src/main.o

%.o:  %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf ../src/*o main *.txt