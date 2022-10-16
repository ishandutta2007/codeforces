#include <bits/stdc++.h>
using namespace std;
int x, d;

bool is_prime(int x) {
    if (x == 1) return true;
    for (int y = 2; y * y <= x; y++) {
        if (x % y == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> x >> d;
    int p = 0;
    int ox = x;
    while (x % d == 0) {
        x /= d;
        p++;
    }
    if (p == 1) {
        cout << "NO\n";
        return;
    }
    if (!is_prime(x)) {
        cout << "YES\n";
        return;
    }
    // x is prime, need to distribute one d if possible
    if (is_prime(d)) {
        cout << "NO\n";
        return;
    }
    if (p == 2) {
        cout << "NO\n";
        return;
    }
    if (p >= 4) {
        cout << "YES\n";
        return;
    }
    // p == 3
    // -> we need to find 2 multiple of of d such that none of them is disible by d^2
    // just do a loop
    for (int a = d; a * a <= ox; a += d) {
        int b = ox / a;
        if (b % d) continue;
        if ((a % (d * d) == 0) || (b % (d * d) == 0)) continue;
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}