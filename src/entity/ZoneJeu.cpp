#include"ZoneJeu.h"
namespace entity
{
    ZoneJeu::ZoneJeu(util::Vecteur max,util::Vecteur min) : max(max) , min(min)
    {
    }

    ZoneJeu::~ZoneJeu()
    {
    }

     bool ZoneJeu::contient(entity::ElementJeu& elementJeu) {
        return elementJeu.position.x >= min.x && elementJeu.position.x <= max.x 
        && elementJeu.position.y >= min.y && elementJeu.position.y <= max.y;
    }
} // namespace entity
