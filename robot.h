#ifndef ROBOT_H // include guard
#define ROBOT_H

// part 2

class Robot
{ // implimenting the robot class
	int robotID; // value for robot id
	
	bool aquiredTools; // checks if the robot has aquired its tools to do its task
	
	int taskTimeCounter; // counts down how long for the robot to do its task
	void collectData(); // function to collect data/ aquire its tools (using naming convention from HW2 packet)
	void doTask(); // function to do the robot's task

public:
	static bool tools[5]; // static class boolean reporting which tools are taken and which ones are free/available
	Robot(int robNum); // constructior that takes in the robot's id number
	bool taskComplete; // reports if the robot is done with it's task
	void opperate(); // a robot operation funciton designed for multithreading
	

};


#endif // ROBOT_H
