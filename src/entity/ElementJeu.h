#pragma once
#include "util/Vecteur.h"
namespace entity
{
    class ElementJeu
    {
    protected:
        util::Vecteur possition;

    public:
        ElementJeu(util::Vecteur possition);
        ~ElementJeu();
    };

} // namespace entity
