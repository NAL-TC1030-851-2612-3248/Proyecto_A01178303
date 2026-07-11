#pragma once
#include <iostream>
#include "Personaje.hpp"

class Arquero : public Personaje{
    public:
        Arquero();
        Arquero(int, int, int, int, int);
        double getPrecision() const;
        void setPrecision(int);
        int calculaAtaque(Personaje& objetivo);
        void imprimir();
    private:
        int precision;
        // % en entero para acertar un critico (puntos de ataque * 5). Max 75% min 10%.
};