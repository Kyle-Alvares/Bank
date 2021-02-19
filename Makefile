CC=g++
# CFLAGS="-O2" # For optimization purposes, leave alone for now. 
# CXXFLAGS="${CFLAGS}" # Ditto
EXECUTABLE_NAME := bank

all: main.o user.o session.o
	$(CC) main.o user.o session.o -o${EXECUTABLE_NAME}

.PHONY: clean run # Not build targets, mark as .PHONY

run:
	./${EXECUTABLE_NAME}

clean:
	rm -f *.o ${EXECUTABLE_NAME}

main.o: main.cpp
	$(CC) $(CXXFLAGS) -c main.cpp

user.o: user.cpp user.h
	$(CC) $(CXXFLAGS) -c user.cpp

session.o: session.cpp session.h
	$(CC) $(CXXFLAGS) -c session.cpp
