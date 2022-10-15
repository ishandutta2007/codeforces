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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
    vi y(3), x(3), c(3);
    for (int i = 0; i < 3; ++i) cin >> y[i];
    for (int i = 0; i < 3; ++i) cin >> x[i];
    for (int i = 0; i < 3; ++i) cin >> c[i];
    ll add = c[1] * max(0, x[2] + 1 - y[1]);
    y[1] = max(y[1], x[2] + 1);
    ll res0 = 1e9;
    for (int a = 0; a <= 100; ++a) for (int b = 0; b <= 100; ++b) {
        ll res = a*c[1] + b*c[2];
        vi y1 = y, x1 = x;
        y1[1] += a; y1[2] += b;
        while (x1[0] > 0) {
            x1[0] -= max(0, y1[1] - x1[2]);
            y1[0] -= max(0, x1[1] - y1[2]);
        }
        res += c[0] * max(0, 1-y1[0]);
        res0 = min(res0, res);
    }
    cout << add + res0 << endl;
    return 0;
}