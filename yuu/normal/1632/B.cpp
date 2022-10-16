#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int key = 1 << __lg(n - 1);
    for (int i = n - 1; i >= key; i--) cout << i << ' ';
    for (int i = 0; i < key; i++) cout << i << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}