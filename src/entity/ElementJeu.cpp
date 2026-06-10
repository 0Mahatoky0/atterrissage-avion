#include "ElementJeu.h"
namespace entity
{
    ElementJeu::ElementJeu(util::Vecteur position) : position(position)
    {
    }

    ElementJeu::~ElementJeu()
    {
    }

    util::Vecteur& ElementJeu::getPosition(){
        return position;
    }
} // namespace entity
