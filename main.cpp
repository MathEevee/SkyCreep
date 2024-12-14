#include "item.hpp"
#include "itemType.hpp"
#include "rank.hpp"
#include "price.hpp"
#include "define.hpp"
#include "file.hpp"

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

std::string ft_replace(std::string str, char old_c, char new_c)
{
	std::string res;
	int i = 0;

	for (std::string::iterator it = str.begin(); it != str.end();)
	{
		if (((*it) >= '0' && (*it) <= '9') || (*it) == ',')
			res = res + (*it);
		if ((*it) == old_c)
			res[i] = new_c;
		it++;
		i++;
	}
	return (res);
}


std::vector<std::string>	parsing_items(std::string line)
{
	std::vector<std::string> all_data;
	bool	quote = false;
	size_t	i = 0;
	size_t	j = 0;
	std::string	data;

	while (i < line.size())
	{
		if (line[i] == '"')
		{
			if (quote == true)
				quote = false;
			else
				quote = true;
		}
		if (((quote == false && line[i] == ',') || (quote == true && j != i && line[i] == '"')) || line[i] == '\n')
		{
			data = line.substr(j, i - j);
			if (data[0] == '"')
			{
				data = data.substr(1);
				if (data[0] == ' ')
					data = data.substr(1);
				data = data.substr(0, data.size() - 1);
			}
			if (data[0] == 13 || data[0] == 10)
				data = data.substr(1);
			if (data[0] == 13 || data[0] == 10)
				data = data.substr(1);
			all_data.push_back(data);
			for (std::string::iterator it = data.begin(); it != data.end(); it++)
			{
				if ((*it) == '%')
					all_data.pop_back();
			}
			j = i;
		}
		i++;
	}
	return (all_data);
}

bool	is_type_item(std::vector<std::string> params)
{
	if (params[0].size() > 2 && params[0][0] != ',')
		return (true);
	return (false);
}

bool	is_item(std::vector<std::string> params)
{

	if (params[1].size() == 1)
		return (false);
	return (true);
}

void	print_all(std::vector<rank>& all_rank)
{
	for (std::vector<rank>::iterator it_rank = all_rank.begin(); it_rank != all_rank.end(); it_rank++)
	{
		std::cout << "--------------------------------------------------------" << std::endl;
		std::cout << (*it_rank).getName() << std::endl;
		for (std::vector<ItemType>::iterator it_class = (*it_rank).getType().begin(); it_class != (*it_rank).getType().end(); it_class++)
		{
			std::cout << "**************************************************************" << std::endl;
			std::cout << "Class item :" << (*it_class).getName() << "\n" << std::endl;
			for (std::vector<Item>::iterator it_item = (*it_class).getItemType().begin(); it_item != (*it_class).getItemType().end(); it_item++)
			{
				std::cout << "-item :" << (*it_item).getName() << std::endl;
				for (std::vector<price>::iterator it_price = (*it_item).getType().begin(); it_price != (*it_item).getType().end(); it_price++)
				{
					std::cout << (*it_price).getUnit() << " = " << (*it_price).getPrice() << std::endl;
				}
				std::cout << std::endl;
			}
			std::cout << "**************************************************************" << std::endl;
		}
		std::cout << "\n\n--------------------------------------------------------\n\n" << std::endl;
	}
}

std::vector<std::string>	create_rank(std::vector<rank> &all_rank, std::vector<std::string>& data)
{
	size_t i = 0;

	for (std::vector<std::string>::iterator it = data.begin(); it != data.end();)
	{
		if ((*it).size() > 2)
		{
			rank tmp((*it).substr(1));
			all_rank.push_back(tmp);
		}
		it = data.erase(data.begin());
		if ((*it).find("Multiplicteur general") != std::string::npos)
		{
			data.erase(data.begin());
			break;
		}
	}
	return (data);
}

void	create_price(std::vector<rank> &all_rank, std::vector<std::string> all_data)
{
	all_data.erase(all_data.begin());
	all_data.erase(all_data.begin());
	int i = 0;
	std::cout << "---------------------------------" << std::endl;
	for (std::vector<std::string>::iterator it = all_data.begin(); it != all_data.end(); it++)
	{
		i = (*it)[0];
		std::cout << (*it) << std::endl;
		std::cout << i << std::endl;
	}
	std::cout << "******" << std::endl;
	std::string unit = all_data[0].substr(1);
	std::vector<std::string>::iterator price_unit = all_data.begin();
	price_unit++;
	for (std::vector<rank>::iterator it_rank = all_rank.begin(); it_rank != all_rank.end(); it_rank++)
	{
		if (((*price_unit).size()) > 1)
		{
			(*it_rank).addOtherUnit(*price_unit, unit);
			price_unit++;
		}
		price_unit++;
	}
	// otherPrice(all_rank, tmp);
	// for (std::vector<std::string>::iterator it = all_data.begin(); it != all_data.end(); it++)
	// {
	// 	std::cout << (*it) << std::endl;
	// }
}

void	create_item(std::vector<rank> &all_rank, std::vector<std::string> all_data)
{
	all_data.erase(all_data.begin());

	// std::cout << "0" << std::endl;
	// std::cout << all_data[0] << std::endl;
	// std::cout << "1" << std::endl;
	// std::cout << all_data[1] << std::endl;
	// std::cout << "2" << std::endl;
	// std::cout << all_data[2] << std::endl;

	// std::cout << "---------------------------------" << std::endl;
	std::string new_item = all_data[0];
	std::string unit = all_data[1];
	all_data.erase(all_data.begin());
	all_data.erase(all_data.begin());
	std::vector<std::string>::iterator it = all_data.begin();
	it++;
	for (std::vector<rank>::iterator it_rank = all_rank.begin(); it_rank != all_rank.end(); it_rank++)
	{
		if (((*it).size()) > 1)
		{
			(*it_rank).addOtherItem(new_item);
			(*it_rank).addOtherUnit(*it, unit);
			it++;
		}
		it++;
	}
}

void	create_item_type(std::vector<rank> &all_rank, std::vector<std::string> &all_data)
{
	std::string new_type_item = all_data[0];
	std::string new_item = all_data[1];
	std::string unit = all_data[2];
	std::vector<std::string> tmp = all_data;
	tmp.erase(tmp.begin());
	tmp.erase(tmp.begin());
	tmp.erase(tmp.begin());
	std::vector<std::string>::iterator it = tmp.begin();
	it++;
	// std::cout << (*it) << std::endl;
	for (std::vector<rank>::iterator it_rank = all_rank.begin(); it_rank != all_rank.end(); it_rank++)
	{
		if (((*it).size()) > 1)
		{
			(*it_rank).addClassItem(new_type_item);
			(*it_rank).addItem(new_type_item, new_item);
			(*it_rank).addOtherUnit(*it, unit);
			it++;
		}
		it++;
	}
}

void	otherPrice(std::vector<rank> &all_rank, std::vector<std::string> all_data)
{
	all_data.erase(all_data.begin());
	all_data.erase(all_data.begin());
	std::string unit = all_data[0];
	all_data.erase(all_data.begin());
	std::vector<std::string>::iterator it = all_data.begin();
	it++;
	for (std::vector<rank>::iterator it_rank = all_rank.begin(); it_rank != all_rank.end(); it_rank++)
	{
		if (((*it).size()) > 1)
		{
			(*it_rank).addOtherUnit(*it, unit);
			it++;
		}
		it++;
	}
}


void	parsing_file(std::vector<rank> &all_rank, std::vector<std::string> &all_data)
{
	std::vector<std::string> tmp;

	int i = 0;
	for (std::vector<std::string>::iterator it = all_data.begin(); it != all_data.end(); it++)
	{
		if (!((*it)[0] >= 44 && (*it)[0] <= 57) && tmp.size() > 2)
		{
			if (is_type_item(tmp) == true)
			{
				create_item_type(all_rank, tmp);
			}
			else if (is_item(tmp) == true)
			{
				create_item(all_rank, tmp);
			}
			else
			{
				// std::cout << "***item***" << std::endl;
				// std::cout << "0" << std::endl;
				// std::cout << tmp[0] << std::endl;
				// std::cout << "1" << std::endl;
				// std::cout << tmp[1] << std::endl;
				// std::cout << "2" << std::endl;
				// std::cout << tmp[2] << std::endl;

				// std::cout << "----------item_end-----------------" << std::endl;
				create_price(all_rank, tmp);
			}
			tmp.clear();
		}
		tmp.push_back(*it);
	}
	print_all(all_rank);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Bad Argument" << std::endl;
		return (0);
	}
	std::ifstream input;
	input.open(av[1]);
	std::string tmp;
	getline(input, tmp, '\0');

	std::vector<rank> all_rank;
	std::vector<std::string> all_data = parsing_items(tmp);
	all_data = create_rank(all_rank, all_data);
	parsing_file(all_rank, all_data);
}
