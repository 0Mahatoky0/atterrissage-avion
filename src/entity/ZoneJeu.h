#pragma once
#include "util/Vecteur.h"
#include "entity/ElementJeu.h"
namespace entity
{
    class ZoneJeu
    {
    public:
        util::Vecteur max;
        util::Vecteur min;

    public:
        ZoneJeu(util::Vecteur max,util::Vecteur min);
        ~ZoneJeu();
        bool contient(entity::ElementJeu& elementJeu);
        const float getLongeur();
        const float getHauteur();
    };
} // namespace entity
