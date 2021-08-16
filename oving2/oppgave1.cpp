#include <iostream>

using namespace std;

void helper(int *var);

int main() {
  int i = 3;
  int j = 5;
  int *p = &i;
  int *q = &j;

  cout << "i: ";
  helper(&i);
  cout << "j: ";
  helper(&j);
  cout << "p: Value: " << p << " Address: " << &p << endl;
  cout << "q: Value: " << q << " Address: " << &q << "\n"
       << endl;

  *p = 7;
  *q += 4;
  *q = *p + 1;
  p = q;

  cout << "p: " << p << " *p: " << *p << endl;
  cout << "q: " << q << " *q: " << *q << endl;
}

void helper(int *var) {
  cout << "Value: " << *var << " Address: " << var << endl;
}
