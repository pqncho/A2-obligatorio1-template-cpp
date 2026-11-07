#include <cassert>
#include <iostream>

using namespace std;

int contar(int* res, int in, int m, int f){
    int c = 0;
    for(int i = in; i <= m; i++){
        for(int j = m+1; j<= f; j++){
            if(res[i] > 2*res[j]) c++;
        }
    }
    return c;
}

int remontadasEpicas(int* res, int i, int f){
    if(i == f) return 0;
    int mid = (i + f)/2;
    int ret;
    ret = remontadasEpicas(res, i, mid);
    ret += remontadasEpicas(res, mid +1, f);

    return ret + contar(res, i, mid, f);
}

int main() { 
    int n;
    cin >> n;
    int* resultado = new int[n]();
    int p;
    for(int i=0; i<n; i++){
        cin >> p;
        resultado[i] = p;
    }
    cout << remontadasEpicas(resultado, 0, n-1) << endl;
    return 0; 
}