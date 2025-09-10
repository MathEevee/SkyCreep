# Actualisation des prix pour un plugin Minecraft

Ce programme permet de modifier un grand nombre d'informations précise dans des .YML en prenant les informations d'un .CSV et en liant les noms dans le dictionnaire.

---


---

## 🚀 Lancer le programme

1. **Compiler** le programme :
   ```bash
   make
   ```
   (dans le dossier où se situe le `Makefile`)

2. **Exécuter** le serveur :
   ```bash
   ./change_data <data.csv>
   ```
---

## 🌳 Arborescence

Les fichiers à changer doivent être sous cette forme :

```
défis/
├── Defi_1_Debutant/
│   ├── Debutant_Bois.yml
│   ├── Debutant_Lapin.yml
│   └── ...
├── Defi_2_Novice/
│   ├── Novice_Bois.yml
│   ├── Novice_Lapin.yml
│   ├── Novice_Poisson.yml
|   └── ...
├── Defi_3_Facile/
│   └── ...
...
├── Defi_28_Prestige7/
│   └── ...
```
---



## 🗒️ Nouveaux prix du .CSV

Le .CSV forme cette arborescence.

```
Pomme
├── pomme
│   ├── Unité
│   ├── Unité x2
│   ├── Unité x3
│   ├── DC
│   ├── DC x2
│   └── DC x3
└── pomme dorée
    ├── Unité
    ├── Unité x2
    ├── Unité x3
    ├── DC
    ├── DC x2
    └── DC x3
Carotte
├── Carotte
│   ├── Unité
│   ├── Unité x2
│   ├── Unité x3
│   ├── DC
│   ├── DC x2
│   └── DC x3
└── Carotte dorée
    ├── Unité
    ├── Unité x2
    ├── Unité x3
    ├── DC
    ├── DC x2
    └── DC x3

```

Dans le code :

```
Débutant
├── pomme
│   ├── pomme ├── ...
│   └── pomme dorée ├── ...
├── Carotte
│   ├── Carotte ├── ...
│   └── Carotte dorée ├── ...
└── Boeuf
│   ├── Boeuf cru ├── ...
│   └── Boeuf cuit ├── ...
└── ...
Novice
├── pomme
│   ├── pomme ├── ...
│   └── pomme dorée ├── ...
├── Carotte
│   ├── Carotte ├── ...
│   └── Carotte dorée ├── ...
└── Boeuf
│   ├── Boeuf cru ├── ...
│   └── Boeuf cuit ├── ...
└── ...

```

On génère ou cherche les données comme les noms des chemins pour trouver les bons fichiers, on cherche les noms des objets et on remplace les lignes prédéfinies avec les macros.

Pour éviter les problèmes avec les noms des objets dans le .csv et dans les .yml, on complète le dictionnaire :

```
Objet dans le .yml | Objet dans le .csv
GrainesBetterave | Graine de Betterave
Betterave | Betterave
MonolitheBetterave | Monolithe de Betterave
GraineBle | Graine de Blé
Epi | Epi 
```
