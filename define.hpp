#ifndef DEFINE_HPP
# define DEFINE_HPP

/*Rank*/

# define DEBUTANT "défis/Defi_1_Debutant/"
# define NOVICE "défis/Defi_2_Novice/"
# define FACILE "défis/Defi_3_Facile/"
# define MOYEN "défis/Defi_4_Moyen/"
# define INTER "défis/Defi_5_Intermediaire/"
# define DIFFICILE "défis/Defi_6_Difficile/"
# define EXTREME "défis/Defi_7_Extreme/"
# define SKYMASTER "défis/Defi_8_SkyMaster/"
# define SKYGOD "défis/Defi_9_SkyGod/"
# define SKYPEARL "défis/Defi_10_SkyPearl/"
# define SKYWING "défis/Defi_11_SkyWing/"
# define SKYDROP "défis/Defi_12_SkyDrop/"
# define SKYMONSTER "défis/Defi_13_SkyMonster/"
# define SKYBUSTER "défis/Defi_14_SkyBuster/"
# define SKYHUNTER "défis/Defi_15_SkyHunter/"
# define SKYGUARDIAN "défis/Defi_16_SkyGuardian/"
# define SKYLANDER "défis/Defi_17_SkyLander/"
# define SKYCREEPER "défis/Defi_18_SkyCreeper/"
# define SKYHEROES "défis/Defi_19_SkyHeroes/"
# define SKYLORD "défis/Defi_20_SkyLord/"
# define SKYLEGEND "défis/Defi_21_SkyLegend/"
# define PRESTIGE(nbr_defis, nbr_pres) "défis/Defi_" + nbr_defis + "_Prestige" + nbr_pres + "/"

/*variante rank*/

# define DEB "Débutant"
# define DEBU "Debutant"
# define EXT "Extreme"
# define INTERM "Intermediaire"

# define SKY "Sky"

# define GOD "SkyGod"
# define MASTER "SkyMaster"

/*variante item*/

/*variante classe*/

# define NETHER "Nether"
# define NW "NW"
# define CHAMPI "Champignon"
# define BLE "Ble"
# define PAPIER "Canne"

/*variable*/

# define YML ".yml"

/*paterne*/

# define LINK(rank, item) rank + "_" + item + YML
# define LINK_BIS(rank) rank + YML

/*in yml*/

# define LORE(unitaire, res) "    - 'lore:&e ▪ &8&m" + unitaire + " &a " + res + " SkyPoints &8| &7x1'"
# define LOREDC(res) "    - 'lore:&7&o  (DC : " + res + " SP)'"
# define REWARD(res) "    Reward: " + res
# define REWARDMIDDLE(res) "    Reward_middle: " + res

#endif