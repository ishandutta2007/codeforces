#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using P = pair<int, int>;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

const int MD = 1100100;
int n, m;
vector<vi> v;
vector<P> g[MD];
vector<vector<array<P, 4>>> nex;
vector<vector<int>> used;

vector<P> buf_pos;
void dfs(int x, int y) {
    used[x][y] = true;
    buf_pos.push_back(P(x, y));
    for (int i = 0; i < 4; i++) {
        P pp = nex[x][y][i];
        if (x != pp.first and y != pp.second) continue;
        if (used[pp.first][pp.second]) continue;
        dfs(pp.first, pp.second);
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            g[v[i][j]].push_back(P(i, j));
        }
    }

    P bak[MD];
    fill_n(bak, MD, P(-1, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int vv = v[i][j];
            nex[i][j][0] = bak[vv];
            bak[vv] = P(i, j);
        }
    }

    fill_n(bak, MD, P(-1, -1));
    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            int vv = v[i][j];
            nex[i][j][1] = bak[vv];
            bak[vv] = P(i, j);
        }
    }

    fill_n(bak, MD, P(-1, -1));
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            int vv = v[i][j];
            nex[i][j][2] = bak[vv];
            bak[vv] = P(i, j);
        }
    }

    fill_n(bak, MD, P(-1, -1));
    for (int j = m-1; j >= 0; j--) {
        for (int i = n-1; i >= 0; i--) {
            int vv = v[i][j];
            nex[i][j][3] = bak[vv];
            bak[vv] = P(i, j);
        }
    }


    int mx[n], my[m];
    fill_n(mx, n, 0);
    fill_n(my, m, 0);

    for (int i = 0; i < MD; i++) {
        for (P p: g[i]) {
            if (used[p.first][p.second]) continue;
            buf_pos.clear();
            dfs(p.first, p.second);
            int u = 1;
            for (P p: buf_pos) {
                u = max(u, mx[p.first]+1);
                u = max(u, my[p.second]+1);
            }

            for (P p: buf_pos) {
                v[p.first][p.second] = u;
            }

            for (P p: buf_pos) {
                mx[p.first] = u;
                my[p.second] = u;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }

}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        vi vv;
        for (int j = 0; j < m; j++) {
            int x;
            scanf("%d", &x);
            vv.push_back(x);
        }
        v.push_back(vv);
    }

    vector<int> vl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vl.push_back(v[i][j]);
        }
    }
    sort(vl.begin(), vl.end());
    vl.erase(unique(vl.begin(), vl.end()), vl.end());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            v[i][j] = lower_bound(vl.begin(), vl.end(), v[i][j]) - vl.begin();
        }
    }

    nex.resize(n);
    for (int i = 0; i < n; i++) {
        nex[i].resize(m);
    }
    used.resize(n);
    for (int i = 0; i < n; i++) {
        used[i].resize(m);
    }

    solve();
    return 0;
}