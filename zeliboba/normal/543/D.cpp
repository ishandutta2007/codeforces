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

vvi gr;
vl res;
vl d;

void dfs0(int v, int pr) {
    for (int i = 0; i < gr[v].size(); ++i) if (gr[v][i] != pr) {
        dfs0(gr[v][i], v);
        d[v] = d[v] * (1 + d[gr[v][i]]) % mod;
    }
} 

void dfs1(int v, ll du, int pr) {
    res[v] = du * d[v] % mod;
    vl l(gr[v].size(), 1);
    vl r(gr[v].size(), 1);
    int x = gr[v].size();
    for (int i = 0; i + 1 < gr[v].size(); ++i) {
        l[i + 1] = l[i];
        r[x - i - 2] = r[x - i - 1];
        if (gr[v][i] != pr) {
            l[i + 1] = l[i + 1] * (1 + d[gr[v][i]]) % mod;
        }
        if (gr[v][x - i - 1] != pr) {
            r[x - i - 2] = r[x - i - 2] * (1 + d[gr[v][x - i - 1]]) % mod;
        }
    }
    for (int i = 0; i < gr[v].size(); ++i) if (gr[v][i] != pr) {
        ll dt = (1 + du * l[i] % mod * r[i]) % mod;
        dfs1(gr[v][i], dt, v);
    }
} 

int main() {
    int n;
    cin >> n;
    gr.resize(n);
    res.assign(n, 0);
    d.assign(n, 1);
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p; --p;
        gr[i].push_back(p);
        gr[p].push_back(i);
    }
    dfs0(0, -1);
    dfs1(0, 1, -1);
    for (int i = 0; i < n; ++i) {
        cout << res[i] << ' ';
    }
    return 0;
}