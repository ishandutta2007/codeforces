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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
const int mod = 1000000007;

vi c;
vvi gr;
vvl d(2);
vi ind;

void dfs(int v, int pr) {
    for (int i = 0; i < gr[v].size(); ++i) if (gr[v][i] != pr) {
        dfs(gr[v][i], v);
    }
    if (c[v]) {
        d[1][v] = 1;
        d[0][v] = 0;
        for (int i = 0; i < gr[v].size(); ++i) if (gr[v][i] != pr) {
            d[1][v] = d[1][v] * (d[0][gr[v][i]] + d[1][gr[v][i]]) % mod;
        }
    } else {
        d[0][v] = 1;
        vl l(1, 1), r(1, 1);
        for (int i = 0; i < gr[v].size(); ++i) if (gr[v][i] != pr) {
            d[0][v] = d[0][v] * (d[0][gr[v][i]] + d[1][gr[v][i]]) % mod;
            ind[gr[v][i]] = l.size() - 1;
            l.push_back(l.back() * (d[0][gr[v][i]] + d[1][gr[v][i]]) % mod);
        }
        for (int i = (int)gr[v].size()-1; i >= 0; --i) if (gr[v][i] != pr) {
            r.push_back(r.back() * (d[0][gr[v][i]] + d[1][gr[v][i]]) % mod);
        }
        d[1][v] = 0;
        for (int i = 0; i < gr[v].size(); ++i) if (gr[v][i] != pr) {
            int pos = ind[gr[v][i]];
            d[1][v] = (d[1][v] + d[1][gr[v][i]] * l[pos] % mod * r[r.size() - 2 - pos]) % mod;
        }
    }
}

int main() {
    int n;
    cin >> n;
    c.resize(n);
    gr.resize(n);
    ind.assign(n, 0);
    d[0].resize(n);
    d[1].resize(n);
    for (int i = 1; i <= n-1; ++i) {
        int a;
        scanf("%d", &a);
        gr[i].push_back(a);
        gr[a].push_back(i);
    }
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
    dfs(0, -1);
    cout << d[1][0] % mod << endl;
    return 0;
}