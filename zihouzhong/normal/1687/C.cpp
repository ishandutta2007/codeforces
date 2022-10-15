#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, m, a[maxn], b[maxn], d[maxn], nxt[maxn];
array<int, 2> c[maxn];
long long s[maxn];
vector<int> G[maxn];

int find(int x) {
    return x == nxt[x] ? x : nxt[x] = find(nxt[x]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i], b[i] -= a[i];
            s[i] = s[i - 1] + b[i];
        }
        for (int i = 0; i <= n; i++) {
            G[i].clear();
        }
        iota(nxt, nxt + n + 2, 0);
        for (int i = 1; i <= m; i++) {
            cin >> c[i][0] >> c[i][1];
            c[i][0]--, d[i] = 2;
            G[c[i][0]].push_back(i), G[c[i][1]].push_back(i);
        }
        function<void(int)> upd = [&](int i) {
            if (i ^ find(i)) return;
            nxt[i] = i + 1;
            for (int j : G[i]) if (!--d[j]) {
                for (int k = find(c[j][0]); k <= c[j][1]; k = find(k)) upd(k);
            }
        };
        for (int i = 0; i <= n; i++) {
            if (!s[i]) upd(i);
        }
        cout << (find(0) == n + 1 ? "YES\n" : "NO\n");
    }
    return 0;
}