#include <iostream>
#include "entity/Avion.h"
#include "entity/Aeroport.h"
#include "entity/ZoneJeu.h"
int main()
{
    using util::Vecteur;
    entity::Avion avion = entity::Avion(Vecteur(0, 0), Vecteur(-40, -6), Vecteur(10, 2), 500, 300);
    entity::Aeroport aero = entity::Aeroport(Vecteur(8000, 0));
    entity::ZoneJeu zone = entity::ZoneJeu(Vecteur(9000,10000),Vecteur(0,0));

    std::cout << "La zone contient avion : " << zone.contient(avion) << std::endl;
    avion.avancer(1000);

    while (zone.contient(avion))
    {
        avion.avancer(1000);
    }
    
    std::cout << "valeur : " << avion.possition.x << std::endl;
    return 0;
}