#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, m, p[N], dep[N];
bool vis[N];
vector<pair<int, int>> e[N];
string ans;
set<int> nodes;

void dfs(int u, int fa) {
    vis[u] = 1;
    for (auto it : e[u]) {
        int v = it.first;
        int i = it.second;
        if (v != fa) {
            if (!vis[v]) {
                ::p[v] = i;
                dep[v] = dep[u] + 1;
                dfs(v, u);
            } else {
                nodes.insert(u);
                nodes.insert(v);
                ans[i] = '1';
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        e[u].emplace_back(v, i - 1);
        e[v].emplace_back(u, i - 1);
    }

    ans = string(m, '0');
    nodes.clear();
    memset(vis + 1, 0, n);

    dfs(1, 0);

    if ((int) nodes.size() == 3) {
        vector<int> v;
        for (auto x : nodes) {
            v.emplace_back(x);
        }
        sort(v.begin(), v.end(), [&](int x, int y) {
            return dep[x] < dep[y];
        });

        int x = v[2], y = v[1];
        ans[p[x]] = '1';
        for (auto it : e[x]) {
            int v = it.first;
            int i = it.second;
            if (v == y) {
                ans[i] = '0';
            }
        }        
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}