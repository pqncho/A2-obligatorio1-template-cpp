#include <cassert>
#include <string>
#include <iostream>
#include "tads/linked_list.cpp"
using namespace std;

string unaVez(string total){
    string res = "";
    for(int i = 0; i < total.length(); i++){
        if(res.find(total[i]) == string::npos){
            res+= total[i]; 
        }
    }
    return res;
}

linkedList<string> solveRiddle(string letras, string l, linkedList<string> best, linkedList<string> act, linkedList<string> completas){
    //if(puedoPodar(act, best)){
        return best;
    //}
    //if(esSolucion(act)){ //pasar strings a int y hacer la suma
      //  return act;
    //}
    for(int i = 0; i < 10; i++){
        //if(esValido(l, i, act)){ // actual seria tipo "ae21f", "22a5", ...

        //}
    }
    
}


int main(){
    int t;
    cin >> t;
    int k;
    for(int i = 0; i < t; i++){
        cin >> k;
        string total;
        for(int j = 0; j <= k; j++){
            string pal;
            cin >> pal;
            total = pal + total; //el resultado al principio
        }
        total = unaVez(total);
        //lamar backtracking
    }
    return 0;
}