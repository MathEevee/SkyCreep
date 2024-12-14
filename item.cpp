#include "item.hpp"

Item::Item()
{}

Item::Item(std::string name)
{
	this->_name_item = name;
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

// std::ostream	&operator<<(std::ostream& os, std::vector<price>& obj)
// {
// 	for (std::vector<price>::iterator it = obj.begin(); it != obj.end(); it++)
// 	{
// 		os << (*it).getType() << std::endl;
// 	}
// 	return (os);
// }