#include "entity/Avion.h"
#include <iostream>
namespace entity
{
    Avion::Avion(util::Vecteur possition, util::Vecteur capaciteFreinage, util::Vecteur variationAcceleration, float vx, float vitesseDecrochage) : ElementJeu(possition), capaciteFreinage(capaciteFreinage), variationAcceleration(variationAcceleration), acceleration(0, 0), vitesse(vx, 0), vitesseDecrochage(vitesseDecrochage)
    {
    }

    Avion::~Avion()
    {
    }

    void Avion::avancer(float durrerMilliseconde)
    {
        // meetre a jour la vitesse
        vitesse.x += acceleration.x * (durrerMilliseconde/1000);
        vitesse.y += acceleration.y * (durrerMilliseconde/1000);

        // mettre a jour le coordoner x
        possition.x += vitesse.x * (durrerMilliseconde/1000);
        possition.y += vitesse.y * (durrerMilliseconde/1000);
    }

    void Avion::augmenterAccelerationX()
    {
        this->acceleration.x += this->variationAcceleration.x;
    }
    void Avion::diminuerAccelerationX()
    {
        float newAcceleration = this->acceleration.x - this->variationAcceleration.x;
        if (newAcceleration > this->capaciteFreinage.x)
        {
            this->acceleration.x = newAcceleration;
        }
        else
        {
            this->acceleration.x = this->capaciteFreinage.x;
        }
    }

    void Avion::augmenterAccelerationY()
    {
        this->acceleration.y += this->variationAcceleration.y;
    }
    void Avion::diminuerAccelerationY()
    {
        float newAcceleration = this->acceleration.y - this->variationAcceleration.y;
        if (newAcceleration > this->capaciteFreinage.y)
        {
            this->acceleration.y = newAcceleration;
        }
        else
        {
            this->acceleration.y = this->capaciteFreinage.y;
        }
    }
    
} // namespace entity
