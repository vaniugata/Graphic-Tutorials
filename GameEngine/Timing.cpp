#include "Timing.h"
#include <SDL/SDL.h>

namespace GameEngine
{
	FpsLimiter::FpsLimiter()
	{

	}
	void FpsLimiter::init(float maxFps)
	{
		setMaxFPS(maxFps);
	}

	void FpsLimiter::setMaxFPS(float maxFps)
	{
		_maxFps = maxFps;
	}

	void FpsLimiter::begin()
	{
		_startTicks = SDL_GetTicks();
	}

	// return current FPS
	float FpsLimiter::end()
	{
		calculateFPS();

		float frameTicks = SDL_GetTicks() - _startTicks;
		//Limit the FPS to max FPS
		if (1000.0f / _maxFps > frameTicks)
		{
			SDL_Delay((Uint32)(1000.0f / _maxFps - frameTicks));
		}

		return _fps;
	}

	void FpsLimiter::calculateFPS()
	{
		static const int NUM_SAMPLES = 10;
		static float frameTimes[NUM_SAMPLES];
		static int currentFrame = 0;

		static float prevTicks = SDL_GetTicks();

		float currentTicks;
		currentTicks = SDL_GetTicks();

		_frameTime = currentTicks - prevTicks;
		frameTimes[currentFrame % NUM_SAMPLES] = _frameTime;

		prevTicks = currentTicks;

		int count;

		currentFrame++;
		if (currentFrame < NUM_SAMPLES)
		{
			count = currentFrame;
		}
		else
		{
			count = NUM_SAMPLES;
		}

		float frameTimeAverage = 0;
		for (int i = 0; i < count; i++)
		{
			frameTimeAverage += frameTimes[i];
		}
		frameTimeAverage /= count;

		if (frameTimeAverage > 0)
		{
			_fps = 1000.0f / frameTimeAverage;
		}
		else
		{
			_fps = 60.0f;
		}
	}
}