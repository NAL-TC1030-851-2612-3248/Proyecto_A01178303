#include <iostream>
#include "Personaje.hpp"
#include "Guerrero.hpp"
#include "Arquero.hpp"
#include "Mago.hpp"
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){

srand(time(0));

Guerrero* guerrero = new Guerrero();
Arquero* arquero = new Arquero();
Mago* mago = new Mago();

guerrero->imprimir();
arquero->imprimir();
mago->imprimir();

for(int i = 0; i<12; i++){
  guerrero->atacar(*arquero);
}

arquero->imprimir();

mago->revivir(*arquero);

arquero->imprimir();

mago->revivir(*arquero);

mago->curar(*arquero);

arquero->imprimir();

delete guerrero;
delete arquero;
delete mago;

}
