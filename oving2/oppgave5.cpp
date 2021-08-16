#include <iostream>

using namespace std;

int main() {
  double number;

  double *pointer = &number;
  double &ref = number;

  // Direkte tilordning
  number = 2.71;
  cout << "Number har nå verdien: " << number << endl;

  // Tilordning via dereferencing
  *pointer = 3.14;
  cout << "Number har nå verdien: " << number << endl;

  // Tilordning via referanse
  ref = 42.0;
  cout << "Number har nå verdien: " << number << endl;
}