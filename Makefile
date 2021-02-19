all: main.o user.o
	g++ main.o user.o -o bank
	./bank

main.o: main.cpp
	g++ -c main.cpp

user.o: user.cpp user.h
	g++ -c user.cpp

clean:
	rm *.o bank
