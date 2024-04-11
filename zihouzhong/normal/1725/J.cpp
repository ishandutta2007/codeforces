#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void chk(ll &x, ll y) {
    if (x > y) x = y;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> G(n);
    for (int i = 0, u, v, w; i < n - 1; i++) {
        cin >> u >> v >> w, u--, v--;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    auto dfs = [&](auto self, int u, int fa) -> array<array<ll, 2>, 5> {
        array<array<ll, 2>, 5> f{};
        for (auto &[v, w] : G[u]) if (v != fa) {
            auto g = self(self, v, u);
            decltype(f) h;
            for (auto &v : h) v.fill(1e18);
            for (int i = 0; i <= 4; i++) {
                for (int j = 0; i + j <= 4; j++) {
                    for (int k : {0, 1}) for (int l : {0, 1}) {
                        if (k && l) continue;
                        ll x = f[i][k] + g[j][l] + w * (j % 2 ? 1 : 2);
                        chk(h[i + j][k | l], x);
                        if (!k && !l && j == 2) chk(h[i + j][1], x - 2 * w);
                    }
                }
            }
            swap(f, h);
        }
        return f;
    };
    cout << dfs(dfs, 0, -1)[4][1] << "\n";
    return 0;
}