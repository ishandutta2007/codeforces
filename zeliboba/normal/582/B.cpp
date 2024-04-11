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

vi f(const vi & a) {
    vi d(301);
    for (int i = 0; i < a.size(); ++i) {
        vi nd = d;
        for (int j = 0; j <= a[i]; ++j) {
            nd[a[i]] = max(nd[a[i]], d[j] + 1);
        }
        d.swap(nd);
    }
    return d;
}

vi g(const vi & a) {
    vi d(301);
    for (int i = a.size() - 1; i >= 0; --i) {
        vi nd = d;
        for (int j = a[i]; j < d.size(); ++j) {
            nd[a[i]] = max(nd[a[i]], d[j] + 1);
        }
        d.swap(nd);
    }
    return d;
}

int main() {
    int n, t;
    cin >> n >> t;
    vi a(n);
    vi c(301);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++c[a[i]];
    }
    int X = 301;
    int it = min(t, X);
    for (int i = 0; i < it - 1; ++i) for (int j = 0; j < n; ++j) a.push_back(a[j]);
    vi b = f(a);
    int it1 = min(X, t - it);
    a.resize(it1*n);
    vi d = g(a);
    ll ma = 0;
    int cur = 0;
    for (int i = 0; i < c.size(); ++i) {
        cur = max(cur, b[i]);
        int m1 = 0;
        for (int j = i; j < d.size(); ++j) m1 = max(m1, d[j]);
        ma = max(ma, m1 + cur + (t - it - it1) * (ll)c[i]);
    }
/*    vi d = g(a);
    if (t == 1) {
        for (int i = 0; i < b.size(); ++i) ma = max(ma, (ll)b[i]);
    } else for (int i = 0; i <= 300; ++i) {
        int m1 = 0;
        for (int j = 0; j <= i; ++j) m1 = max(m1, b[j]);
        int m2 = 0;
        for (int j = i; j < d.size(); ++j) m2 = max(m2, d[j]);
        ma = max(ma, m1+m2+(t - 2) * (ll)c[i]);
    }*/
    cout << ma << endl;
    return 0;
}