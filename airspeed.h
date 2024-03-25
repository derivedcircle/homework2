#ifndef AIRSPEED_H
#define AIRSPEED_H

#include "sensor.h"

// part 1.2

class Airspeed : public Sensor
{
public:
  void gatherData() override;
  void processData() override;

};

#endif // AIRSPEED_H