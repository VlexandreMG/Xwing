#pragma once // Empeche l'inclusion multiple de ce fichier header

#include <SFML/Graphics.hpp> // Module SFML pour les formes et couleurs

// Classe qui gere le contenu visuel affiche dans la fenetre
class SceneAccueil
{
public:
    // Constructeur : initialise les formes et couleurs de la scene
    SceneAccueil();

    // Retourne la couleur de fond de la scene
    sf::Color getCouleurFond() const;

    // Dessine tous les elements de la scene dans la fenetre passee en parametre
    void dessiner(sf::RenderWindow& fenetre);

private:
    sf::Color couleurFond_;       // Couleur de fond (bleu fonce)
    sf::CircleShape cercle_;      // Cercle orange au centre
    sf::RectangleShape barre_;    // Barre grise en bas de l'ecran
};
