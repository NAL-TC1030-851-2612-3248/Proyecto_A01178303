#include "Guerrero.hpp"
#include <iostream>
#include <cmath>

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

float Guerrero::calculaFuerzaAtaq() const{
    switch(fuerza){
        case 1: return 1.2;
        case 2: return 1.4;
        case 3: return 1.6;
        case 4: return 1.8;
        case 5: return 2;
        default: return 1;
    }
}

float Guerrero::calculaFuerzaDef() const{
    switch(fuerza){
        case 1: return 0.9;
        case 2: return 0.8;
        case 3: return 0.7;
        case 4: return 0.6;
        case 5: return 0.5;
        default: return 1;
    }
}

int Guerrero::calculaAtaque(Personaje& objetivo){
    int ataqueBase = Personaje::calculaAtaque(objetivo);
    int ataqueFinal = std::round(ataqueBase * calculaFuerzaAtaq());
    return ataqueFinal;
}

void Guerrero::recibeAtaque(int ptosAtaque){
    int ptosAtaqueFinal = ptosAtaque * calculaFuerzaDef();
    Personaje::recibeAtaque(ptosAtaqueFinal);
}

void Guerrero::revive(int pntosCurar){
    if(getVida()==0){
        setVida(pntosCurar);
        std::cout<<"El guerrero revivio con "<<pntosCurar<<" puntos de vida."<<std::endl<<std::endl;
    }
    else{
        std::cout<<"El guerrero sigue con vida."<<std::endl<<std::endl;
    }

}

void Guerrero::imprimir(std::ostream& os) const {
    Personaje::imprimir(os);
    os<<"Clase: Guerrero"<<std::endl;
    os<<"Fuerza: "<<fuerza<<std::endl;
    Personaje::imprimeBarra();
}