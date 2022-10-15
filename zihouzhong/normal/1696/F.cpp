#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int T, n, d[maxn][maxn];
bool vis[maxn];
bitset<maxn> b[maxn][maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                string str;
                cin >> str, b[i][j].reset();
                for (int k = 1; k <= n; k++) {
                    if (str[k - 1] == '1') b[i][j][k] = 1;
                }
                b[j][i] = b[i][j];
            }
        }
        auto chk = [&](int i, int j, int k) -> bool {
            if (i == j) return 1;
            return b[i][j][k];
        };
        for (int rt = 2; rt <= n; rt++) {
            memset(vis, 0, sizeof(vis));
            vector<array<int, 2>> E;
            auto dfs = [&](auto self, int u, int adj) -> void {
                vis[u] = 1;
                for (int v = 1; v <= n; v++) {
                    if (!vis[v] && chk(adj, v, u)) {
                        E.push_back({v, u}), self(self, v, u);
                    }
                }
            };
            dfs(dfs, 1, rt);
            if (E.size() != n - 1) continue;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    d[i][j] = i == j ? 0 : n;
                }
            }
            for (auto &e : E) {
                d[e[0]][e[1]] = d[e[1]][e[0]] = 1;
            }
            for (int k = 1; k <= n; k++) {
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    }
                }
            }
            bool flag = 1;
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    for (int k = 1; k <= n; k++) {
                        flag &= b[i][j][k] == (d[i][k] == d[j][k]);
                    }
                }
            }
            if (flag) {
                cout << "Yes\n";
                for (auto &e : E) {
                    cout << e[0] << " " << e[1] << "\n";
                }
                goto next;
            }
        }
        cout << "No\n";
    next:;
    }
    return 0;
}