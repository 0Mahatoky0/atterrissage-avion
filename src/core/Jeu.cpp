#include "core/Jeu.h"

namespace core
{
    Jeu::Jeu(entity::Aeroport aeroport,
             entity::Avion avion,
             entity::ZoneJeu zoneJeu) : aeroport(aeroport), avion(avion), zoneJeu(zoneJeu)
    {
    }

    Jeu::~Jeu()
    {
    }

    void Jeu::simmuler(float durrerMiliseconde)
    {
        avion.simuler(durrerMiliseconde);
        if(!zoneJeu.contient(avion)) {
            //erreur sortie hors du zone de jeu
        }

        if(aeroport.siege(avion)) {
            avion.vitesse.y = 0;
            avion.position.y = aeroport.getPosition().x;
        }
    }
} // namespace core
