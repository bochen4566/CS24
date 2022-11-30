all: evalfull
	./evalfull
	
evalfull: evalfull.cpp
	g++ -std=c++11 -O0 -g evalfull.cpp -o evalfull

clean:
	rm evalfull