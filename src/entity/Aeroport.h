#pragma once
#include "entity/ElementJeu.h"
namespace entity 
{
    class Aeroport : ElementJeu 
    {
    private:
        int longeur;

    public:
        Aeroport(util::Vecteur position);
        ~Aeroport();
    };    
} // namespace entity
