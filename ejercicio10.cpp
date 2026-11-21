#include <cassert>
#include <string>
#include <iostream>
#include <cstdint>
using namespace std;

struct par {
    string word;
    int64_t value;
   
};


string unaVez(string total){
    string res = "";
    for(int i = 0; i < total.length(); i++){
        if(res.find(total[i]) == string::npos){
            res+= total[i]; 
        }
    }
    return res;
}

bool esValido(string letras,int ixL, int digito, par* act, int cantP, bool* usados) {
    if(usados[digito]) return false;
    if(ixL >= letras.length()) return false;
    bool res = true;
    
    if(digito == 0){
        for(int i= 0; i < cantP; i++){
            if((act[i].word[0] == letras[ixL] && act[i].word.length() > 1)) res = false;
        }
    }
   
    return res;
}

void agregar(par* palabras, char letra, int digito, int cantP, bool* usados,int64_t* pow10){
    usados[digito] = true;
    for(int i = 0; i < cantP; i++){
        for(int j = 0; j < palabras[i].word.length(); j++){
            if(palabras[i].word[j] == letra) {
                palabras[i].value+= digito*(pow10[palabras[i].word.length() - j - 1]);
                
            }
        }
    }
    return;
}

void quitar(par* palabras, char letra, int digito, int cantP, bool* usados,int64_t* pow10){
    usados[digito] = false;
    for(int i = 0; i < cantP; i++){
        for(int j = 0; j < palabras[i].word.length(); j++){
            if(palabras[i].word[j] == letra) {

                palabras[i].value-= digito*(pow10[palabras[i].word.length() - j - 1]);
                
            }
        }
    } 
    return;
}

bool esSolucion(par* solCandidata, int cantP, bool puedeSer){
    bool res = false;
    int64_t sum = 0;
    for(int i = 0; i < cantP - 1; i++){
        sum+= solCandidata[i].value;
    }
    return puedeSer && (sum == solCandidata[cantP -1].value);
}

bool puedoPodar(par* solCandidata, par* best, int cantP){
    if(solCandidata[cantP - 1].value > best[cantP - 1].value) return true; //chequeamos resultado
    if(solCandidata[cantP - 1].value == best[cantP - 1].value){
        int i=0;
        while(i< cantP && solCandidata[i].value == best[i].value )i++;
        if(i<cantP ){
        if(solCandidata[i].value > best[i].value) return true;

        } 
    }
    return false; //si son iguales nos quedariamos con la nueva
}

void solveRiddle(string letras, int ixL, par* best, par* act, int cantP, bool* usados, int64_t* pow10){
    if(puedoPodar(act, best, cantP)){
        return;
    }
    if(esSolucion(act, cantP, ixL == letras.length())){ //hacer la suma
        for(int i =0 ; i< cantP; i++){
            best[i].value = act[i].value;

        }
      return;
    }
    for(int i = 0; i < 10; i++){
        if(esValido(letras, ixL, i, act, cantP,usados)){
            agregar(act, letras[ixL], i, cantP, usados, pow10);
            solveRiddle(letras, ixL+1, best, act, cantP, usados,pow10);
            quitar(act, letras[ixL], i, cantP, usados, pow10);
        }
    }
    return;
}


int main(){
    int t;
    cin >> t;
    int k;
    int64_t pow10[11];
    pow10[0] = 1;
    for(int i = 1; i <= 10; i++) pow10[i] = pow10[i-1] * 10;
    for(int i = 0; i < t; i++){
        cin >> k;
        string total;
        string pal;
        par* pals = new par[k+1];
        par* best = new par[k+1];
        par* act = new par[k+1];
        for(int j = 0; j < k; j++){
            cin >> pal;
            pals[j].word = pal;
            pals[j].value = 0;
            best[j].word = pal;
            best[j].value = INT64_MAX;
            act[j].word = pal;
            act[j].value = 0;
            total += pal; //orden opuesto
        }
        cin >> pal; //resultado
        pals[k].word = pal;
        pals[k].value = 0;
        best[k].word = pal;
        best[k].value = INT64_MAX;
        act[k].word = pal;
        act[k].value = 0;
        total = pal + total;
        total = unaVez(total);
        solveRiddle(total, 0, best, act, k+1,new bool[10](),pow10);//llamar backtracking con cantP = k+1
        //chequear si tenemos mas de una letra en la palabra
        bool es = true;
        for(int i = 0; i< k+1; i++){
            if(best[i].value == INT64_MAX) es = false;
        }
        if(es){
            for(int i = 0; i < k - 1; i++) {
                cout << best[i].value << " + ";
            }
            cout << best[k-1].value << " = " << best[k].value << endl; 
        }else{
            cout << "imposible" << endl;
        }
    }
    return 0;
}