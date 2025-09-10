#include "item.hpp"

Item::Item()
{}

Item::Item(std::string name, std::map<std::string, std::string> dictionary)
{
	std::string new_name;

	new_name = dictionary[name];

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
