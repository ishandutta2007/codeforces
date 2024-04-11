#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k;
    cin >> k;
    int l = 100 - k;
    int d = gcd(k, l);
    k /= d;
    l /= d;
    cout << k + l << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}