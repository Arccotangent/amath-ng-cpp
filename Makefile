all:
	g++ -c main.cpp
	g++ -c amath-ng.cpp
	g++ -o amath-ng amath-ng.o main.o -lboost_system -lboost_random -lboost_thread -lgmp -std=c++14

clean:
	rm *.o
	rm amath-ng

install:
	cp amath-ng /usr/local/bin
