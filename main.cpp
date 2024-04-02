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
#include "part4.h"
#include <thread>
#include <vector>
using namespace std;
// including all of our header files and all needed standard libraries and seting namespace as standard for convenience


int main() {
	{// part 1
		//part 1.5 code
		Aerospacecontrolsystem ctrlSys; // initializes a control systems object
		// adds an airspeed, altitude and aoa sensor using the sensorfactory class to create the objects
		ctrlSys.add_sensor(Sensorfactory::createSensor("airspeed"));
		ctrlSys.add_sensor(Sensorfactory::createSensor("altitude"));
		ctrlSys.add_sensor(Sensorfactory::createSensor("angleofattack"));

		// runs the gather and process data commands for the all sensors stored in ctrlSys
		ctrlSys.monitor_and_adjust();
	}// The ctrlSys's destructor runs here to delete all of the pointers to heap memory and prevent memory leak 

	{// part 2
		
		// initializing all 5 robots for factory line
		Robot robot0(0);
		Robot robot1(1);
		Robot robot2(2);
		Robot robot3(3);
		Robot robot4(4);

		// starts timer
		auto startTime =	std::chrono::high_resolution_clock::now();

		// begens loop to run the robot commands using 5 different threads - loop completes when all 5 robots are done
		while (!(((robot0.taskComplete && robot1.taskComplete) && (robot2.taskComplete && robot3.taskComplete)) && robot4.taskComplete))
		{
			
			jthread t1(&Robot::opperate, &robot0);
			jthread t2(&Robot::opperate, &robot1);
			jthread t3(&Robot::opperate, &robot2);
			jthread t4(&Robot::opperate, &robot3);
			jthread t5(&Robot::opperate, &robot4);
			
			
		}
		// stops timer
		auto stopTime =std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::seconds>(stopTime - startTime);
		std::cout << "duration : " << duration.count() <<" seconds" << std::endl;
		// outputs how long this took
	}
	{// part 3
		// starts timer, runs code for part 3, and ends timer before displaying how long it took to run the program
		auto startTime = std::chrono::high_resolution_clock::now();
		part3();
		auto stopTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::seconds>(stopTime - startTime);
		std::cout << "duration : " << duration.count() << " seconds" << std::endl;
	}

	{// part 4
		// runs part 4 code
		part4();
	}

	return 0;
}