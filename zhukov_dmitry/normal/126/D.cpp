// Zeliboba's solution

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    ll MAX = 1000000000;
    MAX *= MAX;
    int T;
    cin >> T;
    vector<ll> f(2);
    f[0] = 1; f[1] = 2;
    while (f.back() + f[f.size() - 2] <= MAX)
        f.push_back(f.back() + f[f.size() - 2]);
/*  vi stress(100000);
    stress[0] = 1;
    stress[1] = 1;
    for (int i = 2; i < stress.size(); ++i) {
        int it = 0;
        while (f[it + 1] <= i)
            ++it;
        stress[i] = stress[i - f[it]];

    }*/
    for (int test = 1; test <= T; ++test) {
        ll n;
//        scanf("%lld", &n);
        scanf("%I64d", &n);
        vi a;
        for (int it = f.size() - 1; it >= 0; --it) {
            if (n >= f[it]) {
                a.push_back(it);
                n -= f[it];
            }
        }
        vector<ll> dyn(a.size());
        vector<ll> dyn1(a.size());
        dyn.back() = 1;
        if (a.back() > 1) {
            dyn1.back() = a.back() / 2;
            dyn.back() += dyn1.back();
        }
        for (int i = (int)a.size() - 2; i >= 0; --i) {
            dyn[i] = dyn[i + 1];
            if (a[i] - a[i + 1] >= 2) {
                dyn1[i] = dyn[i + 1] * ((a[i] - a[i + 1] - 1) / 2);
                if (((a[i] - a[i + 1]) & 1) == 0)
                    dyn1[i] += dyn1[i + 1];
            }
            dyn[i] += dyn1[i];
        }
//        printf("%lld\n", dyn[0]);
      printf("%I64d\n", dyn[0]);
    }
    return 0;
}