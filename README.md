# Actualisation des prix pour un plugin Minecraft

Ce programme permet de modifier un grand nombre d'informations spécifiques dans des .YML en prenant les informations d'un .CSV et en liant les noms dans le dictionnaire.

---

## 🚀 Lancer le programme

1. **Compiler** le programme :
   ```bash
   make
   ```
   (dans le dossier où se situe le `Makefile`)

2. **Exécuter** le programme :
   ```bash
   ./change_data <data.csv>
   ```
---

## 🌳 Arborescence

Le fichier .csv forme cette arborescence :

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

Dans la logique du code, cela correspond à :

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
│
...
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
│
...

```

Le programme génère ou recherche les données (par exemple les noms des chemins) pour identifier les bons fichiers.

Les noms des objets sont identifiés et les lignes prédéfinies sont remplacées à l’aide de macros.

Pour éviter les incohérences entre les noms utilisés dans le fichier .csv et ceux présents dans les fichiers .yml, un dictionnaire de correspondance est défini. Il associe chaque identifiant du .yml à son équivalent dans le .csv, par exemple :

```
Objet dans le .yml | Objet dans le .csv
GrainesBetterave | Graine de Betterave
Betterave | Betterave
MonolitheBetterave | Monolithe de Betterave
GraineBle | Graine de Blé
Epi | Epi 
```
