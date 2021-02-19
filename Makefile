all: main.o user.o admin.o session.o
	g++ main.o user.o admin.o session.o -o bank
	./bank

main.o: main.cpp
	g++ -c main.cpp

user.o: user.cpp user.h
	g++ -c user.cpp

admin.o: admin.cpp admin.h
	g++ -c admin.cpp

session.o: session.cpp session.h
	g++ -c session.cpp

clean:
	rm *.o bank
