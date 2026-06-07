#pragma once
#include "entity/ElementJeu.h"
namespace entity 
{
    class Aeroport : ElementJeu 
    {
    private:
        float longeur;

    public:
        Aeroport(util::Vecteur position,float longeur);
        ~Aeroport();
        bool siege(ElementJeu element);
    };    
} // namespace entity
