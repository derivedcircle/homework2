#include <iostream>
#include <string>
#include "sensorfactory.h"
#include "aerospacecontrolsystem.h"
#include "altitude.h"
#include "airspeed.h"
#include "angleofattack.h"
#include "sensor.h"
#include "robot.h"
#include "part3.h"
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

	{// part 2
		

		Robot robot0(0);
		Robot robot1(1);
		Robot robot2(2);
		Robot robot3(3);
		Robot robot4(4);

		// nessisary because when incrimented in the first itteration, the timer starts at 0
		int timer = -1;
		//cout << (((robot0.taskComplete && robot1.taskComplete) && (robot2.taskComplete && robot3.taskComplete)) && robot4.taskComplete) << endl;
		while (!(((robot0.taskComplete && robot1.taskComplete) && (robot2.taskComplete && robot3.taskComplete)) && robot4.taskComplete))
		{
			timer++;
			cout << endl << "time: " << timer << endl;
			robot0.opperate();
			robot1.opperate();
			robot2.opperate();
			robot3.opperate();
			robot4.opperate();
			
			
		}
		
		cout << "duration: " << timer << " seconds" << endl;
	}
	{
		part3();
	}

	{// part 4

	}

	return 0;
}