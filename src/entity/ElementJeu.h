#pragma once
#include "util/Vecteur.h"
namespace entity
{
    class ElementJeu
    {
    public:
        util::Vecteur position;

    public:
        ElementJeu(util::Vecteur position);
        ~ElementJeu();
        util::Vecteur& getPosition();
    };


} // namespace entity
