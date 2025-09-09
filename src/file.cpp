#include "file.hpp"

File::File(std::string all_file)
{
	setAllLine(all_file);
}

File::File(File const &obj)
{
	if (this != &obj)
		*this = obj;
}

File& File::operator=(const File& obj)
{
	this->_all_line = obj._all_line;
	return (*this);
}

File::~File()
{}

std::vector<std::string>&	File::getAllLine(void)
{
	return (this->_all_line);
}

void	File::setAllLine(std::string file)
{
	std::string line;
	do 
	{
		line = file.substr(0, file.find('\n'));
		file = file.substr(file.find('\n') + 1);
		this->getAllLine().push_back(line);
	}while (file.find('\n') != std::string::npos);
	line = file.substr(0, file.find("\n"));
	file = file.substr(file.find('\n') + 1);
	this->getAllLine().push_back(line);
}
