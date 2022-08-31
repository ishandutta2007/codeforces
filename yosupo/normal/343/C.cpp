#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>
#include <complex>
#include <cmath>

using namespace std;
typedef long long ll;

typedef complex<double> P;
int n, m;
vector<ll> h, p;

bool solve(ll md) {
    int u = 0;
    for (int i = 0; i < n; i++) {
        ll d = h[i]+md;
        if (p[u] < h[i]) {
            ll k = h[i]-p[u];
            if (md < k) return false;
            d = h[i]+max(md-k-k, (md-k)/2);
        }
        while (u < m && p[u] <= d) u++;
        if (u == m) return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        ll d;
        cin >> d;
        h.push_back(d);
    }
    for (int i = 0; i < m; i++) {
        ll d;
        cin >> d;
        p.push_back(d);
    }
    ll l = -1, r = 1LL<<55;
    while (r - l > 1) {
        ll md = (r+l)/2;
        if (solve(md)) {
            r = md;
        } else {
            l = md;
        }
    }
    cout << r << endl;
    return 0;
}