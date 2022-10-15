#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k, k++;
    vector<int> p(n);
    for (int &x : p) {
        cin >> x, x--;
    }
    vector<int> q(n);
    for (int i = 0; i < n; i++) {
        q[p[i]] = i;
    }
    vector f(k + 1, vector(1 << k, INF));
    f[0][0] = 0;
    for (int i = 0; i < n; i++) {
        int j = max(0, i - k), _j = max(0, i + 1 - k);
        vector g(k + 1, vector(1 << k, INF));
        for (int pre = 0; pre <= k; pre++) {
            vector<int> coef(n);
            for (int x = 0; x < j + pre; x++) {
                coef[q[x]]++;
            }
            partial_sum(coef.rbegin(), coef.rend(), coef.rbegin());
            for (int S = 0; S < 1 << k; S += 2) {
                if (f[pre][S] == INF) continue;
                for (int x = 0; x < k; x++) {
                    if ((S >> x & 1) || j + pre + x >= n) continue;
                    int w = coef[q[j + pre + x]];
                    for (int mask = S; mask; ) {
                        int y = __builtin_ctz(mask);
                        if (q[j + pre + y] > q[j + pre + x]) w++;
                        mask ^= 1 << y;
                    }
                    int T = S | (1 << x);
                    int inc = __builtin_ctz(T + 1);
                    T >>= inc;
                    int _pre = pre + inc + j - _j;
                    if (_pre < 0) continue;
                    g[_pre][T] = min(g[_pre][T], f[pre][S] + w);
                }
            }
        }
        swap(f, g);
    }
    cout << f[n - max(0, n - k)][0] << "\n";
    return 0;
}