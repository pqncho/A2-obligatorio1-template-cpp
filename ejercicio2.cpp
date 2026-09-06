#include <cassert>
#include <string>
#include <iostream>
//#include <limits>

#include "tads/table.cpp"
#include "tads/open_hash_table.cpp"

using namespace std;

int main()
{
    //registros
    int n;
    cin >> n;
    cin.ignore();
    Table *cajones = new OpenHashTable(n);
    for (int i = 0; i < n; i++) {
        string ans;
        getline(cin,ans);

    }
    //consultas
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string ans;
        getline(cin,ans);

    }
    return 0;
}