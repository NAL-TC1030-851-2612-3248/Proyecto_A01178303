#pragma once
#include <iostream>
#include "Personaje.hpp"

class Mago : public Personaje{
    public:
        Mago();
        Mago(int, int, int, int, int);
        int getNivelClerigo() const;
        void setNivelClerigo(int);
        int calculaCurar();
        void curar(Personaje& objetivo);
        void revive(int pntosCurar) override;
        void revivir(Personaje&);
        void imprimir() override;
    private:
        int nivelClerigo;
            //Nivel 1-5 que determina que tanto sana el mago.
};