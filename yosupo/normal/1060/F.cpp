#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

using D = double;

D C[100][100];
void first() {
    C[0][0] = 1.0;
    for (int i = 1; i < 100; i++) {
        C[i][0] = C[i-1][0];
        for (int j = 1; j < 100; j++) C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
}

int n;
VV<int> g;
using P = pair<int, int>;
map<P, VV<D>> mp;
VV<D> dfs(int p, int b) {
    P key = P(p, b);
    if (mp.count(key)) return mp[key];
    VV<D> old(1, V<D>(1));
    old[0][0] = 1;
    for (int d: g[p]) {
        if (d == b) continue;
        auto nx = dfs(d, p);

        //merge nw, nx
        int old_lw = int(old.size()) - 1;
        int old_uc = int(old[0].size()) - 1;
        int lw = int(nx.size()) - 1;
        int uc = int(nx[0].size()) - 1;

/*        VV<D> tbl_up(lw + 1, V<D>(uc + 1)), tbl_dw(lw + 1, V<D>(uc + 1));
        for (int i = lw-1; i >= 0; i--) {
            for (int j = 0; j <= uc; j++) {
                tbl_up[i][j] = tbl_up[i + 1][j] + nx[i][j];
            }
        }
        for (int i = 0; i < lw; i++) {
            for (int j = 0; j <= uc; j++) {
                tbl_dw[i + 1][j] = tbl_dw[i][j] + nx[i][j];
            }
        }*/

        VV<D> nw(old_lw + lw + 1, V<D>(old_uc + uc + 1));
        for (int i = 0; i <= old_lw; i++) {
            for (int j = 0; j <= old_uc; j++) {
                for (int k = 0; k <= lw; k++) {
                    for (int l = 0; l <= uc; l++) {
                        D p = C[i + k][i] * C[(old_lw - i) + (lw - k)][old_lw - i] / C[old_lw + lw][old_lw];
                        nw[i + k][j + l] += old[i][j] * nx[k][l] * p;
                    }
                }
            }
        }
        old = nw;
    }
    if (b == -1) return old;

    int lw = int(old.size()) - 1;
    int uc = int(old[0].size()) - 1;
    D ilw = 1.0 / (lw + 1);
    VV<D> dp(lw + 1 + 1, V<D>(uc + 1 + 1));
    for (int i = 0; i < lw + 1; i++) {
        for (int j = 0; j <= uc; j++) {
            for (int k = 0; k <= i; k++) {
                dp[k][1 + j] += old[i][j] * ilw;
            }
            for (int k = i + 1; k <= lw + 1; k++) {
                dp[k][j] += old[k - 1][j] * ilw;
            }
        }
    }
    //cerr << p << " " << b << " " << dp.size() << " " << dp[0].size() - 1 << endl;
    return mp[key] = dp;
}

int main() {
    first();
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;
    cin >> n;
    g = VV<int>(n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        auto tbl = dfs(i, -1)[0];
        D sm = 0;
        D freq = 1.0;
//        cout << tbl.size() << " " << n << endl;
        for (int j = 0; j < n; j++) {
            sm += tbl[j] * freq;
            freq *= 0.5;
        }
        cout << sm << endl;
    }
    return 0;
}