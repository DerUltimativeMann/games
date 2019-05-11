# Program Name
PROG = GameEmul

# Compiler C++
CC = g++

# Flags
LF = -lmingw32 -lSDL2main -lSDL2
CF = -Wall -pedantic -ansi

# obj-files
OBJ = main.o map.o

# Binding the Program
$(PROG): $(OBJ)
	$(CC) -o $(PROG) $(OBJ) $(LF)
	rm $(OBJ)

# Compile the code
%.o: src/%.cpp
	$(CC) -c $(CF) $<
