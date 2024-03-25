#ifndef AOA_H
#define AOA_H

#include "sensor.h"

// part 1.2


class Angleofattack : public Sensor
{
public:
  void gatherData() override;
  void processData() override;

};

#endif // AOA_H