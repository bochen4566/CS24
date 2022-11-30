all: test
	./test
	
test: test.cpp intbst.cpp
	g++ -std=c++11 -O0 -g test.cpp intbst.cpp -o test

clean:
	rm test