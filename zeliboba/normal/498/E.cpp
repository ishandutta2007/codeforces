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
const int mod = 1000000007;

vvl mul(const vvl &x, const vvl&y) {
    int n = x.size();
    vvl res(n, vl(n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        for (int l = 0; l < n; ++l) {
            res[i][j] = (res[i][j] + x[i][l]*y[l][j]) % mod;
        }
    }
    return res;
}

vvl id(int n) {
    vvl res(n, vl(n));
    for (int i = 0; i < n; ++i)
        res[i][i] = 1;
    return res;
}

vvl mpow(vvl x, int n) {
    vvl res = id(x.size());
    while (n) {
        if (n & 1) res = mul(res, x);
        x = mul(x, x);
        n /= 2;
    }
    return res;
}

void out (vl v) {
    for (int i = 0; i < v.size(); ++i)
        cerr << v[i] << ' ';
    cerr << endl;
}

void out (vvl v) {
    for (int i = 0; i < v.size(); ++i)
        out(v[i]);
    cerr << endl;
}

int main() {
    vi w(7);
    for (int i = 0; i < w.size(); ++i) cin >> w[i];
    vl x(1, 1);
    for (int i = 0; i < w.size(); ++i) {
        int pw = (1 << (i+1));
        vl nx(pw);
        for (int j = 0; j < x.size(); ++j) {
            nx[j + pw/2] = x[j];
        }
        x.swap(nx);
        vvl a(pw, vl(pw));
        for (int m1 = 0; m1 < pw; ++m1) for (int m2 = 0; m2 < pw; ++m2) {
            vl d(i + 2);
            d[0] = 1;
            for (int j = 1; j < d.size(); ++j) {
                for (int l = 0; l + 1 < j; ++l)
                    d[j] += d[l];
                if (!(m1 & (1 << (j-1))) || !(m2 & (1 << (j-1)))) {
                    d[j] += d[j-1];
                }
                d[j] %= mod;
            }
            a[m1][m2] = d.back();
        }
        if (i == 6) {
            vi ind(pw);
            vi inv;
            int cnt = 0;
            for (int m = 0; m < pw; ++m) {
                if (m < pw/2) {
                    ind[m] = cnt;
                    inv.push_back(m);
                    ++cnt;
                } else {
                    int j = 0;
                    for (int b = 0; b < i + 1; ++b) if (m & (1 << b))
                        j += (1 << (i - b));
                    if (j < m) {
                        ind[m] = ind[j];
                    } else {
                        ind[m] = cnt;
                        inv.push_back(m);
                        ++cnt;
                    }
                }
            }
            vl nx(cnt);
            vvl na(cnt, vl(cnt));
            for (int m = 0; m < pw; ++m) {
                nx[ind[m]] += x[m];
                for (int m1 = 0; m1 < cnt; ++m1) {
                    na[ind[m]][m1] += a[m][inv[m1]];
                    na[ind[m]][m1] %= mod;
                }
            }
            x.swap(nx);
            a.swap(na);
        }
        a = mpow(a, w[i]);
//        if (i == 0) out(a);
        nx.assign(x.size(), 0);
        for (int i = 0; i < a.size(); ++i) for (int j = 0; j < a[i].size(); ++j)
            nx[i] = (nx[i] + a[i][j] * x[j]) % mod;
        x.swap(nx);
//        out(x);
    }
    cout << x.back() << endl;
    return 0;
}