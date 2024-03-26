#ifndef ROBOT_H
#define ROBOT_H

void part2();

class Robot
{
	int robotID;
	
	bool aquiredTools;
	
	int taskTimeCounter;
	void collectData();
	void doTask();

public:
	static bool tools[5];
	Robot(int robNum);
	bool taskComplete;
	void opperate();
	

};


#endif // ROBOT_H
