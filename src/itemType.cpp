#include "itemType.hpp"

ItemType::ItemType()
{}

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

std::string	ItemType::getName(void)
{
	return (this->_name_type);
}

std::vector<Item>&	ItemType::getItemType(void)
{
	return (this->_item);
}
