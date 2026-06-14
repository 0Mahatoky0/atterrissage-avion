# version minimale de Cmake requise pour executer ce script
cmake_minimum_required(VERSION 3.10)
# Nom du projet et langue utiliser 
project(avion CXX)

# confige des variable qui von contenir les fichiers sources
set(
    SOURCES
    # ajout des fichier a suivre par cmake
    src/main.cpp
    src/entity/Avion.cpp
    src/entity/Aeroport.cpp
    src/entity/ZoneJeu.cpp
    src/entity/ElementJeu.cpp
    src/util/Vecteur.cpp
    src/core/Jeu.cpp
    src/view/ViewElementJeu.cpp
    src/view/ViewAeroport.cpp
    src/view/ViewAvion.cpp
    src/view/ViewSimulation.cpp
)



# creation de l executable avec nom avion a partire de main
add_executable(avion ${SOURCES})

# configuerer le fihcier src comme le dossier source 
target_include_directories(avion PRIVATE src)

# execution avec les librairie graphique
target_link_libraries(avion
    sfml-graphics
    sfml-window
    sfml-system
)