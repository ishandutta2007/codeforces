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

int e[405][405];

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u,v;
        scanf("%d%d",&u,&v);
        --u;--v;
        e[u][v] = e[v][u] = 1;
    }
    if (e[0][n-1] == 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) e[i][j] = 1 - e[i][j];
        }
    }
    vi d(n, 1e9);
    d[0] = 0;
    vi q(1, 0);
    for (int it = 0; it < q.size(); ++it) {
        int v = q[it];
        for (int j = 0; j < n; ++j) if (e[v][j] && d[j] > d[v] + 1) {
            d[j] = d[v] + 1;
            q.push_back(j);
        }
    }
    if (d[n-1] < 1e7) {
        cout << d[n-1] << endl;
    } else {
        cout << -1 << endl; 
    }
    return 0;
}