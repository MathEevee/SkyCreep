#include "replaceYml.hpp"


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

	else if (line.find("- 'lore:&e ▪ &a") != std::string::npos && nbr == 2 && line.find(" SkyPoints &8| &7x1'") != std::string::npos)
		line = LOREUN(item.getType()[0].getPrice());

	else if (line.find("- 'lore:&7&o  (DC : ") != std::string::npos)
		line = LOREDC(item.getType()[5 - nbr].getPrice());

	else if (line.find("Reward:") != std::string::npos && nbr != -1 && nbr != 3)
		line = REWARD(price_unit_no_virg);

	else if (line.find("    Reward_right: ") != std::string::npos)
		line = REWARD_RIGHT(price_unit_no_virg);

	else if (line.find("    Reward_middle:") != std::string::npos)
		line = REWARDMIDDLE(price_unit_no_virg);
	return (line);
}

std::string new_line_laine(std::string line, int &nbr, Item item, int &nbr_rewards)
{
	price select_price = item.getType()[2 - nbr];

	std::string price_unit_no_virg = ft_replace(item.getType()[0].getPrice());


	if (line.find("- 'lore:&e ▪ &8&m") != std::string::npos && nbr != 2)
		line = LORE(item.getType()[0].getPrice(), select_price.getPrice());

	else if (line.find("- 'lore:&e ▪ &a") != std::string::npos && nbr == 2 && line.find(" SkyPoints &8| &7x1'") != std::string::npos)
		line = LOREUN(item.getType()[0].getPrice());

	else if (line.find("- 'lore:&7&o  (DC : ") != std::string::npos)
		line = LOREDC(item.getType()[5 - nbr].getPrice());

	else if (line.find("Reward:") != std::string::npos && nbr_rewards != 48)
	{
		line = REWARD(price_unit_no_virg);
		nbr_rewards++;
	}

	else if (line.find("    Reward_right: ") != std::string::npos)
		line = REWARD_RIGHT(price_unit_no_virg);

	else if (line.find("    Reward_middle:") != std::string::npos)
	{
		nbr++;
		line = REWARDMIDDLE(price_unit_no_virg);
	}
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
	int nbr_rewards = 0;
	Item laine(*(all_item).begin());
	for (std::vector<std::string>::iterator it = tmp.getAllLine().begin(); it != tmp.getAllLine().end(); it++)
	{
		*it = new_line_laine(*it, nbr, laine, nbr_rewards);
		if (nbr == 3)
			nbr = 0;
	}
	overwrite(tmp, link);
}

void	file_overwrite(std::vector<Item> all_item, std::string link)
{
	bool change_line = false;

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
					*it = new_line(*it, nbr, *it_item);
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
		{
			link = select_defis_link(rank_name) + LINK_BIS(rank_name);
		}
	}
	infile.close();
	change_file(all_item, link);
}

void	apply_new_data(std::vector<rank> &all_rank)
{
	for (std::vector<rank>::iterator it_rank = all_rank.begin(); it_rank != all_rank.end(); it_rank++)
	{
		create_all_link((*it_rank).getType(), (*it_rank).getName());
	}
}
