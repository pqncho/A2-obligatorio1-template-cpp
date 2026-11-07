#include <cassert>
#include <string>
#include <iostream>
//#include "funciones/enteros.cpp"
using namespace std;

int dalePato(int* gol, int* likes, int sz, int in, int* cont, bool bailo){
    if(in == sz) return 0;
    cont[0]+= gol[in]; //cero o uno
    //int total = 0;
    if(cont[0] > cont[1]){
        if(bailo){ //bailo en el anterior
            //max sumar + /2 o nosumar y entero
            int v1 = dalePato(gol,likes, sz, in+1, cont, false);
            cont[1]++;
            int v2 = likes[in]/2 + dalePato(gol,likes, sz, in+1, cont, true);
            if(v1 > v2){
                return v1;
            }
            return v2;
        } else {
            int v1 = dalePato(gol,likes, sz, in+1, cont, false);
            cont[1]++;
            int v2 = likes[in] + dalePato(gol,likes, sz, in+1, cont, true);
            if(v1 > v2){
                return v1;
            }
            return v2;
        }
    } else {
        return dalePato(gol, likes, sz, in+1, cont, false);
    }
}

int main(){

    int k;
    cin >> k;
    int* likes = new int[k]();
    int* goles = new int[k]();
    int p;
    for(int i = 0; i< k; i++) {
        cin >> p;
        goles[i] = p;
    }
    for(int i = 0; i< k; i++) {
        cin >> p;
        likes[i] = p;
    }
    int* contador = new int[2](); //pos 0 nosotros, pos 1 rivales
    cout << dalePato(goles, likes, k, 0, contador, false) << endl;
    return 0;
}