#include "sed.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Wrong arguments : [filename] [string to replace] [replacement string]" << std::endl;
		return -1;
	}

	std::string toReplace(av[2]);
	if (toReplace.empty()) {
		std::cout << "String to replace can not be empty" << std::endl;
		return -1;
	}

	std::ifstream	originalFile;
	originalFile.open(av[1], std::ifstream::in);
	if (!originalFile.is_open())
	{
		std::cout << "Wrong filename" << std::endl;
		return -1;
	}
	
	std::ofstream	copyFile;
	std::string		filename(av[1]);
	copyFile.open((filename + ".replace").c_str(), std::ofstream::out);
	if (!copyFile.is_open())
	{
		std::cout << "Wrong filename" << std::endl;
		originalFile.close();
		return -1;
	}

	std::string		strContent;
	while (std::getline(originalFile, strContent))
	{
		copyFile << myReplace(strContent, av[2], av[3]);
	}
	originalFile.close();
	copyFile.close();
	return 0;
}
