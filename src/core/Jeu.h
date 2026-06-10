#pragma once
#include "entity/Avion.h"
#include "entity/Aeroport.h"
#include "entity/ZoneJeu.h"
namespace core
{
    class Jeu
    {
    private:
        float tempsPasser;
        entity::Aeroport aeroport;
        entity::Avion avion;
        entity::ZoneJeu zoneJeu;

    public:
        Jeu(entity::Aeroport aeroport,
            entity::Avion avion,
            entity::ZoneJeu zoneJeu);
        ~Jeu();
        void simmuler(float durrerMiliseconde);
    };

} // namespace core
