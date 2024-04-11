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

vi inv(const vi & res, const vii &a) {
    vi tout(res.size());
    for (int i = 0; i < res.size(); ++i)
        tout[a[i].second] = res[i];
    return tout;
}

void out (const vi & v) {
    for (int i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
}

int main() {
    int n, h;
    cin >> n >> h;
    vii a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    vi res0(n, 1);
    int ans0 = a.back().first + a[n - 2].first - a[0].first - a[1].first;
    vi res1(n, 1);
    res1[0] = 2;
    int ma = a.back().first + a[0].first + h;
    if (n > 2)
        ma = max(ma, a.back().first + a[n - 2].first);
    int mi = a[0].first + a[1].first + h;
    if (n > 2)
        mi = min(mi, a[2].first + a[1].first);
    int ans1 = ma - mi;
    if (ans1 < ans0) {
        printf("%d\n", ans1);
        out(inv(res1, a));
    } else {
        printf("%d\n", ans0);
        out(inv(res0, a));
    }
    return 0;
}