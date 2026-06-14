#include "entity/Aeroport.h"
namespace entity
{
    Aeroport::Aeroport(util::Vecteur position,float longeur) : ElementJeu(position) ,longeur(longeur)
    {
    }
    
    Aeroport::~Aeroport()
    {
    }

    const bool Aeroport::siege(ElementJeu el) {
        return el.position.x >= this->position.x && el.position.x <= this->position.x + this->longeur && el.position.y <= this->position.y;
    }

    const float Aeroport::getLongeur() const {
        return this->longeur;
    }
} // namespace entity
