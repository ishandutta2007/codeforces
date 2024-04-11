#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 2>>> a(n + m), b(n + m);
    bool swapped = 0;
    if (n > m) {
        swapped = 1, swap(n, m);
        for (int x = 0; x < m; x++) {
            for (int y = 0, z; y < n; y++) {
                cin >> z;
                if (!z) continue;
                a[y].push_back({z, n + x});
                a[n + x].push_back({z, y});
            }
        }
        for (int x = 0; x < m; x++) {
            for (int y = 0, z; y < n; y++) {
                cin >> z;
                if (!z) continue;
                b[y].push_back({z, n + x});
                b[n + x].push_back({z, y});
            }
        }
    } else {
        for (int x = 0; x < n; x++) {
            for (int y = 0, z; y < m; y++) {
                cin >> z;
                if (!z) continue;
                a[x].push_back({z, n + y});
                a[n + y].push_back({z, x});
            }
        }
        for (int x = 0; x < n; x++) {
            for (int y = 0, z; y < m; y++) {
                cin >> z;
                if (!z) continue;
                b[x].push_back({z, n + y});
                b[n + y].push_back({z, x});
            }
        }
    }
    for (int i = 0; i < n + m; i++) {
        sort(a[i].begin(), a[i].end());
        sort(b[i].begin(), b[i].end());
    }
    vector<int> ver, lnk(n + m, -1);
    vector<bool> vis(n + m);
    auto dfs = [&](auto self, int u, int v) -> bool {
        if (~lnk[u]) return lnk[u] == v;
        if (vis[v]) return 0;
        lnk[u] = v, vis[v] = 1;
        ver.push_back(u);
        if (a[u].size() != b[v].size()) return 0;
        for (int i = 0; i < a[u].size(); i++) {
            if (a[u][i][0] != b[v][i][0]) return 0;
            if (!self(self, a[u][i][1], b[v][i][1])) return 0;
        }
        return 1;
    };
    for (int u = 0; u < n; u++) if (!~lnk[u]) {
        for (int v = 0; v < n; v++) {
            if (dfs(dfs, u, v)) {
                ver.clear(); break;
            }
            for (int x : ver) {
                vis[lnk[x]] = 0, lnk[x] = -1;
            }
            ver.clear();
        }
        if (!~lnk[u]) cout << "-1\n", exit(0);
    }
    for (int i = n, j = n; i < n + m; i++) if (!~lnk[i]) {
        while (vis[j]) j++;
        lnk[i] = j, vis[j] = 1;
    }
    vector<array<int, 3>> res;
    for (int i = 0; i < n + m; i++) if (~lnk[i]) {
        vector<int> cyc;
        int x = i;
        while (~lnk[x]) {
            cyc.push_back(x);
            int y = lnk[x];
            lnk[x] = -1, x = y;
        }
        for (int j = cyc.size() - 2; ~j; j--) {
            if (i < n) res.push_back({swapped, cyc[j], cyc[j + 1]});
            else res.push_back({!swapped, cyc[j] - n, cyc[j + 1] - n});
        }
    }
    cout << res.size() << "\n";
    for (auto &p : res) {
        for (int &x : p) cout << x + 1 << " ";
        cout << "\n";
    }
    return 0;
}