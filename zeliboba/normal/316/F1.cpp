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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int h, w;
int v[1615][1615];
int was[1615][1615];
int was1[1615][1615];
vii cur;

void dfs(int i, int j) {
    if (!was[i][j] && v[i][j]) {
        was[i][j] = 1;
        cur.push_back(pii(i, j));
        for (int i1 = -1; i1 < 2; ++i1) for (int j1 = -1; j1 < 2; ++j1) if (i1 == 0 || j1 == 0)
            dfs(i+i1, j+j1);
    }
}

void dfs1(int i, int j) {
    if (!was1[i][j] && v[i][j]) {
        was1[i][j] = 1;
        for (int i1 = -1; i1 < 2; ++i1) for (int j1 = -1; j1 < 2; ++j1) if (i1 == 0 || j1 == 0) //???
            dfs1(i+i1, j+j1);
    }
}

int f(int i, int j) {
    cur.resize(0);
    dfs(i, j);
//    double cx = 0, cy = 0;
//    int cntc = 0;
    for (int it = 0; it < cur.size(); ++it) {
        int x = cur[it].first, y = cur[it].second;
        bool in = 1;
        for (int i = -2; i <= 2; ++i) for (int j = -2; j <= 2; ++j) if (!v[x+i][y+j])
            in = 0;
//        cerr << x << ' ' << y << ' ' << in << endl;
        if (in) {
            for (int i = -3; i <= 3; ++i) for (int j = -3; j <= 3; ++j) 
                was1[x+i][y+j] = 1;
        }
    }
    int res = 0;
    for (int i = 0; i < cur.size(); ++i) if (!was1[cur[i].first][cur[i].second]) {
//        cerr << cur[i].first << ' ' << cur[i].second << endl;
        ++res;
        dfs1(cur[i].first, cur[i].second);
    }
    for (int i = 0; i < cur.size(); ++i) 
        v[cur[i].first][cur[i].second] = 0;
    return res;
}

int main() {
    memset(v, 0, sizeof(v));
    memset(was, 0, sizeof(was));
    memset(was1, 0, sizeof(was1));
    cin >> h >> w;
    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j)
        scanf("%d", &v[i+5][j+5]);
    h += 20; w += 20;
    vi res;
    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) if (v[i][j]) {
        res.push_back(f(i, j));
    }
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << ' ';
    cout << endl;
    return 0;
}