#include "view/ViewAeroport.h"
namespace view
{

    ViewAeroport::ViewAeroport(const entity::Aeroport &aeroport,int scale,int hauteurWindow) : ViewElementJeu(aeroport,scale,hauteurWindow), aeroport(aeroport)
    {
        this->setFillColor(sf::Color::Black);
        this->setSize(sf::Vector2f(aeroport.getLongeur()*scale,100));
        this->mettreAJourPosition();
    }
    ViewAeroport::~ViewAeroport()
    {
    }
    void ViewAeroport::mettreAJourPosition() {
        this->setPosition(this->toVector2f(aeroport.position));
    }
    void ViewAeroport::draw(sf::RenderWindow &window) const
    {
        window.draw(*this);
    }
} // namespace view
