#include <cassert>
#include <cstdint>
#include <iostream>
using namespace std;

int64_t mergeContar(int *res, int in, int m, int f) {
  int64_t c = 0;
  int n1 = m - in + 1;
  int n2 = f - m;

  int n = m + 1;
  for (int i = in; i <= m; i++) {
    while (n <= f && (int64_t)res[i] > (int64_t)2 * res[n])
      n++;
    c += n - (m + 1);
  }

  int *left = new int[n1]();
  int *right = new int[n2]();
  for (int i = 0; i < n1; i++) {
    left[i] = res[in + i];
  }
  for (int j = 0; j < n2; j++) {
    right[j] = res[m + 1 + j];
  }
  int i = 0;
  int j = 0;
  int k = in;

  // mergear
  while (i < n1 && j < n2) {
    if (left[i] <= right[j]) {
      res[k] = left[i];
      i++;
    } else {
      res[k] = right[j];
      j++;
    }
    k++;
  }

  // los q quedan
  while (i < n1) {
    res[k] = left[i];
    i++;
    k++;
  }

  while (j < n2) {
    res[k] = right[j];
    j++;
    k++;
  }

  return c;
}

int64_t remontadasEpicas(int *res, int i, int f) {
  if (i == f)
    return 0;
  int mid = (i + f) / 2;
  int64_t ret;
  ret = remontadasEpicas(res, i, mid);
  ret += remontadasEpicas(res, mid + 1, f);

  return ret + mergeContar(res, i, mid, f);
}

int main() {
  int n;
  cin >> n;
  int *resultado = new int[n]();
  int p;
  for (int i = 0; i < n; i++) {
    cin >> p;
    resultado[i] = p;
  }
  cout << remontadasEpicas(resultado, 0, n - 1) << endl;
  return 0;
}