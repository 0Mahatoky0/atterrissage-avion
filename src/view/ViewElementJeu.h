#pragma once
#include "entity/ElementJeu.h"
#include <SFML/Graphics.hpp>
namespace view
{
    class ViewElementJeu 
    {
    private:
        const entity::ElementJeu& elementJeu;
        const int scale;
        const int hauteurWindow;
    public:
        ViewElementJeu(const entity::ElementJeu& elementJeu,int scale,int hauteurWindow);
        ~ViewElementJeu();
        virtual void draw(sf::RenderWindow& window) const = 0;
        sf::Vector2f toVector2f(util::Vecteur vecteur);
        sf::Vector2f getPosition();
        virtual void mettreAJourPosition() = 0;
    };
} // namespace view
