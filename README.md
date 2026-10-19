# Construire le projet
Vous pouvez utiliser un dev container de base C++ de VScode.
Le projet utilise cmake, pensez à l'inclure dans votre dev container.

Voici les lignes de commandes pour compiler le projet:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

# Répertoire data

Il contient 2 fichiers `books.txt`et `users.txt` que vous pouvez utilisez pour tester votre code.
Pour ca il suffit de donner chemin vers le repertoire data avec l'application `bibliotheque -d <chemin verrs data>`



# TP C++ - Gestion de bibliothèque

**Nom :** Edson Eugene  
**Cours :** 420-5G4

## Présentation du projet

Dans ce TP, je devais reprendre un programme de gestion de bibliothèque en C++. Une partie du code était manquante et je devais la compléter pour faire fonctionner le programme. Ensuite, je devais ajouter de nouvelles fonctionnalités et corriger un bug.

## Fonctionnalités réalisées

- **book.cpp :** J'ai complété les méthodes manquantes pour permettre au programme de gérer les livres et de lire les informations provenant des fichiers.

- **Détection des doublons :** J'ai ajouté une vérification pour éviter d'ajouter un livre qui existe déjà dans la bibliothèque.

- **Tri des livres :** J'ai utilisé `std::sort()` pour classer les résultats de recherche par titre ou par auteur.

- **Journal d'activités :** J'ai créé un fichier `activity.log` qui permet d'enregistrer les actions du programme et de garder l'historique même après sa fermeture.

- **Correction du bug :** J'ai corrigé le problème de sauvegarde qui survenait lorsqu'on lançait le programme sans préciser de répertoire de données.

## Question 1 - Notion C++

Une notion que nous avons peu vue en cours est l'utilisation de `ofstream` pour créer et écrire dans des fichiers. Dans mon TP, j'ai utilisé cette fonctionnalité pour créer un journal d'activités qui permet de garder une trace des actions effectuées dans le programme, comme l'ajout ou l'emprunt d'un livre. J'ai aussi utilisé `ios::app`, qui permet d'ajouter de nouvelles informations à la fin du fichier sans effacer les anciennes. C'est important dans ce cas, puisque je veux que le journal garde les activités même après avoir fermé et relancé le programme.

**Exemple de mon fichier `activitylog.cpp` :**

```cpp
ofstream fichier(filePath, ios::app);
```

## Question 2 - Amélioration du programme

Personnellement, si la bibliothèque devait gérer des millions de livres, je pense que MongoDB serait une meilleure solution que les fichiers texte, car ça permettrait de mieux organiser et rechercher les données. Avec des index, on pourrait aussi accélérer les recherches parmi tous ces livres. On pourrait utiliser MongoDB Atlas pour stocker les informations et un pilote MongoDB pour C++ afin que notre programme puisse ajouter, modifier et récupérer les données directement dans la base de données.