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
typedef pair<ll, int> pli;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    int n, q;
    cin >> n >> q;
    vi x(n), y(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &y[i]);
    }
    for (int test = 0; test < q; ++test) {
        ll a,b;
        cin >> a >> b;
        vl res(n + 2, -1e18);
        res[n + 1] = 0;
        pli ma1(0, n+1), ma2(res[0], 0);
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ll same = res[y[i]] + a * x[i];
            ll dif = 0;
            if (ma1.second != y[i]) {
                dif = ma1.first + b * x[i];
            } else dif = ma2.first + b * x[i];
            ll ma = max(same, dif);
            ans = max(ans, ma);
            if (ma > res[y[i]]) {
                res[y[i]] = ma;
                if (ma > ma1.first) {
                    if (ma1.second == y[i])
                        ma1.first = ma;
                    else {
                        ma2 = ma1;
                        ma1 = pli(ma, y[i]);
                    }
                } else if (ma > ma2.first) {
                    ma2 = pli(ma, y[i]);
                }
            }
//            assert(ma1.second != ma2.second);
//            assert(ma1.first >= ma2.first);
        }
        cout << ans << endl;
    }
/*    for (int i = 0; i < n; ++i) {
        if (x[i] >= 0) {
            v[0][y[i]].push_back(x[i]);
            s[0][y[i]] += x[i];
        }
        if (x[i] <= 0) {
            v[1][y[i]].push_back(x[i]);
            s[1][y[i]] += x[i];
        }
    }
    for (int i = 0; i < v[0].size(); ++i) {
        sort(v[0][i].begin(), v[0][i].end());
        sort(v[1][i].begin(), v[1][i].end());
    }
    for (int test = 0; test < q; ++test) {
        ll a,b;
        cin >> a >> b;
        ll res = 0;
        for (int i = 0; i < v[0].size(); ++i) if (v[0][i].size() + v[1][i].size() > 0) {
            ll ma = 0;
            int t;
            if (a > 0) {
                ma += a * s[0][i];
                t = 0;
            } else {
                ma += a * s[1][i];
                t = 1;
            }
            ll ma1 = 0;
            if (!v[t][i].empty()) {
                ma1 = ma + max((b-a)*v[t][i][0], (b-a)*v[t][i].back());
            }
            ll ma2 = 0;
            if (!v[1-t][i].empty()) {
                ma2 = ma + max(b * v[1-t][i][0], b * v[1-t][i].back());
            }
            cerr << i << ' ' << ma1 << ' ' << ma2 << endl; 
            ma = max(ma1, ma2);
            res += max(0LL, ma);
        }
        cout << res << endl;
    }*/
    return 0;
}