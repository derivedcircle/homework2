#include "robot.h"
#include <map>
#include <iostream>
#include <mutex>

using namespace std;
// includes all needed header files and sets default namespace as standard for convenience

mutex m; // mutex varible
// static bool array for the entire class showing which tools are available and which are taken, on startup, all tools are available
bool Robot::tools[] = {true,true,true,true,true};

// robot constructor that gets robot id and sets all values properly
Robot::Robot(int robNum)
{
	robotID = robNum;
	
	aquiredTools = false;
	taskComplete = false;
	taskTimeCounter = 6; // it needs to be 6 to account for the fact that there is 1 second to aquire tools and 5 to do task and return tools
}

void Robot::collectData()
{ // function that handles collecting data/aquiring tools (using nomenclature from HW2 packet)
	/*
	Robot 0 can only use tools 0 and 1
	Robot 1 can only use tools 1 and 2
	Robot 2 can only use tools 2 and 3
	Robot 3 can only use tools 3 and 4
	Robot 4 can only use tools 4 and 0
	*/
	
	if (robotID == 4) // specal case for robot id 4 because there is no easy way to handle number wrapping
	{
		
		if (tools[robotID] && tools[0]) // if the tools needed to start are available then robot claims tools and gets to working
		{

			tools[robotID] = false, tools[0] = false;

			cout << "robot " << robotID << " is collecting data" << endl;

			aquiredTools = true;
		}
	}
	else
	{
		
		if (tools[robotID] && tools[robotID + 1]) // if the tools needed to start are available then robot claims tools and gets to working
		{

			tools[robotID] = false, tools[robotID + 1] = false;

			cout << "robot " << robotID << " is collecting data" << endl;

			aquiredTools = true;
		}
	}
	
}

void Robot::doTask()
{
	// function that decriments its counter until the task is complete
	taskTimeCounter--;

	if (taskTimeCounter == 5) // prints once robot has aquired its tools
	{
		cout << "robot " << robotID << " aquired tools and starts performing a task" << endl;
	}
	
	

	if (taskTimeCounter == 0) // this is when the robot is done with its task
	{
		if (robotID == 4) // needed because of difficulty w/ number wrapping
		{
			

			tools[robotID] = true, tools[0] = true; // tools are no longer claimed and the robot is done its task

			cout << "robot " << robotID << " finished the task and returning the tools" << endl;

			taskComplete = true;
			
		}
		else
		{
			

			tools[robotID] = true, tools[robotID + 1] = true; // tools are no longer claimed and the robot is done its task

			cout << "robot " << robotID << " finished the task and returning the tools" << endl;

			taskComplete = true;
			
		}
	}
}


void Robot::opperate() // opperating function desined for multithreading
{

	
	if (!aquiredTools) // if the robot hasnt aquired its tools, it will attempt to aquire them
	{
		m.lock();
		collectData();
		m.unlock();
	}
	else if (!taskComplete) // if the robot hasnt completed its task, it will attempt to
	{
		m.lock();
		doTask();
		m.unlock();
	}
	this_thread::sleep_for(chrono::seconds(1));// one second delay between each action
}