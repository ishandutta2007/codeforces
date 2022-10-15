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

ll m;

ll nx(ll h, ll x, ll y) {
    return (x*h + y) % m;
}

int main() {
    vl a(2), h(2), x(2), y(2);
    cin >> m >> h[0] >> a[0] >> x[0] >> y[0] >> h[1] >> a[1] >> x[1] >> y[1];
    int T = 2e6;
    for (int t = 0; t < T; ++t) {
        if (h[0] == a[0] && h[1] == a[1]) {
            cout << t << endl;
            return 0;
        }
        h[0] = nx(h[0], x[0], y[0]);
        h[1] = nx(h[1], x[1], y[1]);
    }
    vl h0 = h;
    vl p(2, -1), q(2, -1);
    for (int i = 0; i < m; ++i) {
        if (h[0] == a[0] && p[0] == -1) p[0] = i;
        if (h[1] == a[1] && p[1] == -1) p[1] = i;
        h[0] = nx(h[0], x[0], y[0]);
        h[1] = nx(h[1], x[1], y[1]);
        if (h[0] == h0[0] && q[0] == -1) q[0] = i + 1;
        if (h[1] == h0[1] && q[1] == -1) q[1] = i + 1;
    }
    if (min(p[0], p[1]) == -1) {
        cout << -1 << endl;
        return 0;
    }
    ll d = __gcd(q[0], q[1]);
    cerr << p[0] << ' ' << q[0] << ' ' << p[1] << ' ' << q[1] << endl;
    for (ll k = 0; k < 2*q[1]; ++k) {
        if ((p[0] + k * q[0]) % q[1] == p[1]) {
            cout << p[0] + k * q[0] + T << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    //p[0]+kq[0]=p[1]+tq[1]
    return 0;
}