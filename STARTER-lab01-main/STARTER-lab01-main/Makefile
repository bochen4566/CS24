CXX = g++
#CXX = clang++

CXXFLAGS = -Wall -Wno-uninitialized

BINARIES= llTests
SRCDIR = D:\mycode\cs24\STARTER-lab01-main\STARTER-lab01-main
COMMON_OBJECT_FILES = linkedListFuncs.o moreLinkedListFuncs.o tddFuncs.o

all: ${BINARIES}

tests: ${BINARIES}
	./llTests 1
	./llTests 2
	./llTests 3
	./llTests 4
	./llTests 5
	./llTests 6
	./llTests 7

llTests: llTests.o ${COMMON_OBJECT_FILES}
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o
