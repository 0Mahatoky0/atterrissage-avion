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
        return elementJeu.possition.x >= min.x && elementJeu.possition.x <= max.x 
        && elementJeu.possition.y >= min.y && elementJeu.possition.y <= max.y;
    }
} // namespace entity
