#ifndef ACS_H
#define ACS_H

#include "sensor.h"
#include "altitude.h"
#include "airspeed.h"
#include "angleofattack.h"
#include <vector>
#include <iostream>

using namespace std;

// part 1.4
class Aerospacecontrolsystem
{
	vector<Sensor*> sensors;

public:
	
	void add_sensor(Sensor* sensor);
	void monitor_and_adjust();
	~Aerospacecontrolsystem();
};

#endif // ACS_H