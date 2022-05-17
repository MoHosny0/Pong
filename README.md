Nom du projet: Pong

Membre du projet :

    - ALBAGOURY Youssef / p1920140
    - BERARD Thibault / p2005244 
    - HOSNY Mostafa / p2018532
   

Url du git:

  https://forge.univ-lyon1.fr/p1920140/pong
    
  Project ID: 23417

Description brève:

     Au début de la partie, il y a une balle qui apparait au centre de la
    fenêtre et se dirige vers l'un des cotés.

    Les joueurs doivent déplacer les raquettes de haut en bas avec les touches afin de
    taper la balle et changer sa direction de façon à la garder dans le
    terrain.

    Si la balle frappe le haut ou le bas du terrain elle se reflète, elle
    change de direction (Exemple : si la balle frappe le haut du terrain et
    venant de la droite, sa direction se change vers le bas et à gauche et
    vice versa).

    Pour gagner un point il faut que la balle dépasse la raquette de
    l’adversaire et passe à travers son coté. 

But du jeu:
    Le but du jeu pour chacun des deux joueurs est de faire en sorte que l'adversaire ne rattrappe pas la balle. Si la balle atteint la bordure du
    terrain derrière ça raquette, il a alors perdu et son adversaire gagne un point.
    

Compilation:

    Utiliser la commande "make" dans un terminal ouvert dans le dossier "Pong" pour compiler le jeu.
    Utiliser la commande "make docu" dans un terminal ouvert dans le dossier "Pong" pour pour générer la documentation doxygen.


Execution:

    Utiliser la commande "./bin/sdl2" pour lancer la version graphique avec SDL2.
    Utiliser la commande "./bin/txt" pour lancer la version texte dans le terminal.

Utilisation:

   - Le joueur de droite appuit sur la touche "Q" pour se déplacer vers le haut et la touche "A" pour se déplacer vers le bas.
   - Le joueur de gauche appuit sur la touche "P" pour se déplacer vers le haut et la touche "L" pour se déplacer vers le bas.
   - "W" pour quitter le jeu


Fonctionnalités:

    -chanque joueur déplace une raquette horizontalement.
    -La balle se déplace automatiquement aves des vitesses différentes aléatoires.
    -le score se modifie dans le mode texte aprés chaque point.
    -la partie recommence aprés atteindre 10 points et le score se met à 0 dans le mode texte.


Organisation de l'archive :

    - Tous les dossiers se trouvent dans le dossier "Pong"
      avec le Makefile et le ReadMe.

        - Dans le dossier "bin" se trouve l'application "sdl2" et "txt".

        - Dans le dossier "data" se trouve les sprites du jeu.
        
        - Dans le dossier "doc" se trouve la doxygen.

        - Dans le dossier "obj" comporte les fichiers objets ".o" du projet.

        - Dans le dossier "src" on trouve les fichiers ".cpp" et ".h" du projet.
