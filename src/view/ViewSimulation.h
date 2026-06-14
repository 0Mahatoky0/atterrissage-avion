#pragma once
#include "core/Jeu.h"
#include <SFML/Graphics.hpp>
namespace view
{
    class ViewSimulation
    {
    private:
        const core::Jeu& jeu;

        const int VUE_PROFIL;
        const int VUE_ARRIERE;
        const int VUE_COURANTE;
        const int scale;

        //image utile
        sf::Texture TEXTURE_AVION_PROFIL;
        sf::Texture TEXTURE_AVION_ARRIERE;

        //dessin des composants de jeu
        sf::RectangleShape aeroportRect;
        sf::Sprite avionSprite;

        // fonction pour dessiner 
    public:
        void dessinerVueProfil(sf::RenderWindow &window);
        void dessinerAvionProfil(sf::RenderWindow &window);
        void dessinerAeroportProfil(sf::RenderWindow &window);

        //void dessinerVueArriere(sf::RenderWindow &window);
        void dessinerAvionVueArriere(sf::RenderWindow &window);
        //void dessinerAeroportVueArriere(sf::RenderWindow &window);

        sf::Vector2f toVector2f(sf::RenderWindow &window,util::Vecteur vecteur);
    public:
        //void dessiner(sf::RenderWindow &window);
        //void mettreAJour();
        ViewSimulation(const core::Jeu &jeu,const int scale);
        //~ViewSimulation();
    };
} // namespace view
