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

std::string create_link_item(std::string rank, std::string class_item, std::string dir);

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
		if (((quote == false && line[i] == ',') || (quote == true && j != i && line[i] == '"')) && line[i] != '\n')
		{
			data = line.substr(j, i - j);
			if (data[0] == '"')
			{
				data = data.substr(1);
				if (data[0] == ' ')
					data = data.substr(1);
				data = data.substr(0, data.size() - 1);
			}
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
	if (params[0].size() > 1)
		return (true);
	return (false);
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
				std::cout << "-item :	" << (*it_item).getName() << std::endl;
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

void	create_type_item(std::vector<rank> &all_rank, std::vector<std::string> price_item)
{
	std::vector<std::string> tmp = price_item;
	tmp.erase(tmp.begin());
	tmp.erase(tmp.begin());
	std::string quantity = tmp.begin()->substr(1);
	tmp.erase(tmp.begin());

	std::vector<std::string>::iterator it_price_item = tmp.begin();
	it_price_item++;

	for (std::vector<rank>::iterator it_rank = all_rank.begin(); it_rank != all_rank.end(); it_rank++)
	{
		if ((*it_price_item).size() > 1)
		{
			(*it_rank).addClassItem(price_item[0]);
			(*it_rank).addItem(price_item[0], price_item[1]);
			(*it_rank).addPrice(price_item[0], price_item[1], *it_price_item, quantity);
			it_price_item++;
		}
		if ((*it_price_item).size() == 1)
		{
			it_price_item++;
			continue;
		}
	}
}

void	create_item(std::vector<rank> &all_rank, std::vector<std::string> price_item)
{
	std::vector<std::string> tmp = price_item;
	if (tmp.begin()->size() <= 1)
		tmp.erase(tmp.begin());
	std::string name_item = tmp.begin()->substr(1);
	tmp.erase(tmp.begin());
	std::string name_quantity = tmp.begin()->substr(1);
	tmp.erase(tmp.begin());

	std::vector<std::string>::iterator it_price_item = tmp.begin();
	it_price_item++;
	for (std::vector<rank>::iterator it_rank = all_rank.begin(); it_rank != all_rank.end(); it_rank++)
	{

	}
}
