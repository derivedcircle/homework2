#include "robot.h"
#include <map>
#include <iostream>
#include <mutex>

using namespace std;


mutex m;

bool Robot::tools[] = {true,true,true,true,true};

Robot::Robot(int robNum)
{
	robotID = robNum;
	
	aquiredTools = false;
	taskComplete = false;
	taskTimeCounter = 6;
}

void Robot::collectData()
{
	/*
	Robot 0 can only use tools 0 and 1
	Robot 1 can only use tools 1 and 2
	Robot 2 can only use tools 2 and 3
	Robot 3 can only use tools 3 and 4
	Robot 4 can only use tools 4 and 0
	*/
	
	if (robotID == 4)
	{
		//cout << tools[robotID] << tools[0] << (tools[robotID] && tools[0]) << endl;
		if (tools[robotID] && tools[0])
		{

			tools[robotID] = false, tools[0] = false;

			cout << "robot " << robotID << " is collecting data" << endl;

			aquiredTools = true;
		}
	}
	else
	{
		//cout << tools[robotID] << tools[robotID + 1] << (tools[robotID] && tools[robotID + 1]) << endl;
		if (tools[robotID] && tools[robotID + 1])
		{

			tools[robotID] = false, tools[robotID + 1] = false;

			cout << "robot " << robotID << " is collecting data" << endl;

			aquiredTools = true;
		}
	}
	
}

void Robot::doTask()
{
	
	taskTimeCounter--;

	if (taskTimeCounter == 5)
	{
		cout << "robot " << robotID << " aquired tools and starts performing a task" << endl;
	}
	
	

	if (taskTimeCounter == 0)
	{
		if (robotID == 4)
		{
			

			tools[robotID] = true, tools[0] = true;

			cout << "robot " << robotID << " finished the task and returning the tools" << endl;

			taskComplete = true;
			
		}
		else
		{
			

			tools[robotID] = true, tools[robotID + 1] = true;

			cout << "robot " << robotID << " finished the task and returning the tools" << endl;

			taskComplete = true;
			
		}
	}
}


void Robot::opperate()
{

	
	if (!aquiredTools)
	{
		m.lock();
		collectData();
		m.unlock();
	}
	else if (!taskComplete)
	{
		m.lock();
		doTask();
		m.unlock();
	}
	this_thread::sleep_for(chrono::seconds(1));// one second delay between each action
}