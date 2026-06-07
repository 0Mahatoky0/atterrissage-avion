#include "entity/Avion.h"
#include <iostream>
namespace entity
{
    Avion::Avion(util::Vecteur possition, util::Vecteur capaciteFreinage, util::Vecteur variationAcceleration, int vx, int vitesseDecrochage) : ElementJeu(possition), capaciteFreinage(capaciteFreinage), variationAcceleration(variationAcceleration), acceleration(0, 0), vitesse(vx, 0), vitesseDecrochage(vitesseDecrochage)
    {
    }

    Avion::~Avion()
    {
    }

    void Avion::Voler()
    {
        std::cout << "L avion vole" << std::endl;
    }
} // namespace entity
