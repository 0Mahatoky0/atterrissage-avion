#include <iostream>
#include "entity/Avion.h"
#include "entity/Aeroport.h"
#include "entity/ZoneJeu.h"
int main()
{
    using util::Vecteur;
    entity::Avion avion = entity::Avion(Vecteur(0, 0), Vecteur(-40, -6), Vecteur(10, 2), 500, 300);
    entity::Aeroport aero = entity::Aeroport(Vecteur(8000, 0),500);
    entity::ZoneJeu zone = entity::ZoneJeu(Vecteur(9000,10000),Vecteur(0,0));

    //std::cout << "La zone contient avion : " << zone.contient(avion) << std::endl;
    //avion.avancer(1000);

    avion.possition.x = 8500;
    avion.possition.y = -5;

    std::cout << "valeur : " << aero.siege(avion) << std::endl;
    return 0;
}