#include "entity/Avion.h"
#include <iostream>
namespace entity
{
    Avion::Avion() {

    }

    Avion::~Avion() {

    }

    void Avion::Voler() {
        std::cout << "L avion vole" << std::endl ;
    }
} // namespace entity
