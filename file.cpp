#include "file.hpp"

File::File(std::string all_file)
{
	setAllLine(all_file);
}

File::~File()
{}

std::string	File::getLine(void)
{}

std::vector<std::string>&	File::getAllLine(void)
{
	return (this->_all_line);
}

void	File::setAllLine(std::string file)
{
	std::string line;
	while (file.find('\n') != std::string::npos)
	{
		line = file.substr(0, file.find('\n'));
		file = file.substr(file.find('\n') + 1);
		this->getAllLine().push_back(line);
	}
	line = file.substr(0, file.find("\n"));
	file = file.substr(file.find('\n') + 1);
}
