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

ll n,x,y,c;

ll f (ll a, ll b, ll m) {
//    cerr << a << " " << b << endl;
    if (a > b)
        swap(a, b);
    if (a >= m)
        return m * (m + 1) / 2;
    if (m <= b)
        return a * (a + 1) / 2 + a * (m - a);
    if (m >= a + b - 1)
        return a * b;
    return a * b - f(a, b, a + b - 1 - m);
}

ll check(ll m) {
    if (m == 0)
        return 0;
    if (m == 1)
        return 1;
    ll res = 1 + min(m - 1, x - 1) + min(m - 1, y - 1) + min(m - 1, n - x) + min(m - 1, n - y);
//    cerr << m << " " << res << endl;
    m -= 2;
//    cerr << x << " " << y << " " << n << endl;
//    cerr << f(x - 1, y - 1, m) << " " << f(x - 1, n - y, m) << " " << f(n - x, y - 1, m) << " " << f(n - x, n - y, m) << endl;
    return res + f(x - 1, y - 1, m) + f(x - 1, n - y, m) + f(n - x, y - 1, m) + f(n - x, n - y, m);
}

int main() {
    cin >> n >> x >> y >> c;
//    cerr << check(2) << endl;
//    cerr << check(3) << endl;
//    cerr << check(4) << endl;
    ll l = 0, r = 2 * n;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (check(m) >= c)
            r = m;
        else l = m;
    }
    cout << r - 1 << endl;
    return 0;
}