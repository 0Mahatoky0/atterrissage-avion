#include <iostream>
#include "entity/Avion.h"
#include "entity/Aeroport.h"
int main()
{
    using util::Vecteur;
    entity::Avion avion = entity::Avion(Vecteur(0, 0), Vecteur(-40, -6), Vecteur(10, 2), 500, 300);
    entity::Aeroport aero = entity::Aeroport(Vecteur(8000, 0));
    
    avion.augmenterAccelerationX();

    avion.avancer(1000);
    avion.avancer(1000);

    std::cout << "valeur : " << avion.possition.x << std::endl;
    return 0;
}