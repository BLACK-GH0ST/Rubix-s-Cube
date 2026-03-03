// this class is use to keep track of delta time and total time
// of the window and animation of the cube 

#ifndef GAMETIMER_H
#define GAMETIMER_H

// more logic coming 

#pragma once

class RubixCubeTimer
{
public:
	float totalTime()const; // in seconds
	float deltTime()const; // in seconds

	void reset(); // call before message loop
	void start(); // call when unpaused
	void stop(); // call when paused
	void tick(); // call every frame

private:
	RubixCubeTimer();

	__int64 mBaseTime; // time when reset() is called
	__int64 mPauseTime; // total time paused
	__int64 mStopTime; // time when stop() is called
	__int64 mPrevTime; // time when tick() is called last
	__int64 mCurrTime; // time when tick() is called
	
	bool mStopped; // is the timer stopped?, set true when stop() is called

	double mDeltaTime; // time between this frame and previous frame
	double mSecondsPerCount; // convert to seconds

};

#endif // TIMER_H
