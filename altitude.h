#ifndef ALTITUDE_H // include guard
#define ALTITUDE_H

#include "sensor.h"
// including header file to base class
// part 1.2 code

class Altitude : public Sensor
{ // creating the derived altitude sensor with base class sensor
public:
  void gatherData() override; // the gather and process data functions for the altitude sensor
  void processData() override;

};

#endif // ALTITUDE_H