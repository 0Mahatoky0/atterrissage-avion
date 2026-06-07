#pragma once
#include "util/Vecteur.h"
#include "entity/ElementJeu.h"
namespace entity
{
    class Avion : public ElementJeu
    {
    private:
        util::Vecteur vitesse;
        util::Vecteur acceleration;
        util::Vecteur variationAcceleration;
        util::Vecteur capaciteFreinage;

        int vitesseDecrochage;

    public:
        Avion(util::Vecteur possition, util::Vecteur capaciteFreinage, util::Vecteur variationAcceleration, int vx, int vitesseDecrochage);
        ~Avion();
        void Voler();
    };
} // namespace entity
