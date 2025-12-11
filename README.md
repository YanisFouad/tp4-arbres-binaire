# TP4 - Arbres Binaires

Projet d'indexation de texte utilisant des arbres binaires de recherche.

## Structure du Projet

```
tp4-arbres-binaire/
├── Makefile                      # Fichier de compilation
├── include/
│   └── tp4.h                     # Fichier d'en-tête avec les déclarations
└── src/
    ├── main.c                    # Point d'entrée du programme
    ├── affichage_index.c         # afficherIndex  (Aurélien)
    ├── arbre_index.c             # ajouterOccurence, rechercherMot (Aurélien)
    ├── construction_texte.c      # construireTexte (Aurélien)
    ├── global.c                  # Variables et fonctions globales
    ├── indexation_fichier.c      # indexerFichier (Yanis)
    ├── liste_position.c          # ajouterPosition (Yanis)
    └── occurences_mot.c          # afficherOccurencesMot (Yanis)
```

## Types de Données

### T_Position
Structure pour stocker la position d'un mot dans le texte :
- `numeroLigne` : numéro de ligne
- `ordre` : ordre dans la phrase
- `numeroPhrase` : numéro de phrase
- `suivant` : pointeur vers la position suivante

### T_Noeud
Nœud de l'arbre binaire de recherche :
- `mot` : le mot indexé
- `nbOccurrences` : nombre d'occurrences du mot
- `listePositions` : liste chaînée des positions
- `filsGauche` : sous-arbre gauche
- `filsDroit` : sous-arbre droit

### T_Index
Structure principale de l'index :
- `racine` : racine de l'arbre binaire
- `nbMotsDistincts` : nombre de mots distincts
- `nbMotsTotaux` : nombre total de mots

## Fonctions Principales

- `ajouterPosition()` : Ajoute une position à une liste de positions
- `ajouterOccurence()` : Ajoute une occurrence d'un mot dans l'index
- `indexerFichier()` : Indexe un fichier texte complet
- `afficherIndex()` : Affiche l'index complet
- `rechercherMot()` : Recherche un mot dans l'index
- `afficherOccurencesMot()` : Affiche les occurrences d'un mot
- `construireTexte()` : Reconstruit le texte depuis l'index

## Compilation et Exécution

### Compilation
```bash
make build
```

### Nettoyage
```bash
make clean
```

### Compilation et exécution
```bash
make run
```
