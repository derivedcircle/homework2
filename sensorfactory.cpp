#include "sensorfactory.h"
#include <iostream>
#include <string>
#include "sensor.h"
#include "altitude.h"
#include "airspeed.h"
#include "angleofattack.h"

using namespace std;

// part 1.3

Sensor* Sensorfactory::createSensor(std::string sensorType)
{
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
    return nullptr;
  }
    
}