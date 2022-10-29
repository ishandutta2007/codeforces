#include <bits/stdc++.h>
using namespace std;

int main () {
    int y,r,b;
    cin >> y >> b >> r;
    for (int i=1;i<=1000;++i) {
        if (i <= y && i+1 <= b && i+2 <= r) {
            ;
        }
        else {
            cout << i-1 + (i) + (i+1) << endl;
            return 0;
        }
    }
}