#ifndef SENSORFACTORY_H
#define SENSORFACTORY_H
#include <string>
#include "sensor.h"

// part 1.3

class Sensorfactory
{
public:
  static Sensor* createSensor(std::string sensorType);

};

#endif // SENSORFACTORY_H