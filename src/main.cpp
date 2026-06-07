#include<iostream>
#include "entity/Avion.h"
#include "entity/Aeroport.h"
int main() {
    using util::Vecteur;
    entity::Avion avion = entity::Avion(Vecteur(0,0),Vecteur(0,0),Vecteur(10,2),500,300);
    entity::Aeroport aero = entity::Aeroport(Vecteur(8000,0));
    avion.Voler();
    return 0;
}