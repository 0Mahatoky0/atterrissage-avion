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
        const util::Vecteur& getPosition() const ;
    };


} // namespace entity
