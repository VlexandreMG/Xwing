#include "Jeu.hpp" // Declaration de la classe Jeu

Jeu::Jeu()
    : fenetre_(800, 600, "Xwing"), // Cree une fenetre 800x600 intitulee "Xwing"
      sceneAccueil_()              // Initialise la scene d'accueil
{
}

void Jeu::lancer()
{
    while (fenetre_.estOuverte()) // Boucle tant que la fenetre est ouverte
    {
        fenetre_.gererEvenements(); // Traite clavier et fermeture

        fenetre_.effacer(sceneAccueil_.getCouleurFond()); // Efface l'ecran

        sceneAccueil_.dessiner(fenetre_.getRenderWindow()); // Dessine la scene

        fenetre_.afficher(); // Affiche le resultat a l'ecran
    }
}
