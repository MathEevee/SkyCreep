#include "item.hpp"

std::string select_pars_item(std::string old_name, std::map<std::string, std::string> dictionary)
{
	return (dictionary[old_name]);
}


std::string change_name(std::string old_name, std::map<std::string, std::string> dictionary)
{
	std::string new_name = dictionary[old_name];
	if (new_name != old_name)
		return (new_name);

	if (old_name.find(' ') == std::string::npos)
		return (old_name);

	new_name = "";

	while (old_name.find(' ') != std::string::npos)
	{
		new_name = old_name.substr(0, old_name.find(' '));
		old_name = old_name.substr(old_name.find(' ') + 1);
		if (old_name[0])
		{
			if (old_name[0] >= 'a' && old_name[0] <= 'z')
				old_name[0] = old_name[0] - 32;
		}
		new_name = new_name + old_name;
	}
	return (new_name);
}

Item::Item()
{}

Item::Item(std::string name, std::map<std::string, std::string> dictionary)
{
	std::string new_name;

	new_name = change_name(name, dictionary);

	this->_name_item = new_name;
}

void	Item::addPrice(price new_price)
{
	this->getType().push_back(new_price);
}

void	Item::addPrice(std::string unit, std::string prix)
{
	price new_price(unit, prix);

	this->getType().push_back(new_price);
}

Item::~Item()
{}

std::string	Item::getName(void)
{
	return (this->_name_item);
}


std::vector<price>&	Item::getType(void)
{
	return (this->_price);
}

const std::vector<price>& Item::getType() const {
    return this->_price;
}
