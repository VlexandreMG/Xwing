#include "SceneAccueil.hpp" // Declaration de la classe SceneAccueil

SceneAccueil::SceneAccueil()
    : couleurFond_(20, 30, 60),  // Couleur de fond : bleu fonce (R, G, B)
      cercle_(40.f),              // Cercle de rayon 40 pixels
      barre_(sf::Vector2f(800.f, 40.f)) // Rectangle 800x40 pixels
{
    cercle_.setPosition(360.f, 260.f);              // Position au centre de la fenetre
    cercle_.setFillColor(sf::Color(255, 140, 0));   // Remplissage orange
    cercle_.setOutlineColor(sf::Color::White);      // Contour blanc
    cercle_.setOutlineThickness(3.f);               // Epaisseur du contour : 3 px

    barre_.setPosition(0.f, 560.f);                 // Barre en bas (y = 560)
    barre_.setFillColor(sf::Color(80, 80, 80));     // Remplissage gris
}

sf::Color SceneAccueil::getCouleurFond() const
{
    return couleurFond_; // Retourne la couleur utilisee pour effacer l'ecran
}

void SceneAccueil::dessiner(sf::RenderWindow& fenetre)
{
    fenetre.draw(barre_);  // Dessine la barre grise
    fenetre.draw(cercle_); // Dessine le cercle orange
}
