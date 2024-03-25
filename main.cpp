#include <iostream>
#include <string>
#include "sensorfactory.h"
#include "aerospacecontrolsystem.h"
#include "altitude.h"
#include "airspeed.h"
#include "angleofattack.h"
#include "sensor.h"
#include <vector>
using namespace std;

int main() {
	{// part 1
		//part 1.5
		Aerospacecontrolsystem ctrlSys;
		ctrlSys.add_sensor(Sensorfactory::createSensor("airspeed"));
		ctrlSys.add_sensor(Sensorfactory::createSensor("altitude"));
		ctrlSys.add_sensor(Sensorfactory::createSensor("angleofattack"));

		ctrlSys.monitor_and_adjust();
	}
	return 0;
}