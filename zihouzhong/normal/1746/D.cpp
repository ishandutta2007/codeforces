#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> fa(n);
    vector<vector<int>> G(n);
    for (int i = 1; i < n; i++) {
        cin >> fa[i], fa[i]--;
        G[fa[i]].push_back(i);
    }
    vector<int> s(n);
    for (int &x : s) {
        cin >> x;
    }
    vector<map<int, ll>> mp(n);
    auto rec = [&](auto self, int u, int k) -> ll {
        if (mp[u].count(k)) return mp[u][k];
        ll ans = 1LL * k * s[u];
        if (!G[u].empty()) {
            int take = k % G[u].size();
            vector<ll> inc;
            for (int v : G[u]) {
                ll x = self(self, v, k / G[u].size());
                ans += x;
                if (take) inc.push_back(max<ll>(0, self(self, v, k / G[u].size() + 1) - x));
            }
            sort(inc.begin(), inc.end(), greater());
            for (int i = 0; i < take; i++) {
                ans += inc[i];
            }
        }
        return mp[u][k] = ans;
    };
    cout << rec(rec, 0, k) << "\n";
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