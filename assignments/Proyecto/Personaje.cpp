#include <iostream>
#include <cstdlib>
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
    int lleno = (vida*20)/100;
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
    vida -= ptosAtaque;
    if(vida<0){
        vida=0;
    }
}

void Personaje::atacar(Personaje& objetivo){
    int ptosAtaque = calculaAtaque(objetivo);
    objetivo.recibeAtaque(ptosAtaque);
}

void Personaje::recibeCurar(int pntosCurar){
    vida += pntosCurar;
    if (vida>salud){
        vida = salud;
    }
}

void Personaje::imprimir(){
    cout<<"Vida: " <<vida<<endl;
    cout<<"Salud Maxima: " <<salud<<endl;
    cout<<"Nivel: " <<nivel<<endl;
    cout<<"Ataque: " <<ataque<<endl;
    imprimeBarra();
}