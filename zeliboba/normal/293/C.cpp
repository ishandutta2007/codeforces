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

int main() {
    ll n;
    cin >> n;
    if (n % 3) {
        cout << 0 << endl;
        return 0;
    }
    n/=3;
    vl d;
    for (ll i = 2; i * i <= n; ++i) if (n % i == 0)
        d.push_back(i);
    ll res = 0;
    for (int it = 0; it < d.size(); ++it) {
        ll ab = d[it];
        ll n1 = n / ab;
        for (int it1 = it; it1 < d.size() && n1 / d[it1] >= d[it1]; ++it1) if (n1 % d[it1] == 0) {
            ll ac = d[it1];
            ll bc = n1 / ac;
            if ((ab+ac+bc) % 2 == 1 || bc >= ab+ac)
                continue;
//            cerr << ab << ' ' << ac << ' ' << bc << endl;
            if (ab == ac && ac == bc) {
                ++res;
            } else if (ab == ac || ac == bc) {
                res += 3;
            } else res += 6;
        }
    }
    cout << res << endl;
    return 0;
}