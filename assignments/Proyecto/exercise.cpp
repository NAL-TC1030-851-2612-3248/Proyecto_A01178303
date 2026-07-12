#include <iostream>
#include "Personaje.hpp"
#include "Guerrero.hpp"
#include "Arquero.hpp"
#include "Mago.hpp"
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

  Guerrero guerrero;
  Arquero arquero;
  Mago mago;

  guerrero.atacar(arquero);
  arquero.imprimir();

}
