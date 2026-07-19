#pragma once
#include <iostream>
#include "Personaje.hpp"

class Arquero : public Personaje{
    public:
        Arquero();
        Arquero(int, int, int, int, int);
        double getPrecision() const;
        void setPrecision(int);
        int calculaAtaque(Personaje& objetivo) override;
        void revive(int) override;
        void imprimir() override;
    private:
        int precision;
        // % en entero para acertar un critico (puntos de ataque * 5). Max 50% min 10%.
};