#include <iostream>
#include <ctime>
#include "Personaje.hpp"
using namespace std;


Personaje::Personaje(){
    vida = 100;
    salud = 100;
    nivel = 1;
    ataque = 10;
}

Personaje::Personaje(int vida_, int salud_, int nivel_, int ataque_){
            vida = vida_;
            salud = salud_;
            nivel = nivel_;
            ataque = ataque_;
}


int Personaje::getVida() const{
    return vida;
}

int Personaje::getSalud() const{
    return salud;
}
int Personaje::getNivel() const{
    return nivel;
}
int Personaje::getAtaque() const{
    return ataque;
}
void Personaje::setVida(int vida_){
    vida = vida_;
}
void Personaje::setSalud(int salud_){
    salud = salud_;
}
void Personaje::setNivel(int nivel_){
    nivel = nivel_;
}
void Personaje::setAtaque(int ataque_){
    ataque = ataque_;
}
int Personaje::porcentajeSalud(){
    return (salud*100)/vida;
}
void Personaje::imprimeBarra()const{
    int lleno = (salud*20)/100;
    int vacio = 20 - lleno;
    for (int i = 0; i < lleno; i++) cout << "%";
    for (int i = 0; i < vacio; i++) cout << "=";
    cout<<endl;
}

//rand() % (maximo - minimo + 1) + minimo;
int Personaje::calculaAtaque(Personaje& objetivo){
    int mitad = ataque / 2;
    if (objetivo.getNivel() > nivel) {
        return rand() % (mitad - 1 + 1) + 1;
    }
    else {
        return rand() % (ataque - mitad + 1) + mitad;
    }
}

void Personaje::recibeAtaque(int ptosAtaque){
    salud -= ptosAtaque;
    if(salud<0){
        salud=0;
    }
}

void Personaje::atacar(Personaje& objetivo){
    int ptosAtaque = calculaAtaque(objetivo);
    objetivo.recibeAtaque(ptosAtaque);
}

void Personaje::imprimir(){
    cout<<"Vida:" <<vida<<endl;
    cout<<"Salud:" <<salud<<endl;
    cout<<"Nivel:" <<nivel<<endl;
    cout<<"Ataque:" <<ataque<<endl;
    imprimeBarra();
}