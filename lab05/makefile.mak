all: test
	./test
	
test: test.cpp intbst.cpp intbst.h
	g++ -std=c++11 -O0 -g test.cpp -o test

clean:
	rm test