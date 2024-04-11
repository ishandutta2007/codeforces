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
typedef vector<string> vs;
const int N = 1 << 17;

vi col(2*N, 1);
vi t(2*N, -1);
vi tfail(2*N, 0);
vl sum(2*N, 0);
vl add(2*N, 0);
int T = 1, n;

ll setdown(int pos, int x, int sz, int time, int c) {
    if (pos >= n+N) return 0;
    if (t[pos] > time) {
        time = t[pos];
        c = col[pos];
    } else {
        t[pos] = time;
        col[pos] = c;
    }
    ll added = 0;
//    cerr << t[pos] << ' ' << tfail[pos] << ' ' << col[pos] << ' ' << x << ' ' << sz << endl;
    if (t[pos] > tfail[pos]) {
        ll diff = abs(x - c);
        added = diff * sz;
        add[pos] += diff;
    } else {
        added += setdown(2*pos, x, sz/2, t[pos], col[pos]);
        added += setdown(2*pos+1, x, sz/2, t[pos], col[pos]);
    }
    sum[pos] += added;
    return added;
}

void sets(int pos, int x, int sz) {
    int pos1 = pos;
    while (pos1) {
        if (t[pos1] > t[pos]) {
            col[pos] = col[pos1];
            t[pos] = t[pos1];
        }
        pos1 /= 2;
    }
    ll added = 0;
//    cerr << t[pos] << ' ' << tfail[pos] << ' ' << col[pos] << ' ' << x << ' ' << sz << endl;
    if (t[pos] > tfail[pos]) {
        ll diff = abs(x-col[pos]);
        added = diff * sz;
        add[pos] += diff;
    } else {
        added += setdown(2*pos, x, sz/2, t[pos], col[pos]);
        added += setdown(2*pos+1, x, sz/2, t[pos], col[pos]);
    }
    sum[pos] += added;
    col[pos] = x;
    t[pos] = T;
    pos /= 2;
    while (pos) {
        sum[pos] += added;
        tfail[pos] = T;
        pos /= 2;
    }
}

void setall(int l, int r, int x) {
    l += N;
    r += N;
    int sz = 1;
    while (l <= r) {
        if (l == r) {
            sets(l, x, sz);
            break;
        }
        if (l % 2) {
            sets(l, x, sz);
            ++l;
        }
        if (r % 2 == 0) {
            sets(r, x, sz);
            --r;
        }
        if (l > r) break;
        l /= 2;
        r /= 2;
        sz *= 2;
    }
}

ll gets(int pos1, int sz) {
    int pos = pos1;
    ll res = sum[pos];
    while (pos) {
        pos /= 2;
        res += add[pos] * sz;
    }
//    cerr << pos1 << ' ' << sum[pos1] << ' ' << res << endl;
    return res;
}

ll getsum(int l, int r) {
    l += N;
    r += N;
    ll res = 0;
    int sz = 1;
    while (l <= r) {
        if (l == r) {
            res += gets(l, sz);
            break;
        }
        if (l % 2) {
            res += gets(l, sz);
            ++l;
        }
        if (r % 2 == 0) {
            res += gets(r, sz);
            --r;
        }
        if (l > r) break;
        l /= 2;
        r /= 2;
        sz *= 2;
    }
    return res;
}

int main() {
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        col[N + i] = i + 1;
        t[N + i] = 0;
        tfail[N + i] = -1;
    }
    for (; T <= m; ++T) {
        int type,l,r,x;
        scanf("%d%d%d",&type,&l,&r);
        --l; --r;
        if (type == 1) {
            scanf("%d", &x);
            setall(l, r, x);
        } else {
            cout << getsum(l,r) << endl;
        }
    }
    return 0;
}