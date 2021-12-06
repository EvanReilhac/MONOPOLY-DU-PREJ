cmake_minimum_required(VERSION 3.20)
project(MONOP_Evan C)

set(CMAKE_C_STANDARD 99)

add_executable(MONOP_Evan main.c structure.c structure.h MACRO.c MACRO.h fonctions.c fonctions.h propriete.c propriete.h joueur.c joueur.h Menu.c Menu.h Deplacement.c Deplacement.h Cartes.c Cartes.h)
