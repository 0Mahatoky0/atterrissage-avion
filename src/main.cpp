#include<iostream>
#include "entity/Avion.h"
int main() {
    using util::Vecteur;
    entity::Avion avion = entity::Avion(Vecteur(0,0),Vecteur(0,0),Vecteur(10,2),500,300);
    avion.Voler();
    return 0;
}