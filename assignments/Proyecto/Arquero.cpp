#include "Arquero.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Arquero::Arquero(){
    precision = 10;
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

void Arquero::revive(int pntosCurar){
    if(getVida()==0){
        setVida(pntosCurar);
        cout<<"El arquero revivio con "<<pntosCurar<<" puntos de vida."<<endl<<endl;
    }
    else{
        cout<<"El arquero sigue con vida."<<endl<<endl;
    }

}

void Arquero::imprimir(std::ostream& os) const {
    Personaje::imprimir(os);
    os<<"Clase: Arquero"<<endl;
    os<<"Precision: "<<precision<<endl;
    Personaje::imprimeBarra();
}