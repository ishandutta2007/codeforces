#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int b, g, n;

int main(){
    while(cin >> b >> g >> n){
        b = min(n, b);
        g = min(n, g);
        cout << b + g - n + 1 << endl;
    }
    return 0;
}