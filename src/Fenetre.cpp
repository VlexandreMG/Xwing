#include "Fenetre.hpp" // Declaration de la classe Fenetre

Fenetre::Fenetre(unsigned int largeur, unsigned int hauteur, const std::string& titre)
    : fenetre_(sf::VideoMode(largeur, hauteur, 32), titre) // Initialise la fenetre avec le mode video
{
    fenetre_.setFramerateLimit(60); // Limite a 60 images par seconde
}

bool Fenetre::estOuverte() const
{
    return fenetre_.isOpen(); // Delegue a SFML la verification d'ouverture
}

void Fenetre::gererEvenements()
{
    sf::Event event; // Objet qui stocke un evenement

    while (fenetre_.pollEvent(event)) // Lit tous les evenements en attente
    {
        if (event.type == sf::Event::Closed) // Clic sur la croix
            fenetre_.close(); // Ferme la fenetre

        if (event.type == sf::Event::KeyPressed) // Touche enfoncee
        {
            if (event.key.code == sf::Keyboard::Escape) // Touche Echap
                fenetre_.close(); // Ferme la fenetre
        }
    }
}

void Fenetre::effacer(const sf::Color& couleur)
{
    fenetre_.clear(couleur); // Remplit l'ecran avec la couleur passee en parametre
}

void Fenetre::afficher()
{
    fenetre_.display(); // Affiche le buffer de dessin a l'ecran
}

sf::RenderWindow& Fenetre::getRenderWindow()
{
    return fenetre_; // Retourne une reference pour permettre le dessin depuis l'exterieur
}
