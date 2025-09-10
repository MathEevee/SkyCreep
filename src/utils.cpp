#include "utils.hpp"

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
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do
	{
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
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

void	create_all_link(std::vector<ItemType> all_class, std::string rank_name)
{
	for (std::vector<ItemType>::iterator it_class = all_class.begin(); it_class != all_class.end(); it_class++)
	{
		parse_link_file((*it_class).getItemType(), (*it_class).getName(), rank_name);
	}
}