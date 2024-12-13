#include "item.hpp"

Item::Item(std::string name)
{
	this->_name_item = name;
}

void	Item::addPrice(price unit_price_item)
{
	this->_price.push_back(unit_price_item);
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

// std::ostream	&operator<<(std::ostream& os, std::vector<price>& obj)
// {
// 	for (std::vector<price>::iterator it = obj.begin(); it != obj.end(); it++)
// 	{
// 		os << (*it).getType() << std::endl;
// 	}
// 	return (os);
// }