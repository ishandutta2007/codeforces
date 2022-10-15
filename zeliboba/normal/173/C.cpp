#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int n, m;

bool in (int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

vvi dir(4, vi(3));

int down (int x, int y) {
    if (x < y)
        return x;
    return x - y;
}

int main() {
    dir[0][2] = dir[3][1] = 1;
    dir[2][2] = dir[1][1] = -1;
    dir[1][0] = dir[3][0] = 1;
    cin >> n >> m;
    vvi v(n, vi(m));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
        scanf("%d", &v[i][j]);
    vector<vvi> ps(2, vvi(505));
    for (int i = 0; i < n; ++i) {
        ps[0][i].assign(m + 1, 0);
        for (int j = 0; j < m; ++j)
            ps[0][i][j + 1] = ps[0][i][j] + v[i][j];
    }
    for (int i = 0; i < m; ++i) {
        ps[1][i].assign(n + 1, 0);
        for (int j = 0; j < n; ++j)
            ps[1][i][j + 1] = ps[1][i][j] + v[j][i];
    }
    ll ma = -1e9;
    for (int i1 = 0; i1 < n; ++i1) for (int j1 = 0; j1 < m; ++j1) for (int d1 = 0; d1 < 4; d1 += 2) {
        int i = i1, j = j1, d = d1, k = 2, t = 0;
        ll sum = 0;
        while (in(i + dir[d][1] * k, j + dir[d][2] * k)) {
            int ni = i + dir[d][1] * k, nj = j + dir[d][2] * k;
            int l = i, m1, m2;
            if (dir[d][0]) {
                m2 = max(i, ni);
                m1 = min(i, ni);
                l = j;
            } else {
                m2 = max(j, nj);
                m1 = min(j, nj);
            }
            if (d == 0 || d == 3)
                sum += ps[dir[d][0]][l][m2] - ps[dir[d][0]][l][m1];
            else sum += ps[dir[d][0]][l][m2 + 1] - ps[dir[d][0]][l][m1 + 1];
//            cerr << sum << endl;
            i = ni, j = nj;
            d = down(d + 1, 4);
            ++t;
            if (d == 2 && t > 1) {
                ma = max(ma, sum + ps[0][i][j + 1] - ps[0][i][j - k]);
/*                if (ma == 9) {
                    cerr << i1 << " " << j1 << " " << d1 << " " << t << " " << k << endl;
                    cerr << i << " " << j << endl;
                    return 0;
                }*/
            }
            if (t % 2 == 0)
                k += 2;
        }
    }
    cout << ma << endl;
    return 0;
}