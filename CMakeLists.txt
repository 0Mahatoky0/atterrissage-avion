# version minimale de Cmake requise pour executer ce script
cmake_minimum_required(VERSION 3.10)

# Nom du projet et langue utiliser 
project(avion CXX)

# creation de l executable avec nom avion a partire de main
add_executable(avion main.cpp)