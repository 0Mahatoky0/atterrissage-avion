#pragma once
#include "util/Vecteur.h"
#include "entity/ElementJeu.h"
namespace entity
{
    class Avion : public ElementJeu
    {
    public:
        util::Vecteur vitesse;
        util::Vecteur acceleration;
        util::Vecteur variationAcceleration;
        util::Vecteur capaciteFreinage;

        float vitesseDecrochage;

    public:
        Avion(util::Vecteur possition, util::Vecteur capaciteFreinage, util::Vecteur variationAcceleration, float vx, float vitesseDecrochage);
        ~Avion();

        void avancer(float durrerMilliseconde);
        void augmenterAccelerationX();
        void diminuerAccelerationX();
        void augmenterAccelerationY();
        void diminuerAccelerationY();
        bool decrouche();
    };
} // namespace entity
