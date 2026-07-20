#pragma once
#include "Personaje.hpp"
#include <iostream>

class Guerrero : public Personaje{
    public:
        Guerrero();
        Guerrero(int, int, int, int, int);
        int getFuerza() const;
        void setFuerza(int);
        float calculaFuerzaAtaq() const;
        float calculaFuerzaDef() const;
        int calculaAtaque(Personaje& objetivo) override;
        void recibeAtaque(int ptosAtaque) override;
        void revive(int) override;
        void imprimir(std::ostream& os) const override;
    private:
        int fuerza;
        //Fuerza max 5
        //Por nivel de fuerza +20% ataque +10% defensa

};