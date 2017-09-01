# minishell
Projet 42 - Langage C - MiniSHell
-----------------------------------------------------------------------------------------------------------------------------------------------

Le projet Minishell nous permet de plonger au coeur d'un système Unix et de découvrir une partie importante de l’API d’un tel système: la création et la synchronisation de processus. 

Le lancement d’une commande dans un shell implique la création d’un nouveau processus dont le processus parent doit monitorer l’exécution et l’état final.

Cet ensemble de fonctions sera le coeur de notre Minishell.

Vous trouverez à votre disposition le sujet du projet sous format PDF dans le repository.

Comme d'habitude, toutes les fonctions présentes ont été prototypées dans le fichier "minishell.h" et nous utilisons egalement notre Libft mise à jour avec les fonctions précédemment utilisées au cours des derniers projets.

Dans ce projet, j'ai réalisé comme demandé dans le sujet, une série de builtins avec certaines options, voici la liste:

- env
  + -i (Démarrer  avec  un  environnement  vide, et non pas avec l'environnement hérité par env. cf: man env)

- cd
  - . (Affiche le répertoire courant)
  
  - ~ (Change de répertoire en fonction de l'attribut de la variable d'environnement "HOME")
  
  - - (Reviens dans le répertoire précédent (contenu dans la variable d'environnement "OLDPWD")
  
  - Absolute/path
  
  - Relative/path

- setenv (exemple: setenv FOO=bar <-- La variable FOO avec pour valeur "bar" est ajouté a l'environnement actuel)
- unsetenv (Supprime une variable et son contenu de l'environnement actuel)
- echo (version minimaliste)
- exit (Quitte le programme)

Pour finir, l'ensemble du projet est compilable dans un environnement UNIX, via le Makefile. Les règles a dispositions sont les suivantes:
- make
  - clean 
  - fclean
  - re
  
-----------------------------------------------------------------------------------------------------------------------------------------------
mtacnet@student.42.fr
