#include "itemType.hpp"

ItemType::ItemType(std::string name)
{
	this->_name_type = name;
}

ItemType::~ItemType()
{}

void	ItemType::setName(std::string classItem)
{
	this->_name_type = classItem;
}


// void	ItemType::addItem(price new_price, Item new_item);
// {
// 	this->getItemType().push_back(new_item);
// }


std::string	ItemType::getName(void)
{
	return (this->_name_type);
}

std::vector<Item>&	ItemType::getItemType(void)
{
	return (this->_item);
}

// std::ostream	&operator<<(std::ostream& os, std::vector<Item>& obj)
// {
// 	for (std::vector<ItemType>::iterator it = obj.begin(); it != obj.end(); it++)
// 	{
// 		os << "Item :" << (*it).getName() << ":\n";
// 		os << "Unite & price :\n" << (*it).getItemType();

// 	}
// 	return (os);
// }