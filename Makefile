all: main.o user.o session.o
	g++ main.o user.o session.o -o bank
	./bank

main.o: main.cpp
	g++ -c main.cpp

user.o: user.cpp user.h
	g++ -c user.cpp

session.o: session.cpp session.h
	g++ -c session.cpp

clean:
	rm *.o bank
