// name(s) and Perm 
// This is the only file to submit.
//Bochen Wang 8344863

#include "car.hpp"
#include <cstddef>
#include <cstring>
#include "perf.hpp"
//#include <iostream>


using namespace std;

Car::Car(){
        //manufacturer = new char;
        manufacturer = nullptr;
        //model = new char;
        model = nullptr;
        zeroToSixtyNs = 0;
        headonDragCoeff = 0;
        horsepower = 0;
        backseatDoors = None;
        seatCount = 0;
};

Car::Car(char const* const manufacturerName, char const* const modelName, PerformanceStats perf, uint8_t numSeats, DoorKind backseatDoorDesign){
        char* p = new char;
        strcpy(p, manufacturerName);
        manufacturer = p;

        //manufacturer = new char;
        //strcpy(manufacturer, manufacturerName);
        
        //model = new char;
        //strcpy(model, modelName);
        char* q = new char;
        strcpy(q, modelName);
        model = q;
        zeroToSixtyNs = perf.zeroToSixtyNs;
        headonDragCoeff = perf.headonDragCoeff;
        horsepower = perf.horsepower;
        backseatDoors = backseatDoorDesign;
        seatCount = numSeats;
};

Car::Car(Car const& o){
    //this->manufacturer = new char;
    //strcpy(manufacturer, o.getManufacturer());
    //this->model = new char;
    //strcpy(model, o.getModel());
    char* p = new char;
    strcpy(p, o.getManufacturer());
    this->manufacturer = p;
    
    char* q = new char;
    strcpy(q, o.getModel());
    model = q;

    this->zeroToSixtyNs = o.zeroToSixtyNs;
    this->headonDragCoeff = o.headonDragCoeff;
    this->horsepower = o.horsepower;
    this->backseatDoors = o.backseatDoors;
    this->seatCount = o.seatCount;
};

Car& Car::operator=(Car const& o){
    //manufacturer = new char;
    //strcpy(manufacturer, o.getManufacturer());
    //model = new char;
    //strcpy(model, o.getModel());
    //zeroToSixtyNs = o.zeroToSixtyNs;
    //headonDragCoeff = o.headonDragCoeff;
    //horsepower = o.horsepower;
    //backseatDoors = o.backseatDoors;
    //seatCount = o.seatCount;
    
    Car a(o);
    return a;
};

Car::~Car(){
    
    //delete manufacturer;
    //delete model;
};

char const* Car::getManufacturer() const{
    return manufacturer;
};

char const* Car::getModel() const{
    return model;
};

PerformanceStats Car::getStats() const{
    return PerformanceStats(horsepower, zeroToSixtyNs, headonDragCoeff);
};

uint8_t Car::getSeatCount() const{
    return seatCount;
};

DoorKind Car::getBackseatDoors() const{
    return backseatDoors;
};

void Car::manufacturerChange(char const* const newManufacturer){
    char* p = new char;
    strcpy(p, newManufacturer);
    manufacturer = p;
    //manufacturer = new char;
    //strcpy(manufacturer, newManufacturer);
};

void Car::modelNameChange(char const* const newModelName){
        char* q = new char;
        strcpy(q, newModelName);
        model = q;    
    //model = new char;
    //strcpy(model, newModelName);
};

void Car::reevaluateStats(PerformanceStats newStats){
    zeroToSixtyNs = newStats.zeroToSixtyNs;
    headonDragCoeff = newStats.headonDragCoeff;
    horsepower = newStats.horsepower;
};

void Car::recountSeats(uint8_t newSeatCount){
    seatCount = newSeatCount;
};

void Car::reexamineDoors(DoorKind newDoorKind){
    backseatDoors = newDoorKind;
};



//int main(){
//    //char* a = new char;
//    //strcpy(a, "Audi");
//    //char* b = new char;
//    //strcpy(b, "r8");
//    //string manu = "audi";
//    //string model = "r8";
//    const char *a = "manu";
//    const char* b = "model";
//
//    PerformanceStats per(100, 100, 0.5);
//    uint8_t s = 4;
//    DoorKind d = Hinge;
//    Car audi(a, b, per, s, d);
//    //cout << *a << endl;
//    //cout << *b << endl;
//    //cout<< audi.getBackseatDoors() <<"d" << endl;
//    //cout << audi.getManufacturer() << "a" << endl;
//    //cout << audi.getModel() << "b" << endl;
//    //cout << audi.getSeatCount() << "s" << endl;
//    //cout << audi.getStats().headonDragCoeff << " " << audi.getStats().horsepower<< " " << audi.getStats().zeroToSixtyNs;
//    //cout << endl;
//    Car audi2 = audi;
//    
//
//    cout<< audi2.getBackseatDoors() <<"d" << endl;
//    cout << audi2.getManufacturer() << "a" << endl;
//    cout << audi2.getModel() << "b" << endl;
//    cout << audi2.getSeatCount() << "s" << endl;
//    cout << audi2.getStats().headonDragCoeff << " " << audi.getStats().horsepower<< " " << audi.getStats().zeroToSixtyNs;
//    cout << endl;
//    return 0;
//};
