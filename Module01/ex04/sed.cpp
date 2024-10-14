#include "sed.hpp"

std::string	myReplace(std::string str, std::string s1, std::string s2)
{
	size_t		lenToFind = s1.length();
	size_t		lenToReplace = s2.length();
	size_t		istr = 0;

	while (str.find(s1) != std::string::npos && istr < str.length())
	{
		istr = str.find(s1);
		str.erase(istr, lenToFind);
		str.insert(istr, s2);
		istr += lenToReplace;
	}
	return str;
}
