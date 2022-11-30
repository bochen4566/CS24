all: testbst
	./testbst
	
testbst: testbst.cpp bst.cpp bst.h
	g++ -std=c++11 -O0 -g testbst.cpp bst.cpp bst.h -o testbst

clean:
	rm testbst