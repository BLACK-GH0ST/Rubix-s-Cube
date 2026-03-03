
#include "RubixCubeTimer.h"
#include "RubixCubeUtil.h"

RubixCubeTimer::RubixCubeTimer()
	: mBaseTime(0), mPauseTime(0), mStopTime(0),
	mPrevTime(0), mCurrTime(0), mStopped(false),
	mDeltaTime(-1.0), mSecondsPerCount(0.0)
{
	__int64 countsPerSec;
	QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
	mSecondsPerCount = 1.0 / (double)countsPerSec;
}



float RubixCubeTimer::totalTime() const
{
	if( mStopped ) {
		return (float) (((mStopTime - mPauseTime) - 
			mBaseTime) * mSecondsPerCount);
	} else {
		return (float) (((mCurrTime-mPauseTime) -
			mBaseTime) * mSecondsPerCount);
	}
}

float RubixCubeTimer::deltTime() const
{
	return static_cast<float>(mDeltaTime);
}

void RubixCubeTimer::reset() {
	__int64 currTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&currTime);

	mBaseTime = currTime;
	mPrevTime = currTime;
	mStopTime = 0;
	mStopped = false;
}

void RubixCubeTimer::start () { 
	__int64 startTime;
	QueryPerformanceCounter((LARGE_INTEGER*)& startTime);

	if (mStopped) {
		mPauseTime += (startTime - mStopTime);

		mPrevTime = startTime;
		mStopTime = 0;
		mStopped = false;
	}
}

void RubixCubeTimer::stop() {
	if (!mStopped) {
		__int64 currTime;
		QueryPerformanceCounter((LARGE_INTEGER*)&currTime);
		mStopTime = currTime;
		mStopped = true;
	}
}

void RubixCubeTimer::tick() {	

	__int64 currTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&currTime);
	mCurrTime = currTime;
	mDeltaTime = (mCurrTime - mPrevTime) * mSecondsPerCount;
	mPrevTime = currTime;

	if(mDeltaTime < 0.0) { 
		mDeltaTime = 0.0;
		}
	} 