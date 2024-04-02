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
		auto startTime =	std::chrono::high_resolution_clock::now();
		//cout << (((robot0.taskComplete && robot1.taskComplete) && (robot2.taskComplete && robot3.taskComplete)) && robot4.taskComplete) << endl;
		while (!(((robot0.taskComplete && robot1.taskComplete) && (robot2.taskComplete && robot3.taskComplete)) && robot4.taskComplete))
		{
			
			thread t1(&Robot::opperate, &robot0);
			thread t2(&Robot::opperate, &robot1);
			thread t3(&Robot::opperate, &robot2);
			thread t4(&Robot::opperate, &robot3);
			thread t5(&Robot::opperate, &robot4);
			
			t1.join();
			t2.join();
			t3.join();
			t4.join();
			t5.join();
			
		}
		auto stopTime =std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::seconds>(stopTime - startTime);
		std::cout << "duration : " << duration.count() <<" seconds" << std::endl;
		
	}
	{
		auto startTime = std::chrono::high_resolution_clock::now();
		part3();
		auto stopTime = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::seconds>(stopTime - startTime);
		std::cout << "duration : " << duration.count() << " seconds" << std::endl;
	}

	{// part 4
		part4();
	}

	return 0;
}