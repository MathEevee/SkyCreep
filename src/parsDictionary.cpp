#include "parsDictionary.hpp"

std::map<std::string, std::string> set_dictionary(void)
{
	std::ifstream	input;
	std::string		str_out;
	std::string		tmp;
	std::map<std::string, std::string> dictionary;
	ssize_t			pos;
	
	input.open("dictionary.txt", std::fstream::in);
	if (input.is_open() == 0)
	{
		std::cout << "Failed with dictionary." << std::endl;
		exit(-1);
	}
	while (getline(input, str_out, '\n'))
	{
		tmp = str_out;
		pos = str_out.find("| ");
		str_out = str_out.substr(pos + 2);
		dictionary[str_out] = tmp.substr(0, pos);
	}
	input.close();
	return (dictionary);
}
