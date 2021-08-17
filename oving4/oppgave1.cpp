#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<double> numbers;
  numbers.emplace_back(1.61);
  numbers.emplace_back(3.14);
  numbers.emplace_back(2.71);
  numbers.emplace_back(42.0);

  cout << "First number: " << numbers.front() << endl;
  cout << "Last number: " << numbers.back() << endl;

  double to_find = 2.71;
  auto pos = find(numbers.begin(), numbers.end(), to_find);
  if (pos != numbers.end()) {
    cout << to_find << " was found in the vector :)" << endl;
  } else {
    cout << to_find << " was not found in the vector :(" << endl;
  }
}
