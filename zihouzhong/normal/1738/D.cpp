#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int &x : b) {
        cin >> x, x--;
    }
    vector<int> pre(n), suf(n);
    pre[0] = b[0];
    for (int i = 1; i < n; i++) {
        pre[i] = min(pre[i - 1], b[i]);
    }
    suf.back() = b.back();
    for (int i = n - 2; ~i; i--) {
        suf[i] = max(suf[i + 1], b[i]);
    }
    int k;
    for (int i = 0; i <= n; i++) {
        if ((!i || pre[i - 1] >= i) && (i == n || suf[i] < i)) k = i;
    }
    vector<vector<int>> G(n);
    vector<int> ind(n), outd(n);
    for (int i = 0; i < k; i++) {
        if (b[i] < n) G[b[i]].push_back(i), ind[i]++, outd[b[i]]++;
    }
    for (int i = k; i < n; i++) {
        if (~b[i]) G[b[i]].push_back(i), ind[i]++, outd[b[i]]++;
    }
    cout << k << "\n";
    for (int i = 0; i < n; i++) if (!ind[i] && !outd[i]) {
        cout << i + 1 << " ";
    }
    for (int i = 0; i < n; i++) if (!ind[i] && outd[i]) {
        auto dfs = [&](auto self, int u) -> void {
            cout << u + 1 << " ";
            for (int v : G[u]) {
                if (G[v].empty()) self(self, v);
            }
            for (int v : G[u]) {
                if (!G[v].empty()) self(self, v);
            }
        };
        dfs(dfs, i);
    }
    cout << "\n";
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