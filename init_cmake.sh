#!/bin/bash
# cree le dossier de build pour ne pas puluer l environnement
mkdir build
cp -r assets/ build/
cd build

# cree l outil de build a partir du fichier CmakeLists.txt
cmake ..

# effecuter le build
cmake --build .

# executer le fichier binaire cree 
../build/avion

# revenir dans le dossier principal
cd ..