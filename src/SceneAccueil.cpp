#include "../include/SceneAccueil.hpp" // Declaration de la classe SceneAccueil

SceneAccueil::SceneAccueil()
    : couleurFond_(20, 30, 60),  // Couleur de fond : bleu fonce (R, G, B)
{

}

sf::Color SceneAccueil::getCouleurFond() const
{
    return couleurFond_; // Retourne la couleur utilisee pour effacer l'ecran
}

void SceneAccueil::dessiner(sf::RenderWindow& fenetre)
{
    // Aucun contenu visuel à dessiner pour l'instant
}

