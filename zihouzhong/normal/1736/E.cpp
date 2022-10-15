#include <bits/stdc++.h>
using namespace std;

void chk(int &x, int y) {
    if (x < y) x = y;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    vector f(n + 1, vector<int>(n, -1e9));
    for (int i = 0; i < n; i++) {
        vector g(i + 2, vector<int>(n + 1, -1e9));
        for (int j = i; ~j; j--) {
            for (int k = 0; k <= i; k++) {
                chk(g[j][i + 1], f[j][k]);
                if (k < i) chk(f[j + 1][i], f[j][k]);
            }
        }
        for (int j = i; ~j; j--) {
            for (int k = 0; k < n; k++) {
                if (j < i && k) chk(g[j][k], g[j + 1][k - 1]);
                chk(f[j][k], g[j][k]);
            }
        }
        if (!i) f[0][1] = f[1][0] = 0;
        for (int j = 0; j <= i + 1; j++) {
            for (int k = 0; k < n; k++) {
                f[j][k] += a[k];
            }
        }
    }
    int ans = 0;
    for (auto &v : f) {
        chk(ans, *max_element(v.begin(), v.end()));
    }
    cout << ans << "\n";
    return 0;
}