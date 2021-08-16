#include <iostream>

using namespace std;

int find_sum(const int *table, int length);

int main() {

  // Lag en tabell og fyll den med 1, 2, 3...
  int table[20];
  for (int i = 0; i < 20; i++) {
    table[i] = i + 1;
  }

  // Benytt det faktum at navnet på en tabell er en pointer i seg selv
  cout << "Summen av de 10 første tallene er: " << find_sum(table, 10) << endl;
  cout << "Summen av de 5 neste er: " << find_sum(&table[10], 5) << endl;
  cout << "Summen av de 5 siste er: " << find_sum(&table[15], 5) << endl;
}

int find_sum(const int *table, int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += table[i];
  }
  return sum;
}