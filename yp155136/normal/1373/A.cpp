#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void go() {
    ll a, b, c; cin >> a >> b >> c;
    cout << (a < c ? 1 : -1) << ' ';
    cout << (a * b > c ? b : -1) << endl;
}

int main () {
    int T; cin >> T;
    while (T--) {
        go();
    }
}