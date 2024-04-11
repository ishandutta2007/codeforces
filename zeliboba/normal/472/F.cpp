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

int gauss(vi & v, vii & ans, vi & mb) {
    int cur = 0;
    for (int b = 30; b >= 0; --b) if (cur < v.size()) {
        for (int i = cur; i < v.size(); ++i) if (v[i] & (1 << b)) {
            if (i != cur) {
                swap(v[i], v[cur]);
                ans.push_back(pii(i, cur));
                ans.push_back(pii(cur, i));
                ans.push_back(pii(i, cur));
            }
            break;
        }
        if (v[cur] & (1 << b)) {
            for (int i = 0; i < v.size(); ++i) if (i != cur && (v[i] & (1 << b))) {
                v[i] ^= v[cur];
                ans.push_back(pii(i, cur));
            }
            mb.push_back(1<<b);
            ++cur;
        }
    }
    return cur;
}

int main() {
    int n;
    cin >> n;
    vi x(n), y(n);
    for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &y[i]);
//    vi xr = x, yr = y;
    vii ans;
    ans.reserve(1000000);
    vi mb;
    int b = gauss(x, ans, mb);
//    cerr << "gx: " << ans.size() << endl;
    vi y0 = y;
    for (int i = 0; i < y.size(); ++i) {
        for (int j = 0; j < b; ++j) if ((y[i] & x[j]) >= mb[j]) {
            y[i] ^= x[j];
            if (i >= b) ans.push_back(pii(i, j));
        }
        if (y[i]) {
            printf("-1\n");
            return 0;
        }
    }
    y0.resize(b);
    vii ansy;
    vi mby;
    gauss(y0, ansy, mby);
//    cerr << "gy: " << ansy.size() << endl;
    y = y0;
    for (int i = 0; i < y.size(); ++i) {
        if ((x[i] & y[i]) >= mb[i]) {
            y[i] ^= x[i];
        } else {
            ans.push_back(pii(i, i));
        }
        for (int j = i+1; j < b; ++j) if ((y[i] & x[j]) >= mb[j]) {
            y[i] ^= x[j];
            ans.push_back(pii(i, j));
        }
//        assert(y[i] == 0);
    }
    for (int i = (int)ansy.size()-1; i >= 0; --i) {
        ans.push_back(pii(ansy[i].first, ansy[i].second));
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
/*    for (int i = 0; i < ans.size(); ++i) {
        xr[ans[i].first] ^= xr[ans[i].second];
//        cerr << xr[0] << ' ' << xr[1] << endl;
    }
    for (int i = 0; i < n; ++i) {
        if (xr[i] != yr[i]) cerr << i << ' ' << xr[i] << ' ' << yr[i] << endl;
        assert(xr[i] == yr[i]);
    }*/
    return 0;
}