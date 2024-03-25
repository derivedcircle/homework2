#ifndef ALTITUDE_H
#define ALTITUDE_H

#include "sensor.h"

// part 1.2

class Altitude : public Sensor
{
public:
  void gatherData() override;
  void processData() override;

};

#endif // ALTITUDE_H