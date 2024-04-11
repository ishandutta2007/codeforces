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

int main() {
    int n, m;
    cin >> n >> m;
    vi v(n), q(m);
    for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
    for (int i = 0; i < m; ++i) scanf("%d", &q[i]);
    sort(v.begin(), v.end());
    vi next(v.size());
    for (int i = 0; i < v.size(); ++i) {
        next[i] = i;
        if (i && v[i-1] + 1 == v[i]) {
            next[i] = next[i-1];
        }
    }
    sort(q.begin(), q.end());
    vvi d(2, vi(n));
    for (int i = 0; i < n; ++i) {
        int it = upper_bound(q.begin(), q.end(), v[i]) - q.begin();
        for (int j = 0; j < it; ++j) {
            int ind = i - (v[i] - q[j]);
            if (ind >= 0) ind = next[ind];
            if (ind > 0) d[0][i] = max(d[0][i], d[1][ind-1] + it-j);
            if (ind == 0) d[0][i] = max(d[0][i], it-j);
        }
        if (i) {
            d[1][i] = max(d[1][i], d[1][i-1]);
            if (next[i] > 0) d[0][i] = max(d[0][i], d[1][next[i]-1]);
        }
        d[1][i] = max(d[1][i], d[0][i]);
        int cnt = 0;
        for (int j = it; j < m; ++j) {
            ++cnt;
            int ind = i + q[j]-v[i];
            if (ind < n) d[1][ind] = max(d[1][ind], d[0][i]+cnt);
        }
//        cerr << d[0][i] << ' ' << d[1][i] << endl;
    }
    cout << d[1][n-1] << endl;
    return 0;
}