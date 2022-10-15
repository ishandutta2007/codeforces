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

int N = 1<<17;
vi mi(2*N, 1.1e9), ma(2*N, -1.1e9), mid(2*N, 1.1e9);

int getma(int l, int r) {
    l += N; r += N;
    int res = -1.1e9;
    while (l <= r) {
        if (l % 2 == 1) {
            res = max(res, ma[l]);
            ++l;
        }
        if (r % 2 == 0) {
            res = max(res, ma[r]);
            --r;
        }
        if (l > r) break;
        l /= 2; r /= 2;
    }
    return res;
}

int getmi(int l, int r, const vi& v) {
    l += N; r += N;
    int res = 1.1e9;
    while (l <= r) {
        if (l % 2 == 1) {
            res = min(res, v[l]);
            ++l;
        }
        if (r % 2 == 0) {
            res = min(res, v[r]);
            --r;
        }
        if (l > r) break;
        l /= 2; r /= 2;
    }
    return res;
}

void setmi(int l, int val, vi & v) {
    l += N;
    while (l) {
        v[l] = min(v[l], val);
        l /= 2;
    }
}

int main() {
    int n, s, dist;
    scanf("%d%d%d", &n, &s, &dist);
    vi a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        mi[N+i] = ma[N+i] = a[i];
    }
    for (int i = N - 1; i > 0; --i) {
        mi[i] = min(mi[2*i], mi[2*i+1]);
        ma[i] = max(ma[2*i], ma[2*i+1]);
    }
    vi d(n + 1, n + 1);
    d[0] = 0;
    setmi(0, d[0], mid);
    for (int i = dist; i <= n; ++i) {
        int l = -1, r = i-dist+1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (getma(m,i-1) - getmi(m,i-1,mi) > s) {
                l = m;
            } else {
                r = m;
            }
        }
        if (r <= i-dist) {
            d[i] = 1 + getmi(r,i-dist,mid);
            setmi(i, d[i], mid);
        }
    }
    if (d.back() <= n) {
        cout << d.back() << endl;
    } else {
        cout << "-1\n";
    }
    return 0;
}