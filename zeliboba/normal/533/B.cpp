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
vi a;
vl ma[2];
//vl res;

void dfs(int v) {
    for (int i = 0; i < gr[v].size(); ++i) {
        int nv = gr[v][i];
        dfs(nv);
        ll t0 = max(ma[1][v] + ma[1][nv], ma[0][v] + ma[0][nv]);
        ll t1 = max(ma[0][v] + ma[1][nv], ma[1][v] + ma[0][nv]);
        ma[0][v] = t0;
        ma[1][v] = t1;
    }
    ma[1][v] = max(ma[1][v], a[v] + ma[0][v]);
}

int main() {
    int n;
    cin >> n;
    gr.resize(n);
    a.resize(n);
    ma[0].assign(n, 0);
    ma[1].assign(n, -1e18);
//    res.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        int p;
        scanf("%d%d", &p, &a[i]);
        --p;
        if (p >= 0) gr[p].push_back(i);
    }
    dfs(0);
//    cout << res[0] << endl;
    cout << max(ma[0][0], ma[1][0]) << endl;
    return 0;
}