#pragma once // Empeche l'inclusion multiple de ce fichier header

#include "Fenetre.hpp"      // Gestion de la fenetre SFML
#include "SceneAccueil.hpp" // Contenu visuel a afficher

// Classe principale : orchestre la fenetre, la scene et la boucle de jeu
class Jeu
{
public:
    // Constructeur : prepare la fenetre et la scene
    Jeu();

    // Lance la boucle principale du jeu
    void lancer();

private:
    Fenetre fenetre_;           // Fenetre du jeu (800x600)
    SceneAccueil sceneAccueil_; // Scene affichee dans la fenetre
};
