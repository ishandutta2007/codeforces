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

int down(int x) {
    if (x >= mod)
        return x-mod;
    return x;
}

int main() {
    ll n,q,t;
    cin >> n >> q >> t;
    vi a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vi v(n,-1), was(n);
    for (int i = 0; i < q; ++i) {
        int x,b;
        cin >> x >> b;
        --x;--b;
        v[x] = b;
        was[b] = 1;
    }
    vi p(t+1);
    p[0] = 1;
    for (int i = 0; i < n; ++i) if (!was[i]) {
        ll sum = 0;
        ll cur = i;
        while (cur != -1) {
            if (cur < 0 || cur >= n)
                return 0;
//            cerr << i << ' ' << cur << endl;
            sum += a[cur];
            a[cur] = -1;
            cur = v[cur];
//            cerr << sum << ' ' << cur << endl;
            if (cur != -1)
                t -= sum;
            for (int i = 0; i+sum < p.size(); ++i)
                p[i+sum] = down(p[i+sum]+p[i]);
        }
    }
    for (int i = 0; i < n; ++i) if (a[i] != -1) {
        cout << 0 << endl;
        return 0;
    }
//    cerr << t << endl;
    if (t < 0) {
        cout << 0 << endl;
        return 0;
    } else cout << (p[t]%mod+mod)%mod << endl;
    return 0;
}