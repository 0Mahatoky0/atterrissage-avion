#include "core/Jeu.h"
#include <SFML/Graphics.hpp>
#include "view/ViewSimulation.h"
#include <iostream>
namespace view
{
    //constructeur
    view::ViewSimulation::ViewSimulation(const core::Jeu& jeu,int scale) : jeu(jeu), VUE_PROFIL(1) ,VUE_ARRIERE(2) , VUE_COURANTE(VUE_PROFIL),scale(scale) {
        TEXTURE_AVION_PROFIL.loadFromFile("assets/avion.png");
        TEXTURE_AVION_ARRIERE.loadFromFile("avion_arriere.webp");
    }

    void view::ViewSimulation::dessinerVueProfil(sf::RenderWindow &window) {
        //initialiser vue avion profil
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
        std::cout << "La position de la piste y : " <<  this->aeroportRect.getPosition().y << std::endl;
        std::cout << "La position de la piste x : " <<  this->aeroportRect.getPosition().x << std::endl;
    }

    sf::Vector2f view::ViewSimulation::toVector2f(sf::RenderWindow &window, util::Vecteur vecteur) {
        return sf::Vector2f(vecteur.x/scale, window.getSize().y -vecteur.y/scale);
    }
} // namespace view
