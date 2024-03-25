#include "aerospacecontrolsystem.h"
#include <vector>
#include <iostream>

using namespace std;

// part 1.4

void Aerospacecontrolsystem::add_sensor(Sensor* sen)
{
  sensors.push_back(sen);
}

void Aerospacecontrolsystem::monitor_and_adjust()
{
  for (auto& sensor : sensors)
    {
      sensor->gatherData();
      sensor->processData();
    }
  cout << "Adjusting controls based on sensor data." << endl;
}

Aerospacecontrolsystem::~Aerospacecontrolsystem()
{
    for (auto& sensor : sensors)
    {
        delete[] sensor;
    }

}