#include "Guerrero.hpp"
#include <iostream>
using namespace std;

Guerrero::Guerrero(){
    fuerza = 1;
}

Guerrero::Guerrero(int vida_, int salud_, int nivel_, int ataque_, int fuerza_):Personaje(vida_, salud_, nivel_, ataque_){
    if(fuerza_ < 1){
        fuerza = 1;
    }
    else if(fuerza_ > 5){
        fuerza = 5;
    }
    else{
        fuerza = fuerza_;
    }
}

int Guerrero::getFuerza() const{
    return fuerza;
}

void Guerrero::setFuerza(int fuerza_){
    if(fuerza_<1){
        fuerza = 1;
    }
    else if(fuerza_ > 5){
        fuerza = 5;
    }
    else{
        fuerza = fuerza_;
    }
}

int Guerrero::calculaAtaque(Personaje& objetivo){
    int ataqueBase = Personaje::calculaAtaque(objetivo);
    int ataqueFinal = ataqueBase + fuerza * 2;
    return ataqueFinal;
}

void Guerrero::recibeAtaque(int ptosAtaque){
    ptosAtaque -= fuerza;
    if(ptosAtaque < 0){
        ptosAtaque = 0;
    }
    Personaje::recibeAtaque(ptosAtaque);
}
