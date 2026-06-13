## 1 - Création de la fenêtre 
    - Pourquoi le CMakeLists et le Makefile 
# Makefile 
    -> C'est comme un bash mais en plus inteligent 
    Bash : refait tout de A à Z 
    Makefile : Jereny ze niova dia iny fotsn no apiny 
# CMakeLists 
    -> Créer le fichier Makefile à executer 

# Zavatra nataoko 
    - Fafana le Makefile 
    - Amboarina le CMakeLists 
    - Créer un makefile intelligent dans le build 
```bash
    cmake -B build
```
    - Compilation du code 
```bash
    cmake --build build
```
    - Execution 
```bash
    ./build/xwing 
```

## Fenetre.hpp
```cpp
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
```
    - Que signifie pragma once *à tester s'il n'y a pas le pragma once*
        ->  Il lit dans fenetre.hpp puis quand il va lire Jeu.hpp , il verra le include de fenetre.hpp et il va dire que : "ohh je l'ai déja lue , plus besoin de lire "
    - Explique "std::" 
        -> Signifie standard , otrn hoe tiroir dia misy string 
    - Explique "sf::"
        -> Même chose que std fa pour SFML . 
    - A quoi sert le "&" , par exemple sur const std::string& titre
    - C'est quoi le RenderWindow 
        -> Classe pour faire apparaître une fenêtre noire 
            -> Window communique avec mon OS 
            -> Render , c'est l'ardoise où je met des trucs . 
    - Explication du const 
        -> const veut dire constante donc personne ne peut changer la valeur qu'elle possède

## Fenetre.cpp -> Affichage de la fenetre maina be 
```cpp
#include "../include/Fenetre.hpp" // Declaration de la classe Fenetre

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

```
    -> Unsigned 

## SceneAccueil.hpp 
```cpp
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
```
## SceneAccueil.cpp -> Contenu ao @ ilay fenetre *Ataoko farany izay tsotra fa be zavatra b izy zao*
```cpp
#include "../include/SceneAccueil.hpp" // Declaration de la classe SceneAccueil

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
```
    -> Pourquoi il réappelle le nom de la classe quand on fait des fonction 
## Jeu.hpp 
```cpp
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

```
## Jeu.cpp -> Manambatra an'izy roa 
```cpp
#include "../include/Jeu.hpp" // Declaration de la classe Jeu

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

```