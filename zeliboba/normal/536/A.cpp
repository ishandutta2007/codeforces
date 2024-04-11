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

ll c2(ll x) {
    return x*(x-1)/2;
}

int main() {
    ll a, b, n;
    cin >> a >> b >> n;
    for (int i = 0; i < n; ++i) {
        ll l, t, m;
        cin >> l >> t >> m;
        if (a + b*(l-1) > t) {
            cout << -1 << endl;
            continue;
        }
        ll x = l, y = 4000000;
        while (y - x > 1) {
            ll z = (x + y) / 2;
            if (a + b*(z-1) > t || a*(z-l+1)+b*(c2(z) - c2(l-1)) > t*m) {
                y = z;
            } else {
                x = z;
            }
        }
        cout << x << endl;
    }
    return 0;
}