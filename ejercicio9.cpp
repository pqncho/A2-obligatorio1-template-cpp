#include <cassert>
#include <iostream>
//#include <string>
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
int dalePato(int** memoBailo, int** memoNo, int* goles, int* likes, int sz, int ix, int cont){
    if(ix == sz) return 0;
    if(memoBailo[ix][cont] == -1 && memoNo[ix][cont] == -1){
        cont+= goles[ix];
        if(cont > 0){
            memoBailo[ix][cont] = max(likes[ix]/2 + dalePato(memoBailo, memoNo, goles, likes, sz, ix+1, cont-1),
                                    likes[ix] + dalePato(memoBailo, memoNo, goles, likes, sz, ix+1, cont-1));
            memoNo[ix][cont] = dalePato(memoBailo, memoNo, goles, likes, sz, ix+1, cont);
        }
    }
    return max(memoBailo[ix][cont], memoNo[ix][cont]);
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

  int** memoBailo = new int*[k];
  int** memoNo = new int*[k];
  for(int i =0; i < k; i++){
    memoBailo[i] = new int[k]();
    memoNo[i] = new int[k]();
    for(int j = 0; j < k; j++){
        memoBailo[i][j] = -1;
        memoNo[i][j] = -1;
    }
  }

  cout << dalePato(memoBailo, memoNo, goles, likes, k, 0, 0) << endl;
  return 0;
}