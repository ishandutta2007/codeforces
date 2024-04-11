#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, K;
    cin >> n >> K;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end(), [&](int x, int y) { return abs(x) < abs(y); });
    int zero = count(a.begin(), a.end(), 0);
    array<vector<int>, 2> pre;
    for (int k : {0, 1}) {
        pre[k] = {0};
        for (int i = 0; i < n; i++) {
            pre[k].push_back(pre[k].back() + (!k ? a[i] > 0 : a[i] < 0));
        }
    }
    vector<int> pw(n + 1);
    for (int i = pw[0] = 1; i <= n; i++) {
        pw[i] = 2 * pw[i - 1] % P;
    }
    int ans = 0;
    array<vector<int>, 2> f;
    f.fill(vector<int>(K));
    f[0][0] = 1;
    for (int i = n - 1; ~i; i--) if (a[i]) {
        int ti = a[i] < 0;
        ans = (ans + 1LL * a[i] * (f[0][K - 1] + f[1][K - 1])) % P;
        ans = (ans + 1LL * a[i] * (pw[i] - 1) % P * f[ti][K - 1]) % P;
        auto g = f;
        g.fill(vector<int>(K));
        for (int j = K - 1; j; j--) {
            g[0][j] = f[ti][j - 1], g[1][j] = f[!ti][j - 1];
        }
        for (int j = i - 1; ~j; j--) if (a[j] && ti ^ (a[j] < 0)) {
            int tj = a[j] < 0;
            for (int x = j - 1, y = j - 1; ~x; x--) if (a[x] && ti == (a[x] < 0)) {
                while (~y && abs(1LL * a[j] * a[y]) > 1LL * a[i] * a[x]) y--;
                ans = (ans + 1LL * g[!tj][K - 1] * a[i] % P * a[x] % P * pw[pre[ti][x] + pre[!ti][y + 1] + zero]) % P;
            }
            for (int x = j - 1, y = j - 1; ~x; x--) if (a[x] && tj == (a[x] < 0)) {
                while (~y && abs(1LL * a[i] * a[y]) >= 1LL * a[j] * a[x]) y--;
                ans = (ans + 1LL * g[!tj][K - 1] * a[j] % P * a[x] % P * pw[pre[tj][x] + pre[!tj][y + 1] + zero]) % P;
            }
            for (int k = K - 1; k; k--) {
                g[0][k] = (g[0][k] + 1LL * a[j] * g[tj][k - 1]) % P;
                g[1][k] = (g[1][k] + 1LL * a[j] * g[!tj][k - 1]) % P;
            }
        }
        for (int j = K - 1; j; j--) {
            f[0][j] = (f[0][j] + 1LL * a[i] * f[ti][j - 1]) % P;
            f[1][j] = (f[1][j] + 1LL * a[i] * f[!ti][j - 1]) % P;
        }
    }
    if (K % 2) {
        vector<int> f(K);
        f[0] = 1;
        for (int i = 0; i < n; i++) if (a[i] < 0) {
            ans = (ans + 1LL * f[K - 1] * a[i] % P * (pw[pre[1][n] - pre[1][i + 1]] - 1)) % P;
            for (int j = K - 1; j; j--) {
                f[j] = (f[j] + 1LL * a[i] * f[j - 1]) % P;
            }
        }
        f.assign(K, 0), f[0] = 1;
        for (int i = n - 1; ~i; i--) if (a[i] < 0) {
            for (int j = i - 1; ~j; j--) if (a[j] > 0) {
                ans = (ans + 1LL * f[K - 1] * a[j] % P * pw[pre[0][j] + pre[1][i] + zero]) % P;
            }
            for (int j = K - 1; j; j--) {
                f[j] = (f[j] + 1LL * a[i] * f[j - 1]) % P;
            }
        }
    }
    cout << (ans + P) % P << "\n";
    return 0;
}