#include <bits/stdc++.h>
using namespace std;

void NO() {
    cout << "NO" << endl;
    exit(0);
}

int main () {
    int x,y,z,a,b,c;
    cin >> x >> y >> z >> a >> b >> c;
    if (x > a) {
        NO();
    }
    a -= x;
    b += a;
    if (y > b) {
        NO();
    }
    b -= y;
    c += b;
    if (z > c) {
        NO();
    }
    cout << "YES" << endl;
}