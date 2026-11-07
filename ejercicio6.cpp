#include <cassert>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int *placas = new int[1001]();
  int n;
  cin >> n;
  cin.ignore();
  int p;
  for (int i = 0; i < n; i++) {
    cin >> p;
    placas[p]++;
  }

  int cntr = -1;
  string side1 = "";
  string side2 = "";
  for (int i = 1000; i >= 0; i--) { // recorrer de mayor a menor
    while (placas[i] > 0) {
      if (placas[i] >= 2) {
        side1.append(to_string(i));
        side1.append(" ");
        side2 = to_string(i) + " " + side2;
        placas[i]--;
      } else if (i > cntr) {
        cntr = i;
      }
      placas[i]--;
    }
  }

  if (cntr != -1) {
    side1 += to_string(cntr);
    side1 += " ";
  }
  side1 += side2;
  cout << side1 << endl;
  return 0;
}