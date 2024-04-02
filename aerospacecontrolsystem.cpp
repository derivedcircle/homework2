#include "aerospacecontrolsystem.h"
#include <vector>
#include <iostream>

using namespace std;
// getting all needed header file and setting default namespace as standard for convenience
// part 1.4 code

void Aerospacecontrolsystem::add_sensor(Sensor* sen)
{ // fuction that adds a sensor pointer to a vector holding them
  sensors.push_back(sen);
}

void Aerospacecontrolsystem::monitor_and_adjust()
{ // function that runs throguh all stored sensors and runs their gather and process data functions
  for (auto& sensor : sensors)
    {
      sensor->gatherData();
      sensor->processData();
    }
  cout << "Adjusting controls based on sensor data." << endl << endl; // prints this line at end
}

Aerospacecontrolsystem::~Aerospacecontrolsystem()
{ // destructor used to destroy all sensors stored in heap memory for memory safety
    for (auto& sensor : sensors)
    {
        delete[] sensor;
    }

}