#include "sensorfactory.h"
#include <iostream>
#include <string>
#include "sensor.h"
#include "altitude.h"
#include "airspeed.h"
#include "angleofattack.h"

using namespace std;
// includes all needed header files and sets default namespace as standard for convenience
// part 1.3

Sensor* Sensorfactory::createSensor(std::string sensorType) // function that outputs a pointer to a sensor stored in heap memory
{ //based on what is requested by the user

  if (sensorType == "altitude")
  {
    return new Altitude();
  }
  else if (sensorType == "airspeed")
  {
    return new Airspeed();
  }
  else if (sensorType == "angleofattack")
  {
    return new Angleofattack();
  }
  else
  {
    return nullptr; // returns nullpointer if no valid text input is provided
  }
    
}