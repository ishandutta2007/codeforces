#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[100001];
int p[100001];
vector<int> pos[100001];
int f[100002][18];
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= 100000; i++)
        if (p[i] == 0)
            for (int j = i; j <= 100000; j += i)
                if (p[j] == 0) p[j] = i;
    for (int i = 1; i <= n; i++) {
        while (a[i] > 1) {
            int prime = p[a[i]];
            pos[prime].push_back(i);
            while (a[i] % prime == 0) a[i] /= prime;
        }
    }
    for (int i = 1; i <= n + 1; i++)
        for (int j = 0; j < 18; j++) f[i][j] = n + 1;
    for (int i = 1; i <= 100000; i++) {
        for (int j = 1; j < pos[i].size(); j++) {
            f[pos[i][j - 1]][0] = min(f[pos[i][j - 1]][0], pos[i][j]);
        }
    }
    for (int i = n - 1; i >= 1; i--) f[i][0] = min(f[i][0], f[i + 1][0]);
    for (int i = n; i >= 1; i--) {
        for (int j = 0; f[i][j] != (n + 1); j++) {
            f[i][j + 1] = f[f[i][j]][j];
        }
    }
    for (int i = 1, l, r; i <= q; i++) {
        cin >> l >> r;
        int ans = 0;
        for (int j = 17; j >= 0; j--) {
            if (f[l][j] <= r) {
                ans ^= (1 << j);
                l = f[l][j];
            }
        }
        cout << ans + 1 << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}