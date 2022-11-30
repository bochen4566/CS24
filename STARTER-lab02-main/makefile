all: car
	./car
	
car: car.cpp car.hpp  doors.hpp perf.cpp perf.hpp
	g++ -std=c++11 -O0 -g car.cpp -o test

clean:
	rm car