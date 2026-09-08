#include <cassert>
#include <string>
#include <iostream>
//#include <limits>

#include "tads/hash_string_func.cpp"
#include "tads/table.cpp"
#include "tads/open_hash_table.cpp"

using namespace std;

int main()
{
    //registros
    int n;
    cin >> n;
    cin.ignore();
    table<string, string> *cajones = new OpenHashTable<string, string>(n, new stringHash());
    for (int i = 0; i < n; i++) {
        string ans;
        getline(cin,ans);
        cajones->set(ans);
    }
    //consultas
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string ans;
        getline(cin,ans);
        cout << cajones->get(ans) << endl;
    }
    cout << cajones->getFilledBoxes() << " " << cajones->getMaxBox() << endl;
    return 0;
}