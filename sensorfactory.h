#ifndef SENSORFACTORY_H // include guard
#define SENSORFACTORY_H
#include <string>
#include "sensor.h"
// including all needed header files
// part 1.3 code

class Sensorfactory
{ // setting up sensorfactor class that constructs a sensor in heap memory and can send a pointer to that sensor depending on which sensor is requested
public:
  static Sensor* createSensor(std::string sensorType);

};

#endif // SENSORFACTORY_H