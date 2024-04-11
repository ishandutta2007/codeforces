#include <bits/stdc++.h>
using namespace std;

bool check(int x, int y) {
    if (y >= x - 1 && 2 * (x + 1) >= y) return true;
    return false;
}

int main () {
    int a, b, c, d; cin >> a >> b >> c >> d;
    if (check(b, c) || check(a, d)) cout << "YES" << endl;
    else cout << "NO" << endl;
}