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
        entity::Avion& avion;
        entity::ZoneJeu zoneJeu;

    public:
        Jeu(entity::Aeroport& aeroport,
            entity::Avion& avion,
            entity::ZoneJeu& zoneJeu);
        ~Jeu();
        void simmuler(float durrerMiliseconde);
        const entity::Aeroport& getAeroport() const ;
        entity::Avion& getAvion();
        entity::ZoneJeu& getZoneJeu();
        void resetTempsPasser();
        const float getTempsPasser() const ;
        const entity::Avion& getAvion() const;
        void incrementTempsPasser(float val);
    };



} // namespace core
