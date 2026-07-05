//GEnera la implementación de la clase base Personaje
#include <iostream>
#include <ctime>
#include "Personaje.hpp"
using namespace std;


Personaje::Personaje(){
    vida = 100;
    salud = 80;
    nivel = 1;
    ataque = 10;
}

Personaje::Personaje(int vida, int salud, int nivel, int ataque){
            this->vida = vida;
            this->salud = salud;
            this->nivel = nivel;
            this->ataque = ataque;
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
void Personaje::setVida(int v){
    vida = v;
}
void Personaje::setSalud(int s){
    salud = s;
}
void Personaje::setNivel(int n){
    nivel = n;
}
void Personaje::setAtaque(int a){
    ataque = a;
}
int Personaje::porcentajeSalud(){
    return (salud*100)/vida;
}
void Personaje::imprimeBarra()const{
    int lleno = (salud*20)/100;
    int vacio = 20 - lleno;
    for (int i = 0; i < lleno; i++) cout << "%";
    for (int i = 0; i < vacio; i++) cout << "=";
}

//rand() % (maximo - minimo + 1) + minimo;
int Personaje::calculaAtaque(Personaje& objetivo){
    int mitad = ataque / 2;
    if (objetivo.getNivel() > nivel) {
        return rand() % (mitad - 0 + 1) + 0;
    }
    else {
        return rand() % (ataque - mitad + 1) + mitad;
    }
}


