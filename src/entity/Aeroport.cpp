#include "entity/Aeroport.h"
namespace entity
{
    Aeroport::Aeroport(util::Vecteur position,float longeur) : ElementJeu(position) ,longeur(longeur)
    {
    }
    
    Aeroport::~Aeroport()
    {
    }

    bool Aeroport::siege(ElementJeu el) {
        return el.possition.x >= this->possition.x && el.possition.x <= this->possition.x + this->longeur && el.possition.y <= this->possition.y;
    }
} // namespace entity
