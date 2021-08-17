#include <iostream>
#include <string>
#include <vector>

using namespace std;

void replace_helper(string &s, const size_t pos, const char replace_with);

int main() {
  string word1, word2, word3;
  cout << "Skriv inn 3 ord med mellomrom mellom hvert ord:" << endl;
  cin >> word1 >> word2 >> word3;

  string sentence = word1 + " " + word2 + " " + word3 + ".";
  cout << sentence << endl;

  cout << endl;
  cout << "Lengden på de ulike tingene:" << endl;
  cout << "Ord 1: " << word1.length() << ", Ord 2: " << word2.length() << ", Ord 3: " << word3.length() << endl;
  cout << "Hele setningen: " << sentence.length() << endl;

  string sentence2 = sentence;
  replace_helper(sentence2, 10, 'X');
  replace_helper(sentence2, 11, 'X');
  replace_helper(sentence2, 12, 'X');

  cout << endl;
  cout << sentence << endl;
  cout << sentence2 << endl;

  // Gitt at vi må ha tre ord på minst ett tegn hver + mellomrom og punktum er den minste lengden på en setning 6 tegn
  string sentence_start = sentence.substr(0, 5);
  cout << endl;
  cout << sentence_start << endl;
  cout << sentence << endl;

  size_t hallo_pos = sentence.find("hallo");
  if (hallo_pos != string::npos) {
    cout << "Setningen inneholder 'hallo' på index: " << hallo_pos << endl;
  } else {
    cout << "Setningen inneholder ikke 'hallo'!" << endl;
  }

  vector<size_t> positions;
  size_t position = sentence.find("er");
  while (position != string::npos) {
    positions.push_back(position);
    position = sentence.find("er", position + 2);
  }
  cout << endl;
  cout << "'er' finnes på disse indexene:" << endl;
  for (size_t pos : positions) {
    cout << pos << " ";
  }
  cout << endl;
}

void replace_helper(string &s, const size_t pos, const char replace_with) {
  if (s.size() >= pos) {
    s[pos - 1] = replace_with;
  }
}