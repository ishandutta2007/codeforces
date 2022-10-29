#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
    string a;
    int n;
    int x,y;
    while (cin >> n >>x >> y) {
        cin >>a;
        x--;
        y--;
        if (a[x] == a[y]) puts("0");
        else puts("1");
    }
}