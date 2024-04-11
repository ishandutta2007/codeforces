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

vvi gr;
int n, m;

vi bfs(int s) {
    vi d(n, 1e9);
    d[s] = 0;
    vi q(1, s);
    for (int it = 0; it < q.size(); ++it) {
        int v = q[it];
        for (int i = 0; i < gr[v].size(); ++i) {
            int nd = d[v] + 1;
            int nv = gr[v][i];
//            cerr << v << ' ' << nv << ' ' << nd << ' ' << d[nv] << endl;
            if (nd < d[nv]) {
                d[nv] = nd;
                q.push_back(nv);
            }
        }
    }
//    cerr << s << ' ' << n << ' ' << q.size() << endl;
    assert(q.size() == n);
    return d;
}

int main() {
    cin >> n >> m;
    gr.resize(n);
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        --a; --b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    vi s(2),t(2),l(2);
    vvi d(n);
    for (int i = 0; i < n; ++i) d[i] = bfs(i);
    for (int i = 0; i < 2; ++i) {
        cin >> s[i] >> t[i] >> l[i];
        --s[i]; --t[i];
    }
    if (d[s[0]][t[0]] > l[0] || d[s[1]][t[1]] > l[1]) {
        cout << -1 << endl;
        return 0;
    }
    int res = d[s[0]][t[0]] + d[s[1]][t[1]];
    for (int x = 0; x < n; ++x) for (int y = 0; y < n; ++y) {
        vi p(2);
        for (int i = 0; i < 2; ++i) {
            p[i] = d[s[i]][x] + d[x][y] + d[y][t[i]];
        }
        if (p[0] <= l[0] && p[1] <= l[1]) {
            res = min(res, p[0] + p[1] - d[x][y]);
        }
    }
    for (int x = 0; x < n; ++x) for (int y = 0; y < n; ++y) {
        vi p(2);
        p[0] = d[s[0]][x] + d[x][y] + d[y][t[0]];
        p[1] = d[s[1]][y] + d[x][y] + d[x][t[1]];
        if (p[0] <= l[0] && p[1] <= l[1]) {
            res = min(res, p[0] + p[1] - d[x][y]);
        }
    }
    cout << m-res << endl;
    return 0;
}