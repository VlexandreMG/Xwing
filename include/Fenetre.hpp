#pragma once // Empeche l'inclusion multiple de ce fichier header

#include <SFML/Graphics.hpp> // Module SFML pour la fenetre et le rendu
#include <string>            // Pour le type std::string (titre de la fenetre)

// Classe qui encapsule la fenetre SFML et la gestion des evenements
class Fenetre
{
public:
    // Constructeur : cree une fenetre avec largeur, hauteur et titre
    Fenetre(unsigned int largeur, unsigned int hauteur, const std::string& titre);

    // Retourne true tant que la fenetre est ouverte
    bool estOuverte() const;

    // Traite les evenements (fermeture, touches clavier, etc.)
    void gererEvenements();

    // Efface l'ecran avec une couleur de fond
    void effacer(const sf::Color& couleur);

    // Affiche le contenu dessine a l'ecran
    void afficher();

    // Donne acces a la fenetre SFML pour y dessiner des formes
    sf::RenderWindow& getRenderWindow();

private:
    sf::RenderWindow fenetre_; // Objet fenetre SFML (membre de la classe)
};
