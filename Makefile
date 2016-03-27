all:
	g++ -c -o main.o main.cpp -I.
	g++ -c -o amath-ng.o amath-ng.cpp -I.
	g++ -c -o ops/quadratic.o ops/quadratic.cpp -I.
	g++ -c -o ops/vertex.o ops/vertex.cpp -I.
	g++ -o amath-ng main.o amath-ng.o ops/quadratic.o ops/vertex.o -lboost_system -lboost_random -lboost_thread -lgmp -std=c++14

clean:
	rm *.o
	rm ops/*.o

install:
	install amath-ng /usr/local/bin
