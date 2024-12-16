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
#include <ostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

std::string ft_replace(std::string str)
{
	std::string res;
	int i = 0;

	for (std::string::iterator it = str.begin(); it != str.end();)
	{
		if ((*it) >= '0' && (*it) <= '9')
			res = res + (*it);
		if ((*it) == ',')
			res = res + '.';
		if ((*it) >= '0' && (*it) <= '9' || (*it) ==  '.')
			i++;
		it++;
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
	if (params[0].size() >= 2 && params[0][0] != ',')
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
				/*for (std::vector<price>::iterator it_price = (*it_item).getType().begin(); it_price != (*it_item).getType().end(); it_price++)
				{
					std::cout << (*it_price).getUnit() << " = " << (*it_price).getPrice() << std::endl;
				}
				std::cout << std::endl;*/
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
	std::string unit = all_data[0].substr(1);
	all_data.erase(all_data.begin());
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
}

void	create_item(std::vector<rank> &all_rank, std::vector<std::string> all_data)
{
	all_data.erase(all_data.begin());

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
				create_item_type(all_rank, tmp);
			else if (is_item(tmp) == true)
				create_item(all_rank, tmp);
			else
				create_price(all_rank, tmp);
			tmp.clear();
		}
		tmp.push_back(*it);
	}
	create_price(all_rank, tmp);
}

std::string change_class_name(std::string class_name)
{
	if (class_name == "Champi")
		return (CHAMPI);
	if (class_name == "Blé")
		return (BLE);
	if (class_name == "Papier")
		return (PAPIER);
	if (class_name == "Verrue nether")
		return (NW);
	if (class_name == "Blocs Nether")
		return (NETHER);
	return (class_name);
}

void reverse(char s[])
{
    int i, j;
    char c;
    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
} 

std::string	select_defis_link(std::string name_rank)
{
	if (name_rank == "Debutant" || name_rank == "Débutant")
		return (DEBUTANT);
	if (name_rank == "Novice")
		return (NOVICE);
	if (name_rank == "Facile")
		return (FACILE);
	if (name_rank == "Moyen")
		return (MOYEN);
	if (name_rank == "Intermediaire")
		return (INTER);
	if (name_rank == "Difficile")
		return (DIFFICILE);
	if (name_rank == "Extreme")
		return (EXTREME);
	if (name_rank == "SkyMaster")
		return (SKYMASTER);
	if (name_rank == "SkyGod")
		return (SKYGOD);
	if (name_rank == "SkyPearl")
		return (SKYPEARL);
	if (name_rank == "SkyWing")
		return (SKYWING);
	if (name_rank == "SkyDrop")
		return (SKYDROP);
	if (name_rank == "SkyMonster")
		return (SKYMONSTER);
	if (name_rank == "SkyBuster")
		return (SKYBUSTER);
	if (name_rank == "SkyHunter")
		return (SKYHUNTER);
	if (name_rank == "SkyGuardian")
		return (SKYGUARDIAN);
	if (name_rank == "SkyLander")
		return (SKYLANDER);
	if (name_rank == "SkyCreeper")
		return (SKYCREEPER);
	if (name_rank == "SkyHeroes")
		return (SKYHEROES);
	if (name_rank == "SkyLord")
		return (SKYLORD);
	if (name_rank == "SkyLegend")
		return (SKYLEGEND);
	int i = 0;
	std::string nbr;
	while (name_rank[i] != '\0')
	{
		if (name_rank[i] >= '0' && name_rank[i] <= '9')
			nbr = nbr + name_rank[i];
		i++;
	}
	int nbr_defis = atoi(nbr.c_str()) + 21;
	char tmp[33];
	itoa(nbr_defis, tmp);
	std::string nbrd = tmp;
	return (PRESTIGE(nbrd, nbr));
}

/*std::string change_line(Item item, std::string line, int &nbr)
{
	price select_price = item.getType()[2 - nbr];

	std::cout << "---------------------------" << std::endl;
	std::cout << "item = " << item.getName() << std::endl;
	std::cout << "price[0]u = " << item.getType()[0].getUnit() << std::endl;
	std::cout << "price[0]p = "  << item.getType()[0].getPrice() << std::endl;
	std::cout << "price[1]u = "  << item.getType()[1].getUnit() << std::endl;
	std::cout << "price[1]p = "  << item.getType()[1].getPrice() << std::endl;
	std::cout << "price[2]u = "  << item.getType()[2].getUnit() << std::endl;
	std::cout << "price[2]p = "  << item.getType()[2].getPrice() << std::endl;
	std::cout << "price[3]u = "  << item.getType()[3].getUnit() << std::endl;
	std::cout << "price[3]p = "  << item.getType()[3].getPrice() << std::endl;
	std::cout << "price[4]u = "  << item.getType()[4].getUnit() << std::endl;
	std::cout << "price[4]p = "  << item.getType()[4].getPrice() << std::endl;
	std::cout << "price[5]u = "  << item.getType()[5].getUnit() << std::endl;
	std::cout << "price[5]p = "  << item.getType()[5].getPrice() << std::endl;
	std::cout << "---------------------------" << std::endl;

	std::string price_unit_no_virg = ft_replace(item.getType()[0].getPrice());

	if (line.find("- 'lore:&e ▪ &8&m") != std::string::npos && nbr != 2)
		line = LORE(item.getType()[0].getPrice(), select_price.getPrice());

	else if (line.find("- 'lore:&e ▪ &a") != std::string::npos && nbr == 2)
		line = LOREUN(item.getType()[0].getPrice());

	else if (line.find("- 'lore:&7&o  (DC : ") != std::string::npos)
		line = LOREDC(item.getType()[5 - nbr].getPrice());

	else if (line.find("Reward:") != std::string::npos)
		line = REWARD(price_unit_no_virg);

	else if (line.find("    Reward_middle:") != std::string::npos)
	{
		line = REWARDMIDDLE(price_unit_no_virg);
	}
	return (line);
}


void	file_overwrite(File tmp, std::vector<Item> all_item, std::string link, File temoin)
{

	bool change_data = false;

	for (std::vector<Item>::iterator it_item = all_item.begin(); it_item != all_item.end(); it_item++)
	{
		int nbr = 0;
		change_data = false;
		std::string item = "  " + (*it_item).getName();
		std::cout << "item|" << item<<"|" << std::endl;
		std::vector<std::string>::iterator it_bis = temoin.getAllLine().begin();
		for (std::vector<std::string>::iterator it = tmp.getAllLine().begin(); it != tmp.getAllLine().end(); it++)
		{
			if ((*it).find(item) != std::string::npos && (*it) == (*it_bis))
			{
				std::cout << "*it = " << *it << std::endl;
				std::cout << "*it_bis = " << *it_bis << std::endl;
				change_data = true;
			}
			if (change_data == true && ((*it).find("Reward:") != std::string::npos
				|| (*it).find("    Reward_middle:") != std::string::npos || (*it).find("- 'lore:&") != std::string::npos))
			{
				std::string nl = change_line((*it_item), *it, nbr);
				if (nl != *it)
					*it = nl;
			}
			if ((*it).find("    InventoryLocation: ") != std::string::npos && change_data == true)
			{
				nbr++;
				if (nbr == 3)
				{
					nbr == 0;
					break;
				}
			}
			it_bis++;
		}
	}
	overwrite(tmp, link);
}


void	change_file(std::vector<Item> all_item, std::string link)
{
	std::ifstream input;
	std::string content_file;
	
	input.open(link);
	if (input.is_open() == false)
	{
		// std::cout << "this file doesn't exist : " << link << std::endl;
		return;
	}
	getline(input, content_file, '\0');
	input.close();
	File tmp(content_file);
	File temoin(content_file);
	if (all_item.begin()->getName() != "Laine")
		file_overwrite(tmp, all_item, link, temoin);
	else
		file_laine(tmp, all_item, link);
}*/

void	overwrite(File file, std::string link)
{
	std::ofstream	output;

	output.open(link.c_str(), std::fstream::out);

	for (std::vector<std::string>::iterator it = file.getAllLine().begin(); it != file.getAllLine().end(); it++)
	{
		output << *it << "\n";
	}
	output.close();
}

bool	parsing_line_for_item(std::string line, Item curr_item, int &nbr, bool change_line)
{
	std::string item_name1 = "  " + curr_item.getName() + ' ';
	std::string item_name2 = "  " + curr_item.getName() + 'x';

	if ((line.find(item_name1) != std::string::npos || line.find(item_name2) != std::string::npos) && nbr == -1)
	{
		nbr = 0;
		return (true);
	}
	else if (nbr > -1)
		return (true);
	return (false);
}

std::string new_line(std::string line, int &nbr, Item item)
{
	price select_price = item.getType()[2 - nbr];

	std::string price_unit_no_virg = ft_replace(item.getType()[0].getPrice());


	if (line.find("- 'lore:&e ▪ &8&m") != std::string::npos && nbr != 2)
		line = LORE(item.getType()[0].getPrice(), select_price.getPrice());

	else if (line.find("- 'lore:&e ▪ &a") != std::string::npos && nbr == 2)
		line = LOREUN(item.getType()[0].getPrice());

	else if (line.find("- 'lore:&7&o  (DC : ") != std::string::npos)
		line = LOREDC(item.getType()[5 - nbr].getPrice());

	else if (line.find("Reward:") != std::string::npos)
		line = REWARD(price_unit_no_virg);

	else if (line.find("    Reward_right: ") != std::string::npos)
		line = REWARD_RIGHT(price_unit_no_virg);

	else if (line.find("    Reward_middle:") != std::string::npos)
	{
		line = REWARDMIDDLE(price_unit_no_virg);
	}
	std::cout << nbr << std::endl;
	std::cout << line << std::endl;
	return (line);
}

std::string new_line_laine(std::string line, int &nbr, Item item)
{
	price select_price = item.getType()[2 - nbr];

	std::string price_unit_no_virg = ft_replace(item.getType()[0].getPrice());


	if (line.find("- 'lore:&e ▪ &8&m") != std::string::npos && nbr != 2)
		line = LORE(item.getType()[0].getPrice(), select_price.getPrice());

	else if (line.find("- 'lore:&e ▪ &a") != std::string::npos && nbr == 2)
		line = LOREUN(item.getType()[0].getPrice());

	else if (line.find("- 'lore:&7&o  (DC : ") != std::string::npos)
		line = LOREDC(item.getType()[5 - nbr].getPrice());

	else if (line.find("Reward:") != std::string::npos)
		line = REWARD(price_unit_no_virg);

	else if (line.find("    Reward_middle:") != std::string::npos)
	{
		line = REWARDMIDDLE(price_unit_no_virg);
		nbr++;
	}
	std::cout << nbr << std::endl;
	std::cout << line << std::endl;
	return (line);
}

void	file_laine(std::vector<Item> all_item, std::string link)
{
	std::string content_file;
	std::ifstream infile;
	infile.open(link.c_str());
	getline(infile, content_file, '\0');
	infile.close();
	File tmp(content_file);
	int nbr = 0;
	Item laine(*(all_item).begin());
	for (std::vector<std::string>::iterator it = tmp.getAllLine().begin(); it != tmp.getAllLine().end(); it++)
	{
		*it = new_line_laine(*it, nbr, laine);
		if (nbr == 3)
			nbr = 0;
	}
	overwrite(tmp, link);
}

void	file_overwrite(std::vector<Item> all_item, std::string link)
{
	bool change_line = false;

	std::cout << link << std::endl;
	for (std::vector<Item>::iterator it_item = all_item.begin(); it_item != all_item.end(); it_item++)
	{
		std::string content_file;
		std::ifstream infile;
		infile.open(link.c_str());
		getline(infile, content_file, '\0');
		infile.close();
		File tmp(content_file);
		int nbr = -1;
		for (std::vector<std::string>::iterator it = tmp.getAllLine().begin(); it != tmp.getAllLine().end(); it++)
		{
			change_line = parsing_line_for_item(*it, *it_item, nbr, change_line);
			if (change_line == true)
			{
				if (nbr != -1)
				{
					*it = new_line(*it, nbr, *it_item);
					std::cout << *it << std::endl;
				}
				if ((*it).find("    InventoryLocation: ") != std::string::npos && nbr != -1)
					nbr++;
				if (nbr == 3)
				{
					change_line = false;
					nbr = -1;
				}
			}
		}
		overwrite(tmp, link);
	}
}


void	change_file(std::vector<Item> all_item, std::string link)
{
	if (all_item.begin()->getName() != "Laine")
		file_overwrite(all_item, link);
	else
		file_laine(all_item, link);
}

void	parse_link_file(std::vector<Item> all_item, std::string class_name, std::string rank_name)
{
	std::string new_class_name = change_class_name(class_name);
	std::string link = select_defis_link(rank_name) + LINK(rank_name, new_class_name);

	std::ifstream infile;
	infile.open(link.c_str());

	if (rank_name == "Debutant")
	{
		if (infile.is_open() == false)
		{
			std::string tmp = DEB;
			link = select_defis_link(tmp) +  LINK(tmp, new_class_name);
			infile.open(link.c_str());
			if (infile.is_open() == false)
			{
				link = select_defis_link(rank_name) + LINK_BIS(tmp);
				infile.open(link.c_str());
			}
		}
	}
	else
	{
		if (infile.is_open() == false)
			link = select_defis_link(rank_name) + LINK_BIS(rank_name);
	}
	infile.close();
	change_file(all_item, link);
}

void	create_all_link(std::vector<ItemType> all_class, std::string rank_name)
{
	for (std::vector<ItemType>::iterator it_class = all_class.begin(); it_class != all_class.end(); it_class++)
	{
		parse_link_file((*it_class).getItemType(), (*it_class).getName(), rank_name);
		// parse_link_file((all_class.begin())->getItemType(), ((all_class.begin()))->getName(), rank_name);
	}
}



void	apply_new_data(std::vector<rank> &all_rank)
{
	for (std::vector<rank>::iterator it_rank = all_rank.begin(); it_rank != all_rank.end(); it_rank++)
	{
		create_all_link((*it_rank).getType(), (*it_rank).getName());
		// create_all_link(all_rank.begin()->getType(), (all_rank.begin())->getName());
	}
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
	// print_all(all_rank);
	apply_new_data(all_rank);
}
