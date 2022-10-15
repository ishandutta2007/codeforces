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
vvi c(2);
vi sz;

void dfs(int v) {
    if (gr[v].empty()) {
        c[0][v] = c[1][v] = 1;
        sz[v] = 1;
    }
    for (int i = 0; i < gr[v].size(); ++i) {
        dfs(gr[v][i]);
        sz[v] += sz[gr[v][i]];
        c[0][v] = min(c[0][v], c[1][gr[v][i]]);
        c[1][v] += c[0][gr[v][i]];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    gr.resize(n);
    c[0].assign(n, 1e9);
    c[1].assign(n, 0);
    sz.assign(n, 0);
    for (int i = 0; i < n-1; ++i) {
        int a,b;
        scanf("%d%d", &a, &b);
        --a; --b;
        gr[a].push_back(b);
    }
    dfs(0);
    int m = sz[0];
    cout << m - c[0][0] + 1 << ' ' << c[1][0] << endl;
    return 0;
}