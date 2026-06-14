#include "core/Jeu.h"
#include <iostream>
namespace core
{
    Jeu::Jeu(entity::Aeroport& aeroport,
             entity::Avion& avion,
             entity::ZoneJeu& zoneJeu) : aeroport(aeroport), avion(avion), zoneJeu(zoneJeu),tempsPasser(0)
    {
        
    }

    Jeu::~Jeu()
    {
    }

    void Jeu::resetTempsPasser() {
        this->tempsPasser = 0;
    }

    void Jeu::incrementTempsPasser(float val) {
        this->tempsPasser += val;
    }

    const float Jeu::getTempsPasser() const {
        return this->tempsPasser;
    }

    void Jeu::simmuler(float durrerMiliseconde)
    {
        avion.simuler(durrerMiliseconde);
        if(!zoneJeu.contient(avion)) {
            //erreur sortie hors du zone de jeu
        }

        if(avion.getPosition().x >= aeroport.position.x && avion.getPosition().y <= aeroport.getPosition().y) {
              avion.position.y = aeroport.getPosition().y;
              avion.vitesse.y = 0;
            std::cout << "L avion aterrie" << std::endl;
        }

        if(aeroport.siege(avion)) {
            avion.vitesse.y = 0;
            avion.position.y = aeroport.getPosition().y;
        }
    };

    entity::Aeroport& Jeu::getAeroport() {
        return aeroport;
    };
    entity::Avion& Jeu::getAvion() {
        return avion;
    };
    entity::ZoneJeu&  Jeu::getZoneJeu() {
        return zoneJeu;
    };
} // namespace core
