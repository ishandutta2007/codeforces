#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int n, m, T;
    cin >> n >> m >> T;
    vector<vector<int>> G(n);
    vector<int> ind(n);
    while (m--) {
        int u, v;
        cin >> u >> v, u--, v--;
        G[u].push_back(v), ind[v]++;
    }
    vector<int> ord;
    {
        queue<int> Q;
        for (int i = 0; i < n; i++) {
            if (!ind[i]) Q.push(i);
        }
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            ord.push_back(u);
            for (int v : G[u]) {
                if (!--ind[v]) Q.push(v);
            }
        }
    }
    reverse(ord.begin(), ord.end());
    vector<tuple<char, int, int>> op;
    int k = min(20, n);
    map<int, int> mp;
    for (int i = 0; i < k; i++) {
        mp[ord[i]] = i;
        for (int j = 0; j < i; j++) {
            op.emplace_back('+', ord[i], ord[j]);
        }
    }
    vector<vector<int>> mask(k + 1);
    for (int S = 0; S < 1 << k; S++) {
        mask[__builtin_popcount(S)].push_back(S);
    }
    vector res(1 << k, -1);
    for (int i = k; i < n; i++) {
        int u = ord[i], S = 0;
        op.emplace_back('+', u, u);
        for (int j : G[u]) {
            if (mp.count(j)) S |= 1 << mp[j];
        }
        for (auto &v : mask) {
            for (int T : v) {
                if (~res[S ^ T]) continue;
                res[S ^ T] = u;
                while (T) {
                    int j = __builtin_ctz(T);
                    op.emplace_back(S >> j & 1 ? '-' : '+', u, ord[j]);
                    T ^= 1 << j;
                }
                goto next;
            }
        }
    next:;
    }
    cout << op.size() << endl;
    for (auto &[ch, u, v] : op) {
        cout << ch << " " << u + 1 << " " << v + 1 << endl;
    }
    while (T--) {
        int ans = -1, S = 0;
        for (int i = 0; i < k; i++) {
            cout << "? 1 " << ord[i] + 1 << "\n";
            string type;
            cin >> type;
            if (type == "Win") S |= 1 << i;
            else if (type == "Lose") { ans = ord[i]; break; }
        }
        cout << "! " << (~ans ? ans : res[S]) + 1 << endl;
        cin >> *new string;
    }
    return 0;
}