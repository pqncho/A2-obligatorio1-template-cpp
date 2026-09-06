#include <cassert>
#include <string>
#include <iostream>
//#include <limits>

#include "tads/avl.cpp"


using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    bst<long long> *monedas = new avl<long long>();
    bst<string> *pinturas = new avl<string>();

    for (int i = 0; i < n; i++) {
        string ans;
        getline(cin,ans);


    
        if(ans.front() == 'A') { //alta
            ans.erase(0, 5);
            if(ans.front() == 'P'){
                ans.erase(0, 2);
                pinturas->add(ans);
            } else {
                ans.erase(0, 2);
                monedas->add(stoll(ans));
            }
        } else if (ans.front() == 'B') { //buscar
            ans.erase(0, 7);
            if(ans.front() == 'P'){
                ans.erase(0, 2);
                pinturas->search(ans);
            } else {
                ans.erase(0, 2);
                monedas->search(stoll(ans));
            }
        } else { //rango
            ans.erase(0, 6);
            if(ans.front() == 'P'){
                ans.erase(0, 2);
                string upto = ans;
                int ix = ans.find(' ');
                upto.erase(0, ix + 1);
                ans.erase(ix, std::string::npos); 
                pinturas->range(ans, upto);
            } else {
                ans.erase(0, 2);
                string upto = ans;
                int ix = ans.find(' ');
                upto.erase(0, ix + 1);
                ans.erase(ix, std::string::npos); 
                monedas->range(stoll(ans), stoll(upto));
            }
        }
    }
    return 0;
}