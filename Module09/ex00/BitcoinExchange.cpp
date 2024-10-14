#include "BitcoinExchange.hpp"

static	void	dataBaseParsing(std::ifstream& inputFile, std::map<std::string, float>& dataBase);
static	void	manageInputDatas(std::ifstream& inputFile, std::map<std::string, float>& dataBase);
static	bool	checkDate(std::string stringDate);	
static unsigned int lineNb = 0;	

void    openFile(char *file) {
	std::ifstream	inputFile;
	std::ifstream	dataBaseFile;
    std::string		fileName;
    std::string		line;

	try
	{
		fileName = file;
		inputFile.open(file);
		if (inputFile.fail())
			throw OpenFileException();
		fileName = "data.csv";
		dataBaseFile.open("data.csv");
		if (dataBaseFile.fail()) {
			inputFile.close();
			throw OpenFileException();
		}
	}
	catch(const std::exception& e) {
		std::cout << e.what() << std::endl;
		return ;
	}
	
	std::map<std::string, float>	data;
	{
		try	
		{
			dataBaseParsing(dataBaseFile, data);
		}
		catch(const std::exception& e) {
			inputFile.close();
			dataBaseFile.close();
			std::cout << e.what() << std::endl;
			return ;
		}
	}

	{
		manageInputDatas(inputFile, data);
	}

	inputFile.close();
	dataBaseFile.close();	
    return ;
}

//data.csv parsing
void	dataBaseParsing(std::ifstream& dataBaseFile, std::map<std::string, float>& dataBase){
	std::string line;
	std::string	date;
	std::string	value;
	float		floatValue;
	char*		restValue;
	size_t		comma;

	lineNb = 0;

	int	firstLine;
	if (!dataBaseFile.eof()) {
			getline(dataBaseFile, line);
			firstLine = line.compare("date,exchange_rate");
			if (firstLine != 0) 
				throw InvalidDataBaseException();		
	}
	while (!dataBaseFile.eof()){
			getline(dataBaseFile, line);
			lineNb++;
			if (line.empty() && dataBaseFile.eof())
				continue;
			if (line.empty())
				throw InvalidDataBaseException();

			comma = line.find_last_of(",");
			if (comma > 10)
				throw InvalidDataBaseException();
			date = line.substr(0, comma);
			if (date == "date" && lineNb == 1)
				continue;
			if (comma < 10)
				throw InvalidDataBaseException();
			if (checkDate(date) == false)
				throw InvalidDateException();

			value = line.substr(comma + 1);
			if (!isdigit(value[0]) && value[0] != '-')
				throw InvalidDataBaseException();
			floatValue = strtof(value.c_str(), &restValue);
			if (floatValue < 0)
				throw InvalidDataBaseException();
			if (strlen(restValue))
				throw InvalidDataBaseException();
				
			std::map<std::string, float>::iterator it = dataBase.begin();
			dataBase.insert(it, std::pair<std::string, float>(date, floatValue));
	}

	if (dataBase.begin() == dataBase.end())
		throw InvalidDataBaseException();
}

//input.txt parsing
void	manageInputDatas(std::ifstream& inputFile, std::map<std::string, float>& dataBase){

	std::string	line;
	lineNb = 0;

	if (!inputFile.eof()) {
		try
		{
			getline(inputFile, line);
			int	firstLine;
			firstLine = line.compare("date | value");
			if (firstLine != 0) 
				throw InvalidFormatException();
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << " => '" << line << "'" << std::endl;
		}			
	}

	std::string date;
	std::string value;
	size_t		pipe;
	float		floatValue;
	char*		restValue;
	while (!inputFile.eof()){
		try
		{
			getline(inputFile, line);
			lineNb++;
			if (line.empty() && inputFile.eof())
				continue;
			if (line.empty())
				throw InvalidFormatException();
			
			pipe = line.find_last_of("|");
			if (pipe > 11)
				throw BadInputException();
			date = line.substr(0, pipe);
			if (date == "date " && lineNb == 1)
				continue;
			pipe = line.find_last_of(" | ");
			date = line.substr(0, pipe - 2);
			if (pipe <= 11)
				throw InvalidFormatException();
			if (checkDate(date) == false)
				throw InvalidDateException();

			value = line.substr(pipe + 1);
			if (!isdigit(value[0]) && value[0] != '-')
				throw InvalidValueException();
			floatValue = strtof(value.c_str(), &restValue);
			if (floatValue > 1000)
				throw ValueTooLargeException();
			if (floatValue < 0)
				throw ValueNegException();
			if (strlen(restValue))
				throw InvalidFormatException();
			
			std::map<std::string, float>::iterator it = dataBase.lower_bound(date);
			if (it == dataBase.begin() && date < dataBase.begin()->first)
				throw InvalidDateException();
			if (it != dataBase.begin() && it != dataBase.end() && it->first != date)
				it--;

			std::cout << date << " => " << value << " = " << it->second * floatValue << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << " => '" << line << "'" << std::endl;
		}
	}
}

//function that check if the format of the date is valid : YYYY-MM-DD
bool	checkDate(std::string date) {
	long		mounth;
	int			days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	std::string	bigDate;
	bigDate = date.substr(0, date.find('-'));
	long		tmp;
	char		*cmp;
	tmp = std::strtol(bigDate.c_str(), &cmp, 10);
	if (cmp==bigDate || tmp < 2009 || tmp > 2025)
		return false;
	if ((tmp%4 == 0 && tmp%100 != 0) ||tmp%400 == 0)
		days[1]++;
	bigDate = date.substr(bigDate.length() + 1, date.find("-") - 1);
	mounth = std::strtol(bigDate.c_str(), &cmp, 10);
	if (cmp==bigDate || mounth > 12 || mounth < 1)
		return false;
	bigDate = date.substr(date.substr(0, date.find("-")).length() + 1 + bigDate.length(), date.find(" ") - 1);
	tmp = std::strtol(bigDate.c_str(), &cmp, 10);
	if (cmp==bigDate || tmp < 1 || tmp > days[mounth-1])
		return false;
	return true;
}
