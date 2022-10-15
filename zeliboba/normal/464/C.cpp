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
const int mod = 1000000007;

ll mpow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1)
            res = res * x % mod;
        n /= 2;
        x = x * x % mod;
    }
    return res;
}

int dw(int x, int y) {
    if (x < y) return x;
    return x-y;
}

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vi d(n+1);
    vs t(n+1);
    d[0] = 0;
    t[0] = "0->" + s;
    for (int i = 0; i < n; ++i) {
        char x,y;
        cin >> t[i+1];
        d[i+1] = t[i+1][0] - '0';
//        cerr << d[i] << ' ' << t[i] << endl;
    }
    vl l(10, 1), r(10);
    for (int i = 0; i < r.size(); ++i) r[i] = i;
    for (int q = n; q >= 0; --q) {
        ll nl = 0, nr = 0;
        for (int i = (int)t[q].size() - 1; i >= 3; --i) {
            nr = (nr + r[t[q][i]-'0']*mpow(10, nl)) % mod;
            nl = dw(nl + l[t[q][i]-'0'], mod-1);
        }
//        nl[d[q]] %= mod-1;
        l[d[q]] = nl;
        r[d[q]] = nr;
//        cerr << q << ' ' << d[q] << ' ' << t[q] << ' ' << l[d[q]] << ' ' << r[d[q]] << endl;
    }
//    cerr << mpow(10, mod-1) << endl;
    cout << r[0] << endl;
    return 0;
}