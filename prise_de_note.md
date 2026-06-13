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

## Fenetre hpp -> 
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
    - Que signifie pragma once 
    - Explique "std::" 
        -> Signifie standard , otrn hoe tiroir dia misy string 
    - Explique "sf::"
        -> Même chose que std fa pour SFML . 
    - A quoi sert le "&" , par exemple sur const std::string& titre
    - C'est quoi le RenderWindow 
        -> Classe pour faire apparaître une fenêtre noire 
            -> Window communique avec mon OS 
            -> Render , c'est l'ardoise où je met des trucs . 