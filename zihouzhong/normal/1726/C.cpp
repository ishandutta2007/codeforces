#include <bits/stdc++.h>
using namespace std;

struct dsu {
    vector<int> fa, sz;
    dsu(int n) : fa(n), sz(n, 1) { iota(fa.begin(), fa.end(), 0); }

    int find(int x) {
        while (x != fa[x]) x = fa[x] = fa[fa[x]];
        return x;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        sz[x] += sz[y], fa[y] = x;
        return true;
    }
    int size(int x) { return sz[find(x)]; }

    vector<vector<int>> groups() {
        vector<vector<int>> res(fa.size());
        for (int i = 0; i < fa.size(); i++) {
            res[find(i)].push_back(i);
        }
        res.erase(remove_if(res.begin(), res.end(),
            [&](const auto &v) { return v.empty(); }), res.end());
        return res;
    }
};

void solve() {
    int n;
    string str;
    cin >> n >> str;
    dsu T(2 * n);
    vector<int> st, pre(2 * n, -1);
    for (int i = 0; i < 2 * n; i++) {
        if (str[i] == '(') {
            st.push_back(i);
        } else {
            int j = st.back();
            pre[i] = j, T.merge(i, j);
            while (j) {
                j = pre[j - 1];
                if (!~j || !T.merge(i, j)) break;
            }
            st.pop_back();
        }
    }
    cout << T.groups().size() << "\n";
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