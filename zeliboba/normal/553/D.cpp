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
typedef pair<double, int> pdi;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vi bad(n);
    vvi g(n);
    for (int i = 0; i < k; ++i) {
        int t;
        scanf("%d", &t);
        bad[t-1] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int a,b;
        scanf("%d%d", &a, &b);
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vd d(n);
    for (int i = 0; i < n; ++i) {
        int c = 0;
        for (int j = 0; j < g[i].size(); ++j)
            c += 1 - bad[g[i][j]];
        d[i] = c / (double)g[i].size();
    }
    set<pdi> q;
    for (int i = 0; i < n; ++i) if (!bad[i]) {
        q.insert(pdi(d[i], i));
    }
    int T = 2;
    double ma = -1;
    int best = 0;
    while (!q.empty()) {
        int v = q.begin()->second;
//        cerr << v + 1 << endl;
        if (d[v] > ma) {
            ma = d[v];
            best = T;
//            cerr << ma << ' ' << best << endl;
        }
        q.erase(q.begin());
        bad[v] = T; ++T;
        for (int i = 0; i < g[v].size(); ++i) {
            int nv = g[v][i];
            if (bad[nv]) continue;
            q.erase(pdi(d[nv], nv));
            d[nv] -= 1. / g[nv].size();
            q.insert(pdi(d[nv], nv));
        }
    }
    vi res;
    for (int i = 0; i < n; ++i) if (bad[i] >= best) {
//        cerr << i + 1 << ' ' << bad[i] << endl;
        res.push_back(i + 1);
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) printf("%d ", res[i]);
    return 0;
}