#include <cassert>
#include <climits>
#include <string>
#include <iostream>

using namespace std;

struct par {
    string word;
    int value;
    bool hayCero;
};

//hacer respuesta<par*, bool> para saber si esta o no

string unaVez(string total){
    string res = "";
    for(int i = 0; i < total.length(); i++){
        if(res.find(total[i]) == string::npos){
            res+= total[i]; 
        }
    }
    return res;
}

bool esValido(char letra, int digito, par* act, int cantP) {
    bool res = true;
    if(digito == 0){
        for(int i= 0; i < cantP - 1; i++){
            if((act[i].word[0] == letra && act[i].word.length() > 1) || act[i].hayCero) res = false;
        }
    }else{
        for(int i = 0; i < cantP; i++){
            if(to_string(act[i].value).find(to_string(digito)) != string::npos) res = false;
        }
    }
    return res;
}

void agregar(par* palabras, char letra, int digito, int cantP){
    for(int i = 0; i < cantP; i++){
        for(int j = 0; j < palabras[i].word.length(); j++){
            if(palabras[i].word[j] == letra) {
                palabras[i].value+= digito*(10^(palabras[i].word.length() - j - 1));
                if(digito == 0) palabras[i].hayCero = true;
            }
        }
    }
}

void quitar(par* palabras, char letra, int digito, int cantP){
    for(int i = 0; i < cantP; i++){
        for(int j = 0; j < palabras[i].word.length(); j++){
            if(palabras[i].word[j] == letra) {
                palabras[i].value-= digito*(10^(palabras[i].word.length() - j - 1));
                if(digito == 0) palabras[i].hayCero = false; 
            }
        }
    }
}

bool esSolucion(par* solCandidata, int cantP, bool puedeSer){
    bool res = false;
    int sum = 0;
    for(int i = 0; i < cantP - 1; i++){
        sum+= solCandidata[i].value;
    }
    return puedeSer && (sum == solCandidata[cantP -1].value);
}

bool puedoPodar(par* solCandidata, par* best, int cantP){
    if(solCandidata[cantP - 1].value > best[cantP - 1].value) return true; //chequeamos resultado
    for(int i = 0; i < cantP - 1; i++){//chequeamos en orden de sumandos
        if(solCandidata[i].value > best[i].value) return true;
    }
    return false; //si son iguales nos quedariamos con la nueva
}

par* solveRiddle(string letras, int ixL, par* best, par* act, int cantP){
    if(puedoPodar(act, best, cantP)){
        return best;
    }
    if(esSolucion(act, cantP, ixL == cantP)){ //hacer la suma
      return act;
    }
    for(int i = 0; i < 10; i++){
        if(esValido(letras[ixL], i, act, cantP)){
            agregar(act, letras[ixL], i, cantP);
            best = solveRiddle(letras, ixL+1, best, act, cantP);
            quitar(act, letras[ixL], i, cantP);
        }
    }
    return best;
}


int main(){
    int t;
    cin >> t;
    int k;
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
            best[j].value = INT_MAX;
            act[j].word = pal;
            act[j].value = 0;
            total += pal; //orden opuesto
        }
        cin >> pal; //resultado
        pals[k].word = pal;
        pals[k].value = 0;
        best[k].word = pal;
        best[k].value = INT_MAX;
        act[k].word = pal;
        act[k].value = 0;
        total = pal + total;
        total = unaVez(total);
        par* solucion = solveRiddle(total, 0, best, act, k+1);//lamar backtracking con cantP = k+1
        //chequear si tenemos mas de una letra en la palabra
        bool es = true;
        for(int i = 0; i< k+1; i++){
            if(solucion[i].value == INT_MAX) es = false;
        }
        if(es){
            for(int i = 0; i < k - 1; i++) {
                cout << solucion[i].value << " + " << endl;
            }
            cout << solucion[k-1].value << " = " << solucion[k].value << endl; //este si endl
        }else{
            cout << "imposible" << endl;
        }
    }
    return 0;
}