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
const int mod = 1000000007;

vi p, r;

int getp(int v) {
    if (p[v] == v) return v;
    return p[v] = getp(p[v]);
}

void join(int a, int b) {
    a = getp(a);
    b = getp(b);
    if (a == b) return;
    if (r[a] > r[b]) swap(a, b);
    p[a] = b;
    if (r[a] == r[b]) ++r[b];
}

vvi gr;
vi was;
bool fail = 0;

int dfs(int v, int c) {
    if (was[v]) {
        if (was[v] != c) fail = 1;
        return 0;
    }
    was[v] = c;
    int sz = 1;
    for (int i = 0; i < gr[v].size(); ++i) {
        sz += dfs(gr[v][i], 3-c);
    }
    return sz;
}

int main() {
    int n, m;
    cin >> n >> m;
    r.assign(n, 0);
    p.assign(n, 0);
    for (int i = 0; i < n; ++i) p[i] = i;
    vii bad;
    for (int i = 0; i < m; ++i) {
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);
        --a; --b;
        if (c == 1) join(a, b);
        else bad.push_back(pii(a, b));
    }
    gr.resize(n);
    was.assign(n, 0);
//    int cnt = 0;
//    for (int i = 0; i < n; ++i) if (getp(i) == i) ++cnt;
    for (int i = 0; i < bad.size(); ++i) {
        int a = bad[i].first, b = bad[i].second;
        a = getp(a); b = getp(b);
        if (getp(a) == getp(b)) {
//            cerr << bad[i].first << ' ' << bad[i].second << endl;
            cout << 0 << endl;
            return 0;
        }
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    ll res = 1;
    int cnt = 0;
    for (int i = 0; i < n; ++i) if (getp(i) == i && !was[i]) {
        ++cnt;
        int sz = dfs(i, 1);
//        if (sz > 1) res = res * 2 % mod;
        if (fail) {
            cout << 0 << endl;
            return 0;
        }
    }
    for (int i = 0; i < cnt - 1; ++i) res = res * 2 % mod;
    cout << res << endl;
    /*if (cnt == 1) {
        cout << 1 << endl;
        return 0;
    }*/ 
    return 0;
}