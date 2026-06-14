#pragma once
#include <entity/Avion.h>
#include "view/ViewElementJeu.h"
#include <SFML/Graphics.hpp>
namespace view
{
    class ViewAvion : public ViewElementJeu,public sf::Sprite
    {
    private:
        sf::Texture texture;
        const std::string imageAvion = "assets/avion.png";
        const entity::Avion& avion;

    public:
        ViewAvion(const entity::Avion &avion,const int scale,int longeurWindow);
        ~ViewAvion();
        void draw(sf::RenderWindow& window) const override;
        void mettreAJourPosition() override;
    };


} // namespace view
