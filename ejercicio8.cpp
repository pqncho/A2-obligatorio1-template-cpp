#include <cassert>
//#include <string>
#include <iostream>
#include "funciones/enteros.cpp"

using namespace std;

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


int main(){
    int n;
    int w;
    cin >> n >> w;
    int* peso = new int[n+1];
    int* sat = new int[n+1];
    int* cat = new int[n+1];
    int* max = new int[4];
    int c;
    for(int i = 0; i < 4; i++){
        cin >> c;
        max[i] = c;
    }
    int p;
    int s;
    for(int i = 1; i <= n; i++){
        cin >> p >> s >> c;
        peso[i] = p;
        sat[i] = s;
        cat[i] = c;
    }
    cout << asadoRec(w, n, n-1, peso, sat, cat, max) << endl;
    return 0;
}