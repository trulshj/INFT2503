#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

void read_temperatures(double temperatures[], int length);

int main() {
    const int length = 5;
    double temperatures[length];

    read_temperatures(temperatures, length);
}

void read_temperatures(double temperatures[], int length) {
    const char filename[] = "/Users/trulshj/school/INFT2503/1/temperaturfil.dat";
    ifstream file;
    file.open(filename);
    if (!file) {
        cout << "Feil ved åpning av temperaturfilen." << endl;
        exit(EXIT_FAILURE);
    }

    double temperature;
    int i = 0;
    while (file >> temperature && i < length) {
        temperatures[i] = temperature;
    }
    file.close();
}