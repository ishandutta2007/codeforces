#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

struct Solver {
    int n;
    VV<int> g;
    string mp;
    V<int> wpos;

    V<int> col;
    void dfs(int p, int b, int c = 0) {
        col[p] = c;
        for (int d: g[p]) {
            if (d == b) continue;
            dfs(d, p, 1-c);
        }
    }
    int solve(VV<int> _g, string _mp) {
        g = _g; mp = _mp;
        n = int(g.size());
        for (int i = 0; i < n; i++) {
            if (mp[i] == 'W') wpos.push_back(i);
        }
        col = V<int>(n);
        dfs(0, -1);

        for (int i = 0; i < n; i++) {
            if (g[i].size() >= 4) return 1;
        }
        if (wpos.size() >= 3) return 1;
        if (wpos.size() == 2) {
            int a = wpos[0], b = wpos[1];
            if (col[a] == col[b]) return 1;
            if (g[a].size() >= 2) return 1;
            if (g[b].size() >= 2) return 1;
            for (int i = 0; i < n; i++) {
                if (g[i].size() >= 3) return 1;
            }
            return 0;
        }

        int buf[2] = {};
        for (int i = 0; i < n; i++) {
            if (g[i].size() == 3) {
                buf[col[i]]++;
                int cnt = 0;
                for (int j: g[i]) {
                    if (g[j].size() >= 2) cnt++;
                }
                if (cnt >= 2) return 1;
            }
        }
        if (buf[0] >= 2 || buf[1] >= 2) return 1;

        if (n == 3) return 0;

        if (wpos.size() == 1) {
            int a = wpos[0];
            if (buf[1 - col[a]]) return 1;
            if (g[a].size() >= 2) return 1;
            return 0;
        }

        return 0;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;

    int t;
    cin >> t;
    for (int ph = 0; ph < t; ph++) {
        int n;
        cin >> n;
        VV<int> g(n);
        for (int i = 0; i < n-1; i++) {
            int a, b;
            cin >> a >> b; a--; b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        string mp;
        cin >> mp;
        Solver solver;
        int u = solver.solve(g, mp);
        if (u == 1) cout << "White\n";
        if (u == 0) cout << "Draw\n";
        if (u == -1) cout << "Black\n"; //needed?
    }
    return 0;
}