#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    vector<int> f(n + 1, INT_MAX);
    f[0] = 0;
    for (int i = 0; i < n; i++) {
        f[i + 1] = min(f[i + 1], f[i] + (a[i] > 0));
        int xors = 0;
        for (int j = i; ~j; j--) {
            xors ^= a[j];
            if (j < i && !xors) {
                f[i + 1] = min(f[i + 1], f[j] + i - j);
            }
        }
    }
    cout << f[n] << "\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}