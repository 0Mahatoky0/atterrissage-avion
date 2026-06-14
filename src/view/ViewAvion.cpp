#include <entity/Avion.h>
#include "view/ViewAvion.h"
#include <iostream>
namespace view
{
    ViewAvion::ViewAvion(const entity::Avion &avion, const int scale, int hauteurWindow) : avion(avion), ViewElementJeu(avion,scale,hauteurWindow)
    {
        // charger l image  de l avion
        this->texture.loadFromFile("assets/avion.png");
        this->setTexture(texture);

        // mettre a jour la position
        this->mettreAJourPosition();
    }

    void ViewAvion::mettreAJourPosition() {
        this->setPosition(this->toVector2f(avion.position));
    };

    void ViewAvion::draw(sf::RenderWindow &window) const
    {
        window.draw(*this);
    }

    ViewAvion::~ViewAvion()
    {
    }
} // namespace view
