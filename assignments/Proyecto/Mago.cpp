#include <iostream>
#include "Mago.hpp"
#include <cstdlib>
#include <ctime>
using namespace std;

Mago::Mago(){
    nivelClerigo = 1; 
}

Mago::Mago(int vida_, int salud_, int nivel_, int ataque_, int nivelClerigo_): Personaje(vida_, salud_, nivel_, ataque_){
        if(nivelClerigo_ < 1){
            nivelClerigo = 1;
        }
        else if(nivelClerigo_ > 5){
            nivelClerigo = 5;
        }
        else{
            nivelClerigo = nivelClerigo_;
        }
}

int Mago::getNivelClerigo() const{
    return nivelClerigo;
}

void Mago::setNivelClerigo(int nivelClerigo_){
  if(nivelClerigo_ < 1){
            nivelClerigo = 1;
        }
        else if(nivelClerigo_ > 5){
            nivelClerigo = 5;
        }
        else{
            nivelClerigo = nivelClerigo_;
        }
}

//rand() % (maximo - minimo + 1) + minimo;
int Mago::calculaCurar(){
    int pntosCurar;
    switch(nivelClerigo){
        case 1: pntosCurar = rand() % (5 - 1 + 1) + 1;
               break;
        case 2: pntosCurar = rand() % (8 - 3 + 1) + 3;
               break;
        case 3: pntosCurar = rand() % (10 - 5 + 1) + 5;
               break;
        case 4: pntosCurar = rand() % (15 - 8 + 1) + 8;
               break;
        case 5: pntosCurar = rand() % (25 - 10 + 1) + 10;
               break;
        default: pntosCurar = 0;
        }
        return pntosCurar;
}

void Mago::curar(Personaje& objetivo){
    int pntosCurar = calculaCurar();
    objetivo.recibeCurar(pntosCurar);
    if(pntosCurar==1){
        cout<<"Objetivo curado por un punto."<<endl<<endl;
    }
    else{
        cout<<"Objetivo curado por "<<pntosCurar<<" puntos."<<endl<<endl;
    }
    }

void Mago::revive(int pntosCurar){
    if(getVida()==0){
        setVida(pntosCurar);
        cout<<"El mago revivio con "<<pntosCurar<<" puntos de vida."<<endl<<endl;
    }
    else{
        cout<<"El mago sigue con vida."<<endl<<endl;
    }
}

void Mago::revivir(Personaje& objetivo){
    double porcentaje = nivelClerigo * 0.1;
    if(porcentaje>1){
        porcentaje = 1;
    }
    int pntosVida = objetivo.getSalud() * porcentaje;
    objetivo.revive(pntosVida);
}

void Mago::imprimir(){
    Personaje::imprimir();
    cout<<"Clase: Mago"<<endl;
    cout<< "Clerigo Nivel: "<<nivelClerigo<<endl<<endl;
}