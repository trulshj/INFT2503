#include <iostream>

using namespace std;

int main() {
  int a = 5;
  int &b = a;       // Referanser MÅ initialiseres
  int *c = nullptr; // Pekere *burde* settes til 0 eller nullptr
  c = &b;
  a = b + *c; // Vi trenger ikke derefrence ints for å hente verdiene deres
  b = 2;      // "Adressen til b" kan ikke gis verdien 2
}