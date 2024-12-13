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
	std::string message;
	
	message = file;
	while (message.find("\n") != std::string::npos)
	{
		std::string line = message.substr(0, message.find("\n"));
		message = message.substr(message.find('\n') + 1);
		this->getAllLine().push_back(message);
	}
}

void	setNewLine(std::string old_line)
{

}