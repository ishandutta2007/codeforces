#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;

using P = pair<ll, ll>;

P solve() {
    ll n;
    cin >> n;
    if (n == 0) {
        return P(0, 0);
    }
    ll l = 1, r = 1e9+100;
    while (r-l > 1) {
        ll md = (l+r)/2;
        if (1LL+3*(md)*(md-1) <= n) {
            l = md;
        } else {
            r = md;
        }
    }
    n -= 1LL+3*(l)*(l-1);
    if (n == 0) {
        return P(2*l-1, 2);
    }
    P np = P(2*l, 0);
    n++;
    P di[6] = {
        P(-1, 2),
        P(-2, 0),
        P(-1, -2),
        P(1, -2),
        P(2, 0),
        P(1, 2),
    };
    for (int i = 0; i < 6; i++) {
        ll us = min(l, n);
        np = P(np.first + di[i].first*us, np.second + di[i].second*us);
        n -= us;
    }
    return np;
}
int main() {
    auto p = solve();
    cout << p.first << " " << p.second << endl;
    return 0;
}