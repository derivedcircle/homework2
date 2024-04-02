#ifndef ACS_H // include guard
#define ACS_H

#include "sensor.h"
#include "altitude.h"
#include "airspeed.h"
#include "angleofattack.h"
#include <vector>
#include <iostream>

using namespace std;
// inlcuding all needed libraries a setting default namespace as standard for convenince

// part 1.4 code
class Aerospacecontrolsystem
{
	vector<Sensor*> sensors; // vector that holds all of the pointers to the sensors 

public:
	
	void add_sensor(Sensor* sensor); // function to add sensors to the vector
	void monitor_and_adjust(); // function that runs through each sensor's gather and process data functions
	~Aerospacecontrolsystem(); // destructor used to prevent memory leaks
};

#endif // ACS_H