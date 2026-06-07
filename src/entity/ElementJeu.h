#pragma once
#include "util/Vecteur.h"
namespace entity
{
    class ElementJeu
    {
    public:
        util::Vecteur possition;

    public:
        ElementJeu(util::Vecteur possition);
        ~ElementJeu();
    };

} // namespace entity
