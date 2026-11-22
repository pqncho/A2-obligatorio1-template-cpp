#include <cassert>
#include <iostream>
// #include <string>
#include "funciones/enteros.cpp"
using namespace std;

/*int dalePato(int *gol, int *likes, int sz, int in, bool bailo, int golA,
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
*/
int dalePato(int ***memoPato, int *goles, int *likes, int sz,
             int ix, int cont, bool bailo) {
  if (ix == sz)
    return 0;
  cont += goles[ix];
  if (memoPato[ix][cont][bailo] == -1) {
    if (cont > 0) {
      int like = likes[ix];
      if(bailo) like = like / 2;
      memoPato[ix][cont][bailo] = max(
          like + dalePato(memoPato, goles, likes, sz, ix + 1,
                                   cont - 1, true),
          dalePato(memoPato, goles, likes, sz, ix + 1, cont, false));

    } else {
      memoPato[ix][cont][bailo] =
          dalePato(memoPato, goles, likes, sz, ix + 1, cont, false);
    }

  } 
  return memoPato[ix][cont][bailo];
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

  int ***memoPato = new int **[k + 1];
  for (int i = 0; i <= k; i++) {
    memoPato[i] = new int*[k + 1];
    for (int j = 0; j <= k; j++) {
      memoPato[i][j] = new int[2];
      memoPato[i][j][0] = -1;
      memoPato[i][j][1] = -1;
    }
  }

  cout << dalePato(memoPato, goles, likes, k, 0, 0, false) << endl;
  return 0;
}
