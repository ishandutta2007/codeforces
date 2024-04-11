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
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
char s[1001][1005];
int d[3][1001][1005];
int n,m;

bool in(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%s", s[i]);
    vii q;
    q.reserve(n*m);
    vvi md(3, vi(3, 1e8));
    for (int t = 0; t < 3; ++t) {
        q.clear();
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
            d[t][i][j] = 1e8;
            if (s[i][j] == '1' + t) {
                d[t][i][j] = 0;
                q.push_back(pii(i,j));
            }
        }
        for (int it = 0; it < q.size(); ++it) {
            int i = q[it].first;
            int j = q[it].second;
            for (int t1 = 0; t1 < 3; ++t1) if (s[i][j] == '1' + t1) {
                md[t][t1] = min(md[t][t1], d[t][i][j]);
            }
            for (int dir = 0; dir < 4; ++dir) {
                int x = i + dx[dir];
                int y = j + dy[dir];
                if (!in(x, y) || s[x][y] == '#') continue;
                if (d[t][x][y] > 1 + d[t][i][j]) {
                    d[t][x][y] = 1 + d[t][i][j];
                    q.push_back(pii(x, y));
                }
            }
        }
    }
    int mi = 1e8;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        mi = min(mi, d[0][i][j] + d[1][i][j] + d[2][i][j] - 2);
//        cerr << i << ' ' << j << ' ' << mi << endl;
    }
    for (int i = 0; i < 3; ++i) {
        int sum = 0;
        for (int j = 0; j < 3; ++j) {
            sum += md[i][j];
        }
        mi = min(mi, sum - 2);
    }
    if (mi < 1e7) cout << mi << endl;
    else cout << -1 << endl;
    return 0;
}