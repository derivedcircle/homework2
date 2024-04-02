#ifndef AIRSPEED_H // include guard
#define AIRSPEED_H

#include "sensor.h"
// including header file to base class
// part 1.2 code

class Airspeed : public Sensor
{ // creating the derived airspeed sensor with base class sensor
public:
  void gatherData() override; // the gather and process data functions for the airspeed sensor
  void processData() override;

};

#endif // AIRSPEED_H