#include <iostream>

using namespace std;

int main() {
  const int length = 5;

  cout << "Du skal skrive inn " << length << " temperaturer." << endl;

  int under = 0;
  int between = 0;
  int over = 0;

  double temp;

  for (int i = 0; i < length; i++) {
    cout << "Temperatur nr " << i + 1 << ": ";
    cin >> temp;
    if (temp < 10) {
      under++;
    } else if (temp > 20) {
      over++;
    } else {
      between++;
    }
  }

  cout << "Antall under 10 er " << under << endl;
  cout << "Antall mellom 10 og 20 er " << between << endl;
  cout << "Antall over 20 er " << over << endl;
}