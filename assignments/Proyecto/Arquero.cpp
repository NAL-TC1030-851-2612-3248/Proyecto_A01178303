#include "Arquero.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Arquero::Arquero(){
    precision = 5;
}

Arquero::Arquero(int vida_, int salud_, int nivel_, int ataque_, int precision_): Personaje(vida_, salud_, nivel_, ataque_){
    precision = precision_;
}

double Arquero::getPrecision() const{
    return precision;
}

void Arquero::setPrecision(int precision_){
    if(precision<5){
        precision = 5;
    }
    else if(precision>35){
        precision = 35;
    }
    else{
        precision = precision_;
    }
}

int Arquero::calculaAtaque(Personaje& objetivo){
    bool critico;
    if (rand() % 100 < precision) {
        critico = true;
    } 
    else {
        critico = false;
    }

    if(critico==true){
        return Personaje::calculaAtaque(objetivo) * 5;
    }
    else{
        return Personaje::calculaAtaque(objetivo);
    }
}

void Arquero::imprimir(){
    Personaje::imprimir();
    cout<<"Precision: "<<precision<<endl;
}