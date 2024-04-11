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

int dw(int x) {
    if (x < mod) return x;
    return x - mod;
}

int n;
void conv(vi & x) {
    for (int b = 0; b < n; ++b) {
        int B = 1 << b;
        for (int i = 0; i < x.size(); ++i) if (i & B) {
            x[i] = dw(x[i] + x[i^B]);
        }
    }
}

void convinv(vi & x) {
    for (int b = 0; b < n; ++b) {
        int B = 1 << b;
        for (int i = 0; i < x.size(); ++i) if (i & B) {
            x[i] = (x[i] - x[i^B] + mod) % mod;
        }
    }
}

vi mor(vi a, vi b) {
    conv(a);
    conv(b);
    vi res(a.size());
    for (int i = 0; i < a.size(); ++i) {
        res[i] = a[i] * (ll)b[i] % mod;
    }
    convinv(res);
    return res;
}

vi mand(vi a, vi b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vi res = mor(a, b);
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string s;
    cin >> s;
    cin >> n;
    vvi v(n, vi(5));
    for (int i = 0; i < n; ++i) for (int j = 0; j < 5; ++j) cin >> v[i][j];
    vector<vvi> pre(2, vvi(4, vi(1 << n)));
    for (int i = 0; i < 4; ++i) for (int t = 0; t < 2; ++t) {
        int mask = 0;
        for (int j = 0; j < n; ++j) {
            mask += ((v[j][i] == t) << j);
        }
        pre[t][i][mask] = 1;
    }
    vi pretot(1 << n);
    for (int t = 0; t < 2; ++t) for (int i = 0; i < 4; ++i) for (int j = 0; j < pre[t][i].size(); ++j)
        pretot[j] += pre[t][i][j];
    s = '(' + s + ')';
    vi p(s.size());
    vi q;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') q.push_back(i);
        if (s[i] == ')') {
            p[i] = q.back();
            p[q.back()] = i;
            q.pop_back();
        }
    }
    vvi d(s.size());
    vii ts;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            ts.push_back(pii(p[i] - i, i));
        }
    }
    sort(ts.begin(), ts.end());
    for (int ii = 0; ii < ts.size(); ++ii) {
        int l = ts[ii].second;
        int r = p[l];
        if (r - l == 2) {
            if (s[l + 1] == '?') {
                d[l] = pretot;
            } else if (isupper(s[l + 1])) {
                d[l] = pre[1][s[l + 1] - 'A'];
            } else {
                d[l] = pre[0][s[l + 1] - 'a'];
            }
            continue;
        }
        int f1 = l + 1;
        int f2 = p[r-1];
        int mid = f2 - 1;
        if (s[mid] == '|') {
            d[l] = mor(d[f1], d[f2]);
        } else if (s[mid] == '&') {
            d[l] = mand(d[f1], d[f2]);
        } else {
            d[l] = mor(d[f1], d[f2]);
            vi x = mand(d[f1], d[f2]);
            for (int i = 0; i < x.size(); ++i) {
                d[l][i] = dw(d[l][i] + x[i]);
            }
        }
    }
    int m = 0;
    for (int i = 0; i < n; ++i) m += (v[i][4] << i);
    cout << (d[0][m] % mod + mod) % mod << endl;
    return 0;
}