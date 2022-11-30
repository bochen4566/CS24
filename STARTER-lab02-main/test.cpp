#include <iostream>
#include "car.hpp"
#include <cstdint>
#include <cstring>
using namespace std;

int main(){
    //char* a = new char;
    //strcpy(a, "Audi");
    //char* b = new char;
    //strcpy(b, "r8");
    //string manu = "audi";
    //string model = "r8";
    const char *a = "manu";
    const char* b = "model";

    PerformanceStats per(100, 100, 0.5);
    uint8_t s = 4;
    DoorKind d = Hinge;
    Car audi(a, b, per, s, d);
    cout << *a << endl;
    cout << *b << endl;
    cout<< audi.getBackseatDoors() <<"d" << endl;
    cout << audi.getManufacturer() << "a" << endl;
    cout << audi.getModel() << "b" << endl;
    cout << audi.getSeatCount() << "s" << endl;

    return 0;
};