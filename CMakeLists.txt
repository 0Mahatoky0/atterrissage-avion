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
)

# creation de l executable avec nom avion a partire de main
add_executable(avion ${SOURCES})

# configuerer le fihcier src comme le dossier source 
target_include_directories(avion PRIVATE src)