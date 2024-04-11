#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

ll MAX = 1e9;

void out (vi v) {
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}

ll f (const vi & res) {
    vector<vll> dyn(res.size(), vll(res.size()));
    if (res[0] != 1)
        dyn[0][1] = 1;
    for (int i = 0; i + 1 < res.size(); ++i) {
        for (int j = 0; j < res.size(); ++j)
            dyn[i][j] = min(dyn[i][j], MAX);
        if (res[i + 1] != 1)
            dyn[i + 1][1] += dyn[i][0];
        for (int j = 1; j < res.size(); ++j) {
            if (res[i + 1] != 1 && j + 1 < res.size())
                dyn[i + 1][j + 1] += dyn[i][j];
            if (res[i + 1] != 0)
                dyn[i + 1][j - 1] += dyn[i][j];
        }
    }
    return dyn.back()[0]; 
}

int main() {
    MAX *= MAX + 1;
    ll n, m, k;
    cin >> n >> m >> k;
    vi p(n + m - 1, 1e8);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        int t;
        cin >> t;
        p[i + j] = min(t, p[i + j]);
    }
    vii ord(p.size());
    for (int i = 0; i < ord.size(); ++i)
        ord[i] = pii(p[i], i);
    sort(ord.begin(), ord.end());
    vi res(n + m - 1, -1);
    --k;
    for (int it = 0; it < ord.size(); ++it) {
        res[ord[it].second] = 0;
//        out(res);
        ll cnt = f(res);
//        cerr << cnt << endl;
        if (cnt == 0) {
            res[ord[it].second] = 1;
        } else {
            if (cnt <= k) {
                k -= cnt;
                res[ord[it].second] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (res[i + j])
                printf(")");
            else printf("(");
        }
        cout << endl;
    }
    return 0;
}