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
typedef vector<string> vs;

vi pr, r;
vvi gr, grd;

int getp(int v) {
    if (v == pr[v]) return v;
    return pr[v] = getp(pr[v]);
}

void join(int va, int vb) {
    int a = getp(va), b = getp(vb);
    if (r[a] < r[b]) {
        pr[a] = b;
    } else {
        pr[b] = a;
        if (r[a] == r[b])
            ++r[b];
    }
}

int n,m,k,w;
void dfs(int v, int v0, int d) {
    if (d == n*m) {
        cout << v+1 << ' ' << 0 << endl;
    } else {
        cout << v+1 << ' ' << v0+1 << endl;
    }
    for (int i = 0; i < gr[v].size(); ++i) if (v0 != gr[v][i]) {
        dfs(gr[v][i], v, grd[v][i]);
    }
}

int main() {
    cin >> n >> m >> k >> w;
//    if (k == 1) {
//        cout << n*m << endl;
//        return 0;
//    }
    vector<vs> v(k);
    for (int i = 0; i < k; ++i) {
        v[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }
    vvi d(k*(k-1) / 2, vi(3));
    int it = 0;
    for (int i = 0; i < k; ++i) for (int j = i + 1; j < k; ++j) {
        int dist = 0;
        for (int a = 0; a < n; ++a) for (int b = 0; b < m; ++b) {
            dist += (v[i][a][b] != v[j][a][b]);
        }
        dist *= w;
        dist = min(dist, n*m);
        d[it][0] = dist;
        d[it][1] = i;
        d[it][2] = j;
        ++it;
    }
    sort(d.begin(), d.end());
    pr.resize(k);
    r.assign(k, 0);
    gr.resize(k);
    grd.resize(k);
    for (int i = 0; i < pr.size(); ++i) pr[i] = i;
    int res = n*m;
    for (int i = 0; i < d.size(); ++i) {
        int a = d[i][1], b = d[i][2];
        if (getp(b) != getp(a)) {
            res += d[i][0];
            join(a, b);
            gr[a].push_back(b);
            gr[b].push_back(a);
            grd[a].push_back(d[i][0]);
            grd[b].push_back(d[i][0]);
        }
    }
    cout << res << endl;
    dfs(0, -1, n*m);
    return 0;
}