#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, fa[maxn], l[maxn], r[maxn], a[maxn];
vector<int> G[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            G[i].clear();
        }
        for (int i = 2; i <= n; i++) {
            cin >> fa[i], G[fa[i]].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            cin >> l[i] >> r[i];
        }
        int ans = n;
        auto dfs = [&](auto self, int u) -> void {
            if (G[u].empty()) { a[u] = r[u]; return; }
            long long sum = 0;
            for (int v : G[u]) {
                self(self, v), sum += a[v];
            }
            if (sum >= l[u]) a[u] = min(1LL * r[u], sum), ans--;
            else a[u] = r[u];
        };
        dfs(dfs, 1);
        cout << ans << "\n";
    }
    return 0;
}