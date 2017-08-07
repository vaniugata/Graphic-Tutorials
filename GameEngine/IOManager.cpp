#include "IOManager.h"

#include <fstream>

namespace GameEngine
{
	bool IOManager::readFileToBuffer(std::string filePath, std::vector<unsigned char> &buffer)
	{
		std::ifstream file(filePath, std::ios::binary);
		if (file.fail())
		{
			perror(filePath.c_str());
			return false;
		}

		//seek to the end
		file.seekg(0, std::ios::end);

		int fileSize = file.tellg(); // in bytes
		file.seekg(0, std::ios::beg);

		//Reduce the file size by any header bytes that might be present
		fileSize -= file.tellg();

		buffer.resize(fileSize);
		file.read((char*)&buffer[0], fileSize);
		file.close();

		return true;
	}
}