#include <cassert>
// #include <string>
#include "funciones/enteros.cpp"
#include <iostream>

using namespace std;
/*
int asadoRec(int w, int n, int ix, int* p, int* s, int* c, int* mx){
    if(ix < 0 || w == 0) return 0;
    if(p[ix] <= w && mx[c[ix]] > 0){
        mx[c[ix]]--;
        int v1 = s[ix] + asadoRec(w - p[ix], n, ix -1, p, s, c, mx);
        mx[c[ix]]++; //probablemente queden mal las referencias
        int v2 = asadoRec(w, n, ix -1, p, s, c, mx);
        return max(v1, v2);
    } else {
        return asadoRec(w, n, ix -1, p, s, c, mx);
    }
}
*/

int asadoTab(int w, int n, int *p, int *sat, int *c, int *maxPorC) {
  int ******tab = new int *****[n];
  for (int r = 0; r < n; r++) {
    tab[r] = new int ****[w + 1];
    for (int i = 0; i <= w; i++) {
      tab[r][i] = new int ***[maxPorC[0] + 1];
      for (int j = 0; j <= maxPorC[0]; j++) {
        tab[r][i][j] = new int **[maxPorC[1] + 1];
        for (int k = 0; k <= maxPorC[1]; k++) {
          tab[r][i][j][k] = new int *[maxPorC[2] + 1];
          for (int m = 0; m <= maxPorC[2]; m++) {
            tab[r][i][j][k][m] = new int[maxPorC[3] + 1]();
          }
        }
      }
    }
  }

  for (int i = 0; i <= w; i++) {
    for (int j = 0; j <= maxPorC[0]; j++) {
      for (int k = 0; k <= maxPorC[1]; k++) {
        for (int m = 0; m <= maxPorC[2]; m++) {
          for (int q = 0; q <= maxPorC[3]; q++) {
            int aux[4] = {j, k, m, q};
            if (p[0] <= i && aux[c[0]] >= 1) {
              tab[0][i][j][k][m][q] = sat[0];
            }
          }
        }
      }
    }
  }
  for (int r = 1; r < n; r++) {
    for (int i = 0; i <= w; i++) {
      for (int j = 0; j <= maxPorC[0]; j++) {
        for (int k = 0; k <= maxPorC[1]; k++) {
          for (int m = 0; m <= maxPorC[2]; m++) {
            for (int q = 0; q <= maxPorC[3]; q++) {
              if (p[r] <= i) {
                int aux[4] = {j, k, m, q};
                aux[c[r]]--;
                if (aux[c[r]] >= 0) {
                  tab[r][i][j][k][m][q] = max(
                      sat[r] +
                          tab[r - 1][i - p[r]][aux[0]][aux[1]][aux[2]][aux[3]],
                      tab[r - 1][i][j][k][m][q]);
                } else {
                  tab[r][i][j][k][m][q] = tab[r - 1][i][j][k][m][q];
                } // else no cambia, queda el anterior tab[i][j][k][m][q]
              } else {
                tab[r][i][j][k][m][q] = tab[r - 1][i][j][k][m][q];
              } // else no cambia, queda el anterior tab[i][j][k][m][q]
                // (tab[r][i][j][k][m][q] = tab[r-1][i][j][k][m][q]  )
            }
          }
        }
      }
    }
  }

  return tab[n - 1][w][maxPorC[0]][maxPorC[1]][maxPorC[2]][maxPorC[3]];
}

int main() {
  int n;
  int w;
  cin >> n >> w;
  int *peso = new int[n];
  int *sat = new int[n];
  int *cat = new int[n];
  int *maxC = new int[4];
  int c;
  for (int i = 0; i < 4; i++) {
    cin >> c;
    maxC[i] = c;
  }
  int p;
  int s;
  for (int i = 0; i < n; i++) {
    cin >> p >> s >> c;
    peso[i] = p;
    sat[i] = s;
    cat[i] = c;
  }
  cout << asadoTab(w, n, peso, sat, cat, maxC) << endl;
  return 0;
}

/*
 for (int r = 1; r < n; r++) {
    for (int i = 1; i <= w; i++) {
      for (int j = 0; j <= maxPorC[0]; j++) {
        for (int k = 0; k <= maxPorC[1]; k++) {
          for (int m = 0; m <= maxPorC[2]; m++) {
            for (int q = 0; q <= maxPorC[3]; q++) {
              if (p[r] <= i) {
                int aux[4] = {j, k, m, q};
                aux[c[r]]--;
                if (aux[c[r]] >= 0) {
                  tab[i][j][k][m][q] = max(
                      sat[r] + tab[i - p[r]][aux[0]][aux[1]][aux[2]][aux[3]],
                      tab[i][j][k][m][q]);
                } // else no cambia, queda el anterior tab[i][j][k][m][q]
              } // else no cambia, queda el anterior tab[i][j][k][m][q]
                // (tab[r][i][j][k][m][q] = tab[r-1][i][j][k][m][q]  )
                */