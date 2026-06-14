#include "view/ViewElementJeu.h"
#include <SFML/Graphics.hpp>
namespace view
{
    view::ViewElementJeu::ViewElementJeu(const entity::ElementJeu& elementJeu,int scale,int hauteurWindow) : elementJeu(elementJeu),scale(scale),hauteurWindow(hauteurWindow)
    {
    };

    sf::Vector2f ViewElementJeu::toVector2f(util::Vecteur vecteur) {
        return sf::Vector2f(vecteur.x / scale, hauteurWindow -vecteur.y/scale);
    };
    sf::Vector2f ViewElementJeu::getPosition() {
        return this->toVector2f(this->elementJeu.position);
    };
    view::ViewElementJeu::~ViewElementJeu()
    {
    };
} // namespace view
