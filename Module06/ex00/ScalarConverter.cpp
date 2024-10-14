#include "ScalarConverter.hpp"

////////// CONSTRUCTORS /////////////////////////////////////////////
ScalarConverter::ScalarConverter() {
}
ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
    (void)copy;
}

////////// DESTRUCTOR ///////////////////////////////////////////////
ScalarConverter::~ScalarConverter() {
}

////////// OPERATOR /////////////////////////////////////////////////
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) {
    (void)copy;
    return *this;
}

////////// FUNCTIONS ////////////////////////////////////////////////
bool    isChar(std::string str)
{
    int len = str.length();
    if (len == 0 || (len == 1 && !isdigit(str[0])))
        return true;
    return false;
}
bool    isInt(std::string str)
{
    if (!isdigit(str[0]) && str[0] != '-' && str[0] != '+')
        return false;
    if ((str[0] == '-' || str[0] == '+') && str.length() <= 1)
        return false;
    int i = 0;
    if (str.c_str()[0] == '-' || str.c_str()[0] == '+')
        i++;
    while (str.c_str()[i] && isdigit(str.c_str()[i]))
        i++;
    int len = str.length();
    if (i == len && (strtol(str.c_str(), NULL, 10) >= -2147483648) && (strtol(str.c_str(), NULL, 10) <= 2147483647))
        return true;
    return false;
}
bool    isFloat(std::string str)
{
    char    *tod;
    std::strtod(str.c_str(), &tod);
    int     len = str.length();
    if ((len>=3 && tod[0] == 'f' && tod[1] == '\0' && (int)(str.find(".")) != -1) || str == "nanf" || str == "-inff" || str == "+inff")
        return true;
    return false;
}
bool    isDouble(std::string str)
{
    char    *tod;
    std::strtod(str.c_str(), &tod);
    int len = str.length();
    if (((len>=2 && tod[0] == '\0') && (int)(str.find(".")) != -1) || str == "nan" || str == "-inf" || str == "+inf")
        return true;
    return false;
}
int defineType(std::string str)
{
    if (isChar(str) == true)
        return CHAR;
    if (isInt(str) == true)
        return INT;
    if (isFloat(str) == true)
        return FLOAT;
    if (isDouble(str) == true)
        return DOUBLE;
    return -1;
}
void    ScalarConverter::convert(std::string str)
{
    int scalarType = defineType(str);
    if (isFloat(str) == false && (strtol(str.c_str(), NULL, 10) < -2147483648 || strtol(str.c_str(), NULL, 10) > 2147483647)) {
        scalarType = DOUBLE;
    }
    char    c;
    int     i;
    float   f;
    double  d;

    switch (scalarType)
    {
        case CHAR:
        {
            c = str.c_str()[0];
            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
            break;
        }
        case INT:
        {
            i = strtol(str.c_str(), NULL, 10);
            c = static_cast<char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
            break;
        }
        case FLOAT:
        {
            f = strtof(str.c_str(), NULL);
            c = static_cast<char>(f);
            i = static_cast<int>(f);
            d = static_cast<double>(f);
            break;
        }
        case DOUBLE:
        {
            d = strtod(str.c_str(), NULL);
            c = static_cast<char>(d);
            i = static_cast<int>(d);
            f = static_cast<float>(d);
            break;
        }
        default:
        {
            std::cout << "The type conversion is impossible" << std::endl;
            return;
        }
    }
    // char
    if (d<0 || d>127 || std::isnan(d))
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(c) != false)
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    //int
    if (d<-2147483648 || d>2147483647 || std::isnan(d))
        std::cout << "int: overflow" << std::endl;
    else if (std::isnan(d))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    //float-double
    int end = 1;
    if ((int)(str.find(".")) != -1) {
        end = -1;
        int indexFloat = str.find(".");
        while (str[indexFloat] && str[indexFloat+1]) {
            indexFloat++;
            end++;
        }
    }
    if (isDouble(str) == false) {
        std::cout << "float: " << std::fixed << std::setprecision(end) << f << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(end) << d << std::endl;
    }
    else {
        end++;
        std::cout << "float: " << std::fixed << std::setprecision(end) << f << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(end) << d << std::endl;
    }
}
