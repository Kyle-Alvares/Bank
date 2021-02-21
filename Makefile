CC=g++
CFLAGS=-g -O2 # For optimization purposes, leave alone for now. 
CXXFLAGS=${CFLAGS} 
EXECUTABLE_NAME := bank

all: main.o user.o session.o login.o withdraw.o
	$(CC) main.o user.o session.o login.o -o${EXECUTABLE_NAME}

.PHONY: clean run # Not build targets, mark as .PHONY

run:
	./${EXECUTABLE_NAME}

clean:
	rm -f *.o ${EXECUTABLE_NAME}

main.o: main.cpp
	$(CC) $(CXXFLAGS) -c main.cpp

user.o: user.h user.cpp 
	$(CC) $(CXXFLAGS) -c user.cpp

session.o: session.h session.cpp 
	$(CC) $(CXXFLAGS) -c session.cpp

login.o: login.h login.cpp 
	$(CC) $(CXXFLAGS) -c login.cpp

withdraw.o: withdraw.h withdraw.cpp
	$(CC) $(CXXFLAGS) -c withdraw.cpp
