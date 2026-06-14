#include <SFML/Graphics.hpp>
#include <iostream>
#include "entity/Avion.h"
#include "entity/Aeroport.h"
#include "entity/ZoneJeu.h"
#include "util/Vecteur.h"
#include "core/Jeu.h"
#include "view/ViewAvion.h"
#include "view/ViewAeroport.h"
#include "view/ViewSimulation.h"
#include <string>
float SCALE_BACKEND = 10;
int main()
{
    // initialisation des elements de jeu
    entity::ZoneJeu zoneJeu(util::Vecteur(13000, 7000), util::Vecteur(-20000, 0));
    entity::Avion avion(util::Vecteur(10, 4000), util::Vecteur(-40, -20), util::Vecteur(10, 5), 500, 300);
    entity::Aeroport aeroport(util::Vecteur(6000, 1000), 1000);

    // creation de la fenetre
    sf::RenderWindow window(sf::VideoMode(1000, 700), "Ma fenetre");

    // timer pour calculer le durer entre frame
    sf::Clock clock;

    // creation du veu avion
    view::ViewAvion viewAvion(avion, SCALE_BACKEND, 700);

    // information sur l avion
    sf::Font font;
    font.loadFromFile("assets/Pliant.ttf");

    sf::Text infoVitesse;
    infoVitesse.setString("vitesse : (" + std::to_string(avion.vitesse.x) +
                          "," + std::to_string(avion.vitesse.y) + ") m/s");
    infoVitesse.setPosition(100, 10);
    infoVitesse.setFont(font);
    infoVitesse.setCharacterSize(30);
    infoVitesse.setFillColor(sf::Color::White);

    sf::Text infoAcceleration;
    infoAcceleration.setString("Acceleration : (" + std::to_string(avion.acceleration.x) +
                               "," + std::to_string(avion.acceleration.y) + ") m/s");
    infoAcceleration.setPosition(100, 100);
    infoAcceleration.setFont(font);
    infoAcceleration.setCharacterSize(30);
    infoAcceleration.setFillColor(sf::Color::White);

    core::Jeu jeu(aeroport, avion, zoneJeu);
    const view::ViewAeroport viewAeroport(jeu.getAeroport(), SCALE_BACKEND, 700);

    sf::Text tempsPasser;
    tempsPasser.setString("Temps passer : (" + std::to_string(jeu.getTempsPasser()) +
                          " s");
    tempsPasser.setPosition(sf::Vector2f(100, 200));
    tempsPasser.setFont(font);

    view::ViewSimulation viewSimulation(jeu, SCALE_BACKEND);

    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::E)
                {
                    jeu.getAvion().augmenterAccelerationY();
                    //   std::cout << "Augmentation de l acceleration Y" << std::endl;
                }
                if (event.key.code == sf::Keyboard::D)
                {
                    jeu.getAvion().diminuerAccelerationY();
                    //  std::cout << "Diminuation de l acceleration Y" << std::endl;
                }
                if (event.key.code == sf::Keyboard::F)
                {
                    jeu.getAvion().augmenterAccelerationX();
                    // std::cout << "Augmentation de l acceleration X" << std::endl;
                }
                if (event.key.code == sf::Keyboard::S)
                {
                    jeu.getAvion().diminuerAccelerationX();
                    // std::cout << "Diminuation de l acceleration X" << std::endl;
                }
            }
        }
        // mise a jour du logique
        jeu.simmuler(dt * 1000);
        jeu.incrementTempsPasser(dt);
        window.clear(sf::Color::Cyan);

        // viewAeroport.draw(window);
        viewAvion.mettreAJourPosition();
        // mise a jour de l affichage
        infoVitesse.setString("vitesse : (" + std::to_string(jeu.getAvion().vitesse.x) + "," + std::to_string(jeu.getAvion().vitesse.y) + ") m/s");

        infoAcceleration.setString("Acceleration : (" + std::to_string(jeu.getAvion().acceleration.x) +
                                   "," + std::to_string(jeu.getAvion().acceleration.y) + ") m/s");
        tempsPasser.setString("Temps passer : (" + std::to_string(jeu.getTempsPasser()) +
                              " s");

        // viewAvion.draw(window);
        // viewSimulation.dessinerAeroportProfil(window);
        // viewSimulation.dessinerAvionProfil(window);
        viewSimulation.dessinerVueProfil(window);
        // viewSimulation.dessinerAvionVueArriere(window);

        std::cout << "Distance piste : " << jeu.getDistanceAvionAeroport() << std::endl;
        std::cout << "Altitude piste : " << jeu.getAltitudeAvionAeroport() << std::endl;
        // window.draw(infoVitesse);
        // window.draw(infoAcceleration);
        // window.draw(tempsPasser);
        window.display();
    };

    return 0;
}