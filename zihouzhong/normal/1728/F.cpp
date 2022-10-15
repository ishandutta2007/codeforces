#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> G(n * n);
    map<int, int> mp;
    int tot = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        for (int j = 1; j <= n; j++) {
            if (!mp.count(x * j)) mp[x * j] = tot++;
            G[mp[x * j]].push_back(i);
        }
    }
    vector vis(n * n, -1), lnk(n, -1);
    int tim = 0;
    auto match = [&](auto self, int u) -> bool {
        vis[u] = tim;
        for (int v : G[u]) {
            if (vis[lnk[v]] == tim) continue;
            if (!~lnk[v] || self(self, lnk[v])) return lnk[v] = u, 1;
        }
        return 0;
    };
    long long ans = 0;
    for (auto &[x, i] : mp) {
        if (match(match, i)) {
            ans += x;
            if (tim++ == n) break;
        }
    }
    cout << ans << "\n";
    return 0;
}