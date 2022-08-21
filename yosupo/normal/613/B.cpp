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
using P = pair<ll, int>;
const int MN = 100100;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ll A, cf, cm, m;
    cin >> n >> A >> cf >> cm >> m;
    static P a[MN];
    static ll as[MN];
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a[i] = P(x, i);
    }
    sort(a, a+n);
    as[0] = 0;
    for (int i = 0; i < n; i++) {
        as[i+1] = as[i] + a[i].first;
    }
    ll ma = -1;
    ll ml;
    int mj;
    ll sm = 0;
    for (int j = n; j >= 0; j--) {
        if (j < n) {
            sm += A - a[j].first;
        }
        if (m < sm) break;
        ll l = 0, r = A+1;
        while (r-l > 1) {
            ll md = (l+r)/2;
            int u = lower_bound(a, a+j, P(md, -1)) - a;
            if (md * u - as[u] <= m - sm) {
                l = md;
            } else {
                r = md;
            }
        }
        ll res = (n-j)*cf + l*cm;
        if (ma < res) {
            ma = res;
            ml = l;
            mj = j;
        }
    }
    cout << ma << endl;
    static ll ans[MN];
    for (int i = 0; i < n; i++) {
        if (mj <= i) {
            ans[a[i].second] = A;
        } else if (a[i].first <= ml) {
            ans[a[i].second] = ml;
        } else {
            ans[a[i].second] = a[i].first;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}