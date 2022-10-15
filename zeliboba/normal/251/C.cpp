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

const int mod = 360360;
const int lim = 2e6;

ll v[2 * lim];

int main() {
    ll a, b, k;
    cin >> a >> b >> k;
    vl was(mod, -1);
    vl pos(mod, -1);
    ll t = 0;
    while (a - b > lim && was[a % mod] == -1) {
        was[a % mod] = t;
        pos[a % mod] = a;
        ++t;
        ll ma = 1;
        for (int i = 3; i <= k; ++i)
            ma = max(ma, a % i);
        a -= ma;
    }
    if (a - b > lim) {
        ll per = t - was[a % mod];
        ll step = pos[a % mod] - a;
        ll go = (a - b - lim) / step;
        if (go > 0) {
            a -= step * go;
            t += go * per; 
        }
//        cerr << per << " " << a << " " << step << " " << b << endl;
    }
    while (a - b > lim) {
        ++t;
        ll ma = 1;
        for (int i = 3; i <= k; ++i)
            ma = max(ma, a % i);
        a -= ma;
    }
//    cerr << b << " " << a << endl;
    for (int i = a - b - 1; i >= 0; --i) {
        v[i] = 1e9;
    }
    v[a - b] = 0;
    for (int i = a - b; i > 0; --i) {
        v[i - 1] = min(v[i - 1], v[i] + 1);
        for (int m = 3; m <= k; ++m) {
            int r = (b + i) % m;
            if (r && r <= i) {
                v[i - r] = min(v[i - r], v[i] + 1);
            }
        }
    }
    cout << v[0] + t << endl;
    return 0;
}