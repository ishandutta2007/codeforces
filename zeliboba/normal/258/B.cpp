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
const int mod = 1000000007;

vl v(12);
ll T = 0;
int cur = 0;
vi t(12);

ll mpow (ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1)
            res = res * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return res;
}

ll inv (ll x) {
    return mpow(x, mod - 2);
}

ll cc (int m, ll M) {
    ll res = 1;
    for (int i = 0; i < m; ++i)
        res = (M - i) % mod * res % mod;// * inv(i + 1) % mod;
    return res;
}

void rec(int i, int ma) {
    if (i < 6) {
        for (int j = 0; j + cur < ma; ++j) {
            cur += j;
            t[j]++;
            rec(i + 1, ma);
            t[j]--;
            cur -= j;
        }
    } else {
        ll mul = 1;
        for (int j = 0; j < v.size(); ++j)
            mul = mul * cc(t[j], v[j]) % mod;
        T = (T + mul) % mod;
    }
}

void out(vi vv) {
    for (int i = 0; i < vv.size(); ++i)
        cerr << vv[i] << " ";
    cerr << endl;
}

int main() {
    int c[20][20];
    memset(c, 0, sizeof(c));
    for (int i = 0; i < 20; ++i)
        c[0][i] = 1;
    for (int i = 1; i < 20; ++i) for (int j = 1; j <= i; ++j)
        c[j][i] = c[j][i - 1] + c[j - 1][i - 1];
    int n;
    cin >> n;
    int n1 = n;
    vi d;
    while (n1) {
        d.push_back(n1 % 10);
        n1 /= 10;
    }
    int cnt = 0;
    for (int i = (int)d.size() - 1; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) for (int dig = 0; dig < d[i]; ++dig) {
            int cnt1 = cnt;
            if (dig == 4 || dig == 7)
                ++cnt1;
            v[j + cnt1] += c[j][i] * (1 << j) * (1 << (3 * i - 3 * j));
        }
        if (d[i] == 4 || d[i] == 7)
            ++cnt;
    }
    v[0]--;
    v[cnt]++;
//    out (v);
    ll res = 0;
    for (int i = 1; i < v.size(); ++i) {
        T = 0;
        rec(0, i);
        res += T * v[i];
    }
    cout << (res % mod + mod) % mod << endl;
    return 0;
}