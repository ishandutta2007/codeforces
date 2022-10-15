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
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<string> vs;
ll mod;

void out(vl v) {
    for (int i = 0; i < v.size(); ++i) cerr << v[i] << ' ';
    cerr << endl;
}
void out(vvl v) {
    for (int i = 0; i < v.size(); ++i) out(v[i]);
    cerr << endl;
}

vvi id(int n) {
    vvi v(2, vi(2));
    v[0][0] = v[1][1] = 1;
    return v;
}

vvi mul(const vvi & a, const vvi & b) {
    int n = a.size();
    vvi c(n, vi(n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        ll x = 0;
        for (int l = 0; l < n; ++l) x += a[i][l] * (ll)b[l][j];
        c[i][j] = x % mod;
    }
    return c;
}

vl mul(const vvi & a, const vl & b) {
    int n = a.size();
    vl c(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i] += a[i][j] * b[j];
        }
        c[i] %= mod;
    }
    return c;
}

vvi mpow(vvi x, ll n) {
    vvi res(2, vi(2));
    res[0][0] = res[1][1] = 1;
    while (n) {
        if (n & 1) res = mul(res, x);
        x = mul(x, x);
        n /= 2;
    }
    return res;
}

const int N = 1 << 17;
vector<vvi> tr(2 * N);

vvi getm(int l, int r) {
//    cerr << l << ' ' << r << endl;
    l += N;
    r += N;
    vvi resl = id(2), resr = id(2);
    while (l <= r) {
        if (l & 1) {
            resl = mul(tr[l], resl);
            //resl = mul(resl, tr[l]);
            ++l;
        }
        if (!(r & 1)) {
            resr = mul(resr, tr[r]);
            //resr = mul(tr[r], resr);
            --r;
        }
        if (l > r) break;
        l /= 2;
        r /= 2;
    }
    return mul(resr, resl);
    //return mul(resl, resr);
}

int n;
vi s;
map<ll, ll> was;
ll ret(ll i) {
    if (was.count(i)) return was[i];
    return s[i % n];
}

void recalc(vl & f, ll i) {
    ll nx = (f[1] * ret(i) + f[0] * ret(i+1)) % mod;
    f[1] = nx;
    swap(f[1], f[0]);
}

vvi calc(ll l, ll r) {
    vvi res(2, vi(2));
    res[0][0] = res[1][1] = 1;
    if (l > r) return res;
    int l1 = l % n, r1 = r % n;
//    cerr << l1 << ' ' << r1 << endl;
    if (l1 <= r1) {
        return mul(getm(l1, r1), mpow(getm(l1, l1 + n - 1), (r - l) / n));
        //return mul(mpow(getm(l1, l1 + n - 1), (r - l) / n), getm(l1, r1));
    } else {
        return mul(getm(0, r1), calc(l, r - r1 - 1));
        //return mul(calc(l, r - r1 - 1), getm(0, r1));
    }
}

int main() {
    ll k;
    int m;
    cin >> k >> mod >> n;
    if (k == 0 || mod == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (k == 1) {
        cout << 1 << endl;
        return 0;
    }
    s.resize(n);
    for (int i = 0; i < s.size(); ++i) scanf("%d", &s[i]);
    for (int i = 0; i < tr.size(); ++i) tr[i] = id(2);
    for (int i = 0; i < s.size(); ++i) {
        vvi a(2, vi(2));
        a[1][0] = 1;
        a[0][0] = s[(i + 1) % n];
        a[0][1] = s[i];
        tr[N + i] = tr[N + n + i] = a; 
    }
    for (int i = N - 1; i > 0; --i) tr[i] = mul(tr[2*i+1], tr[2*i]);
    cin >> m;
    vector<pll> q(m + 1);
    q[m] = pll(k, 0);
    for (int i = 0; i < m; ++i) {
        ll a; int b;
        scanf("%I64d %d", &a, &b);
        was[a] = b;
        q[i] = pll(a, b);
    }
    sort(q.begin(), q.end());
    vl f(2);
    f[0] = 1;
    ll prev = -1;
    for (int i = 0; i < q.size(); ++i) {
//        for (int j = prev + 1; j <= q[i].first - 2; ++j) recalc(f, j);
        f = mul(calc(prev + 1, q[i].first - 2), f);
//        cerr << q[i].first << ' ' << f[0] << ' ' << f[1] << endl;
        if (q[i].first == k) {
            cout << f[0] << endl;
            return 0;
        }
        if (prev < q[i].first - 1) recalc(f, q[i].first - 1);
        if (q[i].first == k-1) {
            cout << f[0] << endl;
            return 0;
        }
        if (prev < q[i].first) recalc(f, q[i].first);
        if (q[i].first == k-2) {
            cout << f[0] << endl;
            return 0;
        }
        prev = q[i].first;
    }
    return 0;
}