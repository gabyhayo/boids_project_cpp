#ifndef __TIMER_H
#define __TIMER_H

#include <glut.h>

class Timer{
private:
	int epoch;
	int lastTick;
	int delta;
public:
	static Timer* tr;
	int getEpoch();
	int getLastTick();
	int getDelta();
	void update();
};



#endif