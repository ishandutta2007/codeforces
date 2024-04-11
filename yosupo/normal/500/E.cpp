//#define NDEBUG

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <cassert>
#include <numeric>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;


template <int S>
struct RangeMaxQuery {
    static const int N = 1<<S;
    typedef ll D;
    D seg[2*N];

    void init() {
        fill_n(seg, 2*N, -1);
    }

    void init(int n, D x[]) {
        init();
        for (int i = 0; i < n; i++) {
            seg[i+S] = x[i];
        }
        for (int i = N-1; i >= 1; i--) {
            seg[i] = max(seg[i*2], seg[i*2+1]);
        }
    }

    void set(int i, D x) {
        i += N;
        seg[i] = x;
        while (i) {
            i /= 2;
            seg[i] = max(seg[i*2], seg[i*2+1]);
        }
    }

    D get(int a, int b, int k = 1, int l = 0, int r = N) {
        if (r <= a || b <= l) return -1;
        if (a <= l && r <= b) return seg[k];
        int md = (l+r)/2;
        D dl = get(a, b, k*2, l, md);
        D dr = get(a, b, k*2+1, md, r);
        return max(dl, dr);
    }
};

template <int S>
struct StarrySkyTree {
    typedef ll D;
    static const int N = 1<<S;
    ll seg[2*N], lz[2*N];
    int sz[2*N];
    void init() {
        fill_n(seg, 2*N, 0);
        fill_n(lz, 2*N, -1);
        for (int i = 2*N; i >= N; i--) {
            sz[i] = 1;
        }
        for (int i = N-1; i >= 0; i--) {
            sz[i] = sz[i*2]+sz[i*2+1];
        }
    }

    void lzdata(int k, D x) {
        seg[k] = sz[k]*x;
        lz[k] = x;
    }
    void push(int k) {
        if (k >= N) return;
        if (lz[k] != -1) {
            lzdata(k*2, lz[k]);
            lzdata(k*2+1, lz[k]);
            lz[k] = -1;
        }
    }
    void update(int k) {
        seg[k] = seg[k*2]+seg[k*2+1];
    }

    void set(int a, int b, ll x, int k = 1) {
        if (sz[k] <= a || b <= 0) return;
        if (a <= 0 && sz[k] <= b) {
            lzdata(k, x);
            return;
        }
        push(k);
        set(a, b, x, k*2);
        set(a-sz[k]/2, b-sz[k]/2, x, k*2+1);
        update(k);
    }

    ll get(int a, int b, int k = 1) {
        if (sz[k] <= a || b <= 0) return 0;
        if (a <= 0 && sz[k] <= b) return seg[k];
        push(k);
        ll dl = get(a, b, k*2);
        ll dr = get(a-sz[k]/2, b-sz[k]/2, k*2+1);
        return dl+dr;
    }
};
const int MS = 18;
const int MN = 1<<MS;
const ll INF = 1LL<<30;
RangeMaxQuery<MS> rmq;
StarrySkyTree<MS> sst;
P q[MN];
ll res[MN];
ll p[MN], l[MN];
vector<int> qv[MN];
int main() {
    rmq.init(); sst.init();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int pp, ll;
        scanf("%d %d", &pp, &ll);
        p[i] = pp; l[i] = ll;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y); x--; y--;
        q[i] = P(x, y);
        qv[x].push_back(i);
    }
    for (int i = n-1; i >= 0; i--) {
        int idx = upper_bound(p, p+n, p[i]+l[i])-p;
        ll nd = rmq.get(i+1, idx)-p[i];
        l[i] = max(l[i], nd);
        rmq.set(i, p[i]+l[i]);
    }
    for (int i = n-1; i>= 0; i--) {
        int idx = upper_bound(p, p+n, p[i]+l[i])-p;
        sst.set(i+1, idx, 0);
        sst.set(i, i+1, INF);
        sst.set(idx, idx+1, p[idx]-(p[i]+l[i]));
        for (int d: qv[i]) {
            int b = q[d].second;
            res[d] = sst.get(i+1, b+1); 
        }
    }
    for (int i = 0; i < m; i++) {
        printf("%d\n", (int)res[i]);
    }
}