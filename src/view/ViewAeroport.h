#pragma once
#include "entity/Aeroport.h"
#include "view/ViewElementJeu.h"
namespace view
{
    class ViewAeroport : public view::ViewElementJeu , public sf::RectangleShape
    {
    private:
        const entity::Aeroport& aeroport;
    public:
        ViewAeroport(const entity::Aeroport &aeroport,int scale,int hauteurWindow);
        ~ViewAeroport();
        void mettreAJourPosition() override;
        void draw(sf::RenderWindow &window) const override ;
    };
} // namespace view
