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

int dw(int x, int y) {
    if (x >= y) return x - y;
    return x;
}

int main() {
    int n, m, b, mod;
    cin >> n >> m >> b >> mod;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vvi d(b + 1, vi(n + 1, 0));
    vvi s(b + 1, vi(n + 1, 0));
    d[0][0] = 1;
    for (int l = 0; l < m; ++l) {
        vvi nd(d.size(), vi(d[0].size(), 0));
        for (int j = 0; j <= b; ++j) {
            s[j][0] = d[j][0];
            for (int i = 1; i < s[j].size(); ++i) {
                s[j][i] = dw(s[j][i-1] + d[j][i], mod);
//                if (s[j][i]) cerr << l << ' ' << j << ' ' << i << ' ' << s[j][i] << ' ' << d[j][i] << endl;
            }
        }
        for (int i = 1; i <= n; ++i) for (int j = a[i-1]; j <= b; ++j) {
            nd[j][i] = s[j-a[i-1]][i];
//            if (nd[j][i]) cerr << l << ' ' << j << ' ' << i << ' ' << nd[j][i] << endl;
        }
        d.swap(nd);
    }
    ll res = 0;
    for (int i = 1; i <= n; ++i) for (int j = 0; j <= b; ++j) res += d[j][i];
    cout << res % mod << endl;
    return 0;
}