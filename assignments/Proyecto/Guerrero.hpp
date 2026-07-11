#pragma once
#include "Personaje.hpp"
#include <iostream>

class Guerrero : public Personaje{
    public:
        Guerrero();
        Guerrero(int, int, int, int, int);
        int getFuerza() const;
        void setFuerza(int);
        int calculaAtaque(Personaje& objetivo);
        void recibeAtaque(int ptosAtaque);
        void imprimir();
    private:
        int fuerza;
        //Fuerza max 5
        /*Guerrero: calculaAtaque = Ataque + fuerza * 2
                    recibeAtaque = ptosAtaque - fuerza*/

};