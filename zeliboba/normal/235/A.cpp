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

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ll n;
    cin >> n;
    ll res = max(n, n * (n - 1));
    for (int mask = 0; mask < (1 << 17); ++mask) {
        int cnt = 0;
        ll lcm = 1;
        for (int i = 0; i < 17; ++i) if (mask & (1 << i)) {
            ++cnt;
            if (n <= i)
                cnt = 4;
            if (cnt > 3)
                break;
            ll d = gcd(lcm, n - i);
            lcm = lcm / d * (n - i);
        }
        if (cnt <= 3)
            res = max(res, lcm);
    }
    cout << res << endl;
    return 0;
}