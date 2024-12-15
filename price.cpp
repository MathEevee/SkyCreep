#include "price.hpp"

std::string pars_price(std::string prix)
{
	std::string new_str;
	for (std::string::iterator it = prix.begin(); it != prix.end(); it++)
	{
		if (*it != ',' && (((*it) < '0' || (*it) > '9')))
		{
			new_str = new_str + ' ';
			it++;
			it++;
			continue;
		}
		new_str = new_str + *it;
	}
	return (new_str);
}

price::price(std::string unit, std::string prix)
{
	this->_unit = unit;
	this->_prix = pars_price(prix);
}

price::price(std::string unit)
{
	this->_unit = unit;
}

price::price()
{}

price::~price()
{}

std::string	price::getPrice(void)
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