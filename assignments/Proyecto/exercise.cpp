#include <iostream>
#include "Personaje.hpp"
#include "Guerrero.hpp"
#include "Arquero.hpp"
#include "Mago.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int main(){

srand(time(0));

vector<Personaje*> personajes;

personajes.push_back(new Guerrero());
personajes.push_back(new Arquero());
personajes.push_back(new Mago());

cout<<"===== PERSONAJES ====="<<endl;

for (Personaje* p : personajes){
    cout<<*p<<endl;
}

cout<<"===== COMBATES ====="<<endl;

for(int i = 0;i<6; i++){
personajes[0]->atacar(*personajes[1]);
}
cout<<*personajes[1]<<endl;

for(int i = 0; i<5; i++){
personajes[0]->atacar(*personajes[2]);
}
cout<<*personajes[2]<<endl;

for(int i = 0; i<20; i++){
personajes[1]->atacar(*personajes[0]);
}
cout<<*personajes[0]<<endl;

personajes[0]->revive(15);

cout<<*personajes[0]<<endl;

for(Personaje* p : personajes){
    delete p;
}
}
