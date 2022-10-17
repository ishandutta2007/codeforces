#include <bits/stdc++.h>
using namespace std;

struct dsu {
    vector<int> fa;
    dsu(int n) : fa(n) { iota(fa.begin(), fa.end(), 0); }

    int find(int x) {
        while (x != fa[x]) x = fa[x] = fa[fa[x]];
        return x;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        return fa[y] = x, true;
    }
};

int main() {
    ios::sync_with_stdio(0);
    int h, w, q;
    cin >> h >> w >> q;
    vector ban(h + 2, vector<bool>(w + 2));
    for (int r = 1; r <= h; r++) {
        string s;
        cin >> s;
        for (int c = 1; c <= w; c++) {
            ban[r][c] = s[c - 1] == '#';
        }
    }
    for (int r = 3; r <= h + 1; r++) {
        ban[r][0] = 1;
    }
    for (int c = 1; c <= w - 2; c++) {
        ban[h + 1][c] = 1;
    }
    for (int c = 3; c <= w + 1; c++) {
        ban[0][c] = 1;
    }
    for (int r = 1; r <= h - 2; r++) {
        ban[r][w + 1] = 1;
    }
    vector bel(h + 2, vector(w + 2, -1));
    int cnt = 0;
    {
        auto dfs = [&](auto self, int r, int c) -> void {
            for (int x : {r - 1, r, r + 1}) {
                for (int y : {c - 1, c, c + 1}) {
                    if (x < 0 || x > h + 1 || y < 0 || y > w + 1) continue;
                    if (~bel[x][y] || !ban[x][y]) continue;
                    bel[x][y] = bel[r][c], self(self, x, y);
                }
            }
        };
        for (int r = 0; r <= h + 1; r++) {
            for (int c = 0; c <= w + 1; c++) {
                if (ban[r][c] && !~bel[r][c]) {
                    bel[r][c] = cnt++, dfs(dfs, r, c);
                }
            }
        }
    }
    set<pair<int, int>> E;
    for (int r = 0; r <= h + 1; r++) {
        for (int c = 0; c <= w + 1; c++) if (ban[r][c]) {
            for (int x = max(0, r - 2); x <= min(h + 1, r + 2); x++) {
                for (int y = max(0, c - 2); y <= min(w + 1, c + 2); y++) {
                    if (ban[x][y] && bel[r][c] != bel[x][y]) {
                        E.insert(minmax(bel[r][c], bel[x][y]));
                    }
                }
            }
        }
    }
    int lhs = bel[3][0], rhs = bel[0][3];
    while (q--) {
        int k;
        cin >> k;
        vector<pair<int, int>> v(k);
        unordered_map<int, int> id;
        id.emplace(lhs, 0), id.emplace(rhs, 0);
        for (auto &[r, c] : v) {
            cin >> r >> c;
            id.emplace(bel[r][c] = cnt++, 0);
            for (int x : {r - 1, r, r + 1}) {
                for (int y : {c - 1, c, c + 1}) {
                    if (~bel[x][y]) id.emplace(bel[x][y], 0);
                }
            }
        }
        int tot = 0;
        for (auto &[_, x] : id) {
            x = tot++;
        }
        dsu T(id.size());
        for (auto &[r, c] : v) {
            int i = id[bel[r][c]];
            for (int x : {r - 1, r, r + 1}) {
                for (int y : {c - 1, c, c + 1}) {
                    if (~bel[x][y]) T.merge(i, id[bel[x][y]]);
                }
            }
        }
        cout << ([&] {
            for (auto &[x, p] : id) if (T.same(p, id[lhs])) {
                for (auto &[y, q] : id) if (T.same(q, id[rhs])) {
                    if (E.count(minmax(x, y))) return 1;
                }
            }
            for (auto &[r, c] : v) {
                int i = id[bel[r][c]];
                for (int x = max(0, r - 2); x <= min(h + 1, r + 2); x++) {
                    for (int y = max(0, c - 2); y <= min(w + 1, c + 2); y++) {
                        if (!id.count(bel[x][y])) continue;
                        int j = id[bel[x][y]];
                        if (T.same(i, id[lhs]) && T.same(j, id[rhs])) return 1;
                        if (T.same(i, id[rhs]) && T.same(j, id[lhs])) return 1;
                    }
                }
            }
            return 0;
        }() ? "NO" : "YES") << endl;
        cnt -= k;
        for (auto &[r, c] : v) {
            bel[r][c] = -1;
        }
    }
    return 0;
}