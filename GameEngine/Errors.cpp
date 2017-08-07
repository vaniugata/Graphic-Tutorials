#include "Errors.h"

#include <cstdlib>
#include <iostream>
#include <SDL\SDL.h>

namespace GameEngine
{
	void fatalError(std::string errorString)
	{
		std::cout << errorString << std::endl;
		std::cout << "Press any key to exit..." << std::endl;
		int tmp;
		std::cin >> tmp;
		SDL_Quit();
		exit(69);
	}
}