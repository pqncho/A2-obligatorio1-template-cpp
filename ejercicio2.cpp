#include <cassert>
#include <string>
#include <iostream>
//#include <limits>

#include "tads/hash_string_func.cpp"
#include "tads/table.cpp"
#include "tads/open_hash_table.cpp"

using namespace std;

string ordenALfabetico(string s) {
    int* letters = new int[26]();
    for (int i = 0; i < s.length(); i++) {
        letters[s[i] - 'a']++;
    }

    string ordered = "";
    for (int i = 0; i < 26; i++) {
        while(letters[i] > 0) {
            ordered += (char)('a' + i);
            letters[i]--;
        }
    }
    return ordered; 
}

int main()
{
    //registros
    int n;
    cin >> n;
    cin.ignore();
    table<string, string> *cajones = new OpenHashTable<string, string>(n, new stringHash());
    for (int i = 0; i < n; i++) {
        string ans;
        cin >> ans;
        cajones->set(ordenALfabetico(ans));
    }
    //consultas
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string ans;
        cin >> ans;
        cout << cajones->get(ordenALfabetico(ans)) << endl;
    }
    cout << cajones->getFilledBoxes() << " " << cajones->getMaxBox() << endl;
    return 0;
}
