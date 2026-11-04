#include <cassert>
#include <string>
#include <iostream>

using namespace std;

string backwards(string side){
    string ret = "";
    for(int i = side.length() - 1; i >= 0; i++){
        ret+= side[i];
    }
    return ret;
}


int main(){
    int* placas = new int[1001]();
    int n;
    cin >> n; 
    int p;
    for(int i = 0; i < n; i++){
        cin >> p;
        placas[p]++;
    }

    int cntr = -1;
    string side1 = "";
    for(int i = 1000; i >= 0; i--){ //recorrer de mayor a menor
        while(placas[i] > 0){
            if(placas[i] >= 2){
                side1+= i;
                side1 = " ";
                placas[i]--;
            }else if(i > cntr){
                cntr = i;
            }
            placas[i]--;
        }
    }
    string side2 = backwards(side1);
    side2.erase(0, 1); //primer espacio
    if(cntr != -1){
        side1+= cntr;
        side1+= " ";
    }
    side1+= side2;
    cout << side1 << endl;
    return 0;
}