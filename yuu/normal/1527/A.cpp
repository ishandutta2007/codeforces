#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int k = 1;
    while (k * 2 <= n) k *= 2;
    k--;
    cout << k << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}