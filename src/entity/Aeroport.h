#pragma once
#include "entity/ElementJeu.h"
namespace entity 
{
    class Aeroport : ElementJeu 
    {
    private:
        float longeur;

    public:
        Aeroport(util::Vecteur position);
        ~Aeroport();
    };    
} // namespace entity
