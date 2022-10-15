#include <bits/stdc++.h>
using namespace std;

struct dsu {
    vector<int> fa, sz;
    dsu(int n) : fa(n), sz(n, 1) { iota(fa.begin(), fa.end(), 0); }

    int find(int x) {
        while (x != fa[x]) x = fa[x] = fa[fa[x]];
        return x;
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        sz[x] += sz[y], fa[y] = x;
        return true;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> d(n);
    for (int &x : d) {
        cin >> x;
    }
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int i, int j) { return d[i] > d[j]; });
    dsu T(n);
    vector<bool> vis(n);
    int sum = 0;
    for (int i : id) {
        if (vis[i]) continue;
        vis[i] = 1;
        for (int k = 0; k < d[i]; k++) {
            if (++sum > n) assert(0);
            cout << "? " << i + 1 << endl;
            int j;
            cin >> j, j--;
            T.merge(i, j);
            if (vis[j]) break;
            vis[j] = 1;
        }
    }
    cout << "!";
    for (int i = 0; i < n; i++) {
        cout << " " << T.find(i) + 1;
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}