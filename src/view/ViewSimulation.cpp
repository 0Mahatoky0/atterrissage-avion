#include "core/Jeu.h"
#include <SFML/Graphics.hpp>
#include "view/ViewSimulation.h"
#include <iostream>
namespace view
{
    //constructeur
    view::ViewSimulation::ViewSimulation(const core::Jeu& jeu,int scale) : jeu(jeu), VUE_PROFIL(1) ,VUE_ARRIERE(2) , VUE_COURANTE(VUE_PROFIL),scale(scale) {
        TEXTURE_AVION_PROFIL.loadFromFile("assets/avion.png");
        TEXTURE_AVION_ARRIERE.loadFromFile("assets/avion_arriere.png");
    }

    // -- dessin en arriere de l avion -- //
    void view::ViewSimulation::dessinerAvionVueArriere(sf::RenderWindow &window) {
        this->avionSprite.setTexture(TEXTURE_AVION_ARRIERE);
        this->avionSprite.setPosition(window.getSize().x /2-125,100);
        window.draw(this->avionSprite);
    }

    void view::ViewSimulation::dessinerAeroportVueArriere(sf::RenderWindow &window) {
        this->aeroportRect.setFillColor(sf::Color::Green);
        
        float DISTANCE_MIN_VISON = -10000;
        float tailleAeroport = 0;
        if(jeu.getDistanceAvionAeroport() <= DISTANCE_MIN_VISON) {
            tailleAeroport = 20;
        }

        if(jeu.getDistanceAvionAeroport() > DISTANCE_MIN_VISON && 
            jeu.getDistanceAvionAeroport() <= 0) {
                float invers = jeu.getDistanceAvionAeroport() * window.getSize().x / DISTANCE_MIN_VISON;
                tailleAeroport = window.getSize().x  - invers;
                std::cout << "invers : " << invers << std::endl;
                std::cout << "taille : " << tailleAeroport << std::endl;
            }
        this->aeroportRect.setSize(sf::Vector2f(tailleAeroport,100));
        this->aeroportRect.setPosition(0,500);
        window.draw(this->aeroportRect);

    }

    // -- dessin profil -- //

    void view::ViewSimulation::dessinerVueProfil(sf::RenderWindow &window) {
        //initialiser vue avion profil
        this->dessinerAeroportProfil(window);
        this->dessinerAvionProfil(window);
    }

    void view::ViewSimulation::dessinerAvionProfil(sf::RenderWindow &window) {
        this->avionSprite.setTexture(TEXTURE_AVION_PROFIL);
        this->avionSprite.setPosition(toVector2f(window,jeu.getAvion().getPosition()));
        window.draw(this->avionSprite);
    }

    void view::ViewSimulation::dessinerAeroportProfil(sf::RenderWindow &window) {
        this->aeroportRect.setSize(sf::Vector2f(this->jeu.getAeroport().getLongeur()*scale,60));
        this->aeroportRect.setFillColor(sf::Color::Black);
        this->aeroportRect.setPosition(toVector2f(window,this->jeu.getAeroport().getPosition()));
        window.draw(this->aeroportRect);
    }

    sf::Vector2f view::ViewSimulation::toVector2f(sf::RenderWindow &window, util::Vecteur vecteur) {
        return sf::Vector2f(vecteur.x/scale, window.getSize().y -vecteur.y/scale);
    }
} // namespace view
