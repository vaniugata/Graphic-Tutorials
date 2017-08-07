#pragma once
namespace GameEngine
{
	class FpsLimiter
	{
	public:
		FpsLimiter();
		void init(float maxFps);

		void setMaxFPS(float maxFps);

		void begin();

		// return current FPS
		float end();
	private:
		void calculateFPS();

		float _fps;
		float _maxFps;
		float _frameTime;
		unsigned int _startTicks;
	};
}