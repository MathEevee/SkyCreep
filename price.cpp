#include "price.hpp"

price::price(std::string unit, std::string  prix)
{
	this->_unit = unit;
	this->_prix = prix;
}

price::price(std::string unit)
{
	this->_unit = unit;
}

void	price::addPrice(std::string  prix)
{
	setPrice(prix);
}


price::~price()
{}

void	price::setPrice(std::string  prix)
{
	this->_prix = prix;
}

std::string 	price::getPrice(void)
{
	return (this->_prix);
}

std::string price::getUnit(void)
{
	return (this->_unit);
}

// std::ostream	&operator<<(std::ostream& os, std::vector<price>& obj)
// {
// 	for (std::vector<price>::iterator it = obj.begin(); it != obj.end(); it++)
// 	{
// 		os << (*it).getUnit() << " = " << (*it).getPrice() << std::endl;
// 	}
// 	return (os);
// }