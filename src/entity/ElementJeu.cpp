#include "ElementJeu.h"
namespace entity
{
    ElementJeu::ElementJeu(util::Vecteur position) : position(position)
    {
    }

    ElementJeu::~ElementJeu()
    {
    }

    const util::Vecteur& ElementJeu::getPosition() const {
        return position;
    }
} // namespace entity
