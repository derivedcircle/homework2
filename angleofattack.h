#ifndef AOA_H // include guard
#define AOA_H

#include "sensor.h"
// including header file to base class
// part 1.2 code


class Angleofattack : public Sensor
{ // creating the derived angle of attack sensor with base class sensor
public:
  void gatherData() override; // the gather and process data functions for the aoa sensor
  void processData() override;

};

#endif // AOA_H