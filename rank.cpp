# include "rank.hpp"
# include "define.hpp"

rank::rank()
{}

rank::rank(std::string name)
{
	setName(name);
}

rank::~rank()
{}

void	rank::addClassItem(std::string name_class)
{
	if (name_class[0] == 13 || name_class[0] == 10)
		name_class = name_class.substr(1);
	if (name_class[0] == 13 || name_class[0] == 10)
		name_class = name_class.substr(1);
	for (std::vector<ItemType>::iterator it = this->getType().begin(); it != this->getType().end(); it++)
	{
		if ((*it).getName() == name_class)
			return;
	}
	ItemType add_item(name_class);
	this->getType().push_back(add_item);
}

void	rank::addPrice(std::string name_class, std::string name_item, std::string prix, std::string unit)
{
	name_item = name_item.substr(1);
	for (std::vector<ItemType>::iterator it = this->getType().begin(); it != this->getType().end(); it++)
	{
		if ((*it).getName() == name_class)
		{
			for (std::vector<Item>::iterator it_type = (*it).getItemType().begin(); it_type != (*it).getItemType().end(); it_type++)
			{
				if ((*it_type).getName() == name_item)
				{
					(*it_type).addPrice(unit, prix);
					return;
				}
			}
		}
	}
}

void	rank::addOtherUnit(std::string prix, std::string unit)
{
	std::vector<ItemType>::iterator type_item;
	if (this->getType().size())
	{
		type_item = this->getType().end();
		type_item--;
	}
	else
		type_item = this->getType().begin();
	std::vector<Item>::iterator last_item;
	if (type_item->getItemType().size())
	{
		last_item = type_item->getItemType().end();
		last_item--;
	}
	else
		last_item = type_item->getItemType().begin();
	if (unit[0] == ',')
		unit = unit.substr(1);
	(*last_item).addPrice(unit, prix);
}


void	rank::addOtherPrice(std::string name_item, std::string prix, std::string unit)
{
	std::vector<ItemType>::iterator type_item;

	if (this->getType().size() > 1)
	{
		type_item = this->getType().end();
		type_item--;
	}
	else
		type_item = this->getType().begin();
	std::vector<Item>::iterator last_item;
	if (type_item->getItemType().size() > 1)
	{
		last_item = type_item->getItemType().end();
		last_item--;
	}
	else
		last_item = type_item->getItemType().begin();
	price new_price(unit, prix);
	last_item->getType().push_back(new_price);
}


void	rank::addOtherItem(std::string name_item)
{
	std::vector<ItemType>::iterator type_item = this->getType().end();
	type_item--;
	Item newItem(name_item.substr(1));
	type_item->getItemType().push_back(newItem);
}


void	rank::addItem(std::string name_class, std::string name_item)
{
	for (std::vector<ItemType>::iterator it = this->getType().begin(); it != this->getType().end(); it++)
	{
		if ((*it).getName() == name_class)
		{
			for (std::vector<Item>::iterator it_type = (*it).getItemType().begin(); it_type != (*it).getItemType().end(); it_type++)
			{
				if ((*it_type).getName() == name_item)
					return;
			}
			if (name_item.size() == 1)
				name_item = name_class;
			else
				name_item = name_item.substr(1);
			Item	new_item(name_item);
			(*it).getItemType().push_back(new_item);
		}
	}
}

std::string	pars_rank(std::string name_rank)
{
	if (name_rank[0] == 'D' && name_rank != "DIFFICILE" && name_rank != "DROP")
		return (DEBU);
	else if (name_rank == "EXTRÊME")
		name_rank = EXT;
	else if (name_rank == "INTER")
		name_rank = INTERM;
	else if (name_rank == "SKYMASTER")
		name_rank = MASTER;
	else if (name_rank == "SKYGOD")
		name_rank = GOD;
	else
	{
		std::string tmp;
		std::string::iterator it = name_rank.begin();
		tmp = *it;
		it++;
		for (; it != name_rank.end(); it++)
		{
			if ((*it) == ' ')
				it++;
			if ((*it) >= 'A' && (*it) <= 'Z')
				(*it) += 32;
			tmp += (*it);
		}
		name_rank = tmp;
		if (name_rank != "Difficile" && name_rank != "Facile"
			&& name_rank != "Novice" && name_rank != "Moyen"
			&& name_rank.find("Prestige") == std::string::npos)
			name_rank = SKY + name_rank;
	}
	return (name_rank);
}

void	rank::setName(std::string name_rank)
{
	this->_name_rank = pars_rank(name_rank);
}


std::vector<ItemType>&	rank::getType(void)
{
	return (this->_item_type);
}


std::string	rank::getName(void)
{
	return (this->_name_rank);
}

// std::ostream	&operator<<(std::ostream& os, std::vector<rank>& obj)
// {
// 	for (std::vector<rank>::iterator it = obj.begin(); it != obj.end(); it++)
// 	{
// 		os << "----------------------------------" << std::endl;
// 		os << "Rank : " << (*it).getName() << ":\n";
// 		os << "ItemType :" << (*it).getType() << ":\n";
// 		os << "----------------------------------" << std::endl;

// 	}
// 	return (os);
// }


