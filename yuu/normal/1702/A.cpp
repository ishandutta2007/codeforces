#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t m;
    cin >> m;
    int64_t p = 1;
    while (p * 10 <= m) p *= 10;
    cout << m - p << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}