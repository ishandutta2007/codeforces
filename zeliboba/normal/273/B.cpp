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
int mod;
vii fac(200200, pii(0, 1));

ll mpow (ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n&1)
            res = res*x%mod;
        x=x*x%mod;
        n/=2;
    }
    return res;
}

ll f (const vi & v) {
    int t = v.size(), p = 0;
    for (int i = 1; i < v.size(); ++i)
        if (v[i] == v[i-1])
            ++p;
    pii res = fac[t];
    res.first -= p;
    return res.second * mpow(2, res.first) % mod;
}

int main() {
    int n;
    cin >> n;
    vii v(2*n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i].first);
        v[i].second = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i+n].first);
        v[i+n].second = i;
    }
    cin >> mod;
    for (int i = 1; i < fac.size(); ++i) {
        ll i1 = i;
        fac[i] = fac[i-1];
        while (i1 % 2 == 0) {
            i1 /= 2;
            fac[i].first++;
        }
        fac[i].second = fac[i].second * i1 % mod;
    }
    sort(v.begin(), v.end());
    ll res = 1;
    vi cur(1, v[0].second);
    for (int i = 1; i < v.size(); ++i) {
        if (v[i].first == v[i-1].first) {
            cur.push_back(v[i].second);
        } else {
            res = res * f(cur) % mod;
            cur.assign(1, v[i].second);
        }
    }
    cout << res * f(cur) % mod << endl;
    return 0;
}