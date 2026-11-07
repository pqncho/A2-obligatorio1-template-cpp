#include <cassert>
#include <iostream>
#include <string>
// #include "funciones/enteros.cpp"
using namespace std;

int dalePato(int *gol, int *likes, int sz, int in, bool bailo, int golA,
             int golB) {
  if (in == sz)
    return 0;
  golA += gol[in]; // cero o uno

  if (golA > golB) {
    if (bailo) { // bailo en el anterior

      int v1 = dalePato(gol, likes, sz, in + 1, false, golA, golB);
      golB++;
      int v2 =
          likes[in] / 2 + dalePato(gol, likes, sz, in + 1, true, golA, golB);
      if (v1 > v2) {
        return v1;
      }
      return v2;
    } else {
      int v1 = dalePato(gol, likes, sz, in + 1, false, golA, golB);
      golB++;
      int v2 = likes[in] + dalePato(gol, likes, sz, in + 1, true, golA, golB);
      if (v1 > v2) {
        return v1;
      }
      return v2;
    }
  } else {
    return dalePato(gol, likes, sz, in + 1, false, golA, golB);
  }
}

int main() {

  int k;
  cin >> k;
  int *likes = new int[k]();
  int *goles = new int[k]();
  int p;
  for (int i = 0; i < k; i++) {
    cin >> p;
    goles[i] = p;
  }
  for (int i = 0; i < k; i++) {
    cin >> p;
    likes[i] = p;
  }
  cout << dalePato(goles, likes, k, 0, false, 0, 0) << endl;
  return 0;
}