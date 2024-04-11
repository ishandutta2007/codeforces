#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

template <int SIZE>
struct FenwickTree {
    ll seg[SIZE];
    
    void init() {
        fill_n(seg, SIZE, 0);
    }

    void add(int i, ll x) {
        while (i < SIZE) {
            seg[i] += x;
            i += (i+1) & ~i;
        }
    }

    //[0, i)
    ll sum(int i) {
        ll s = 0;
        int d = 1;
        while (i >= d) {
            i -= d;
            s += seg[i];
            d = (i+1) & ~i;
        }
        return s;
    }

    //[a, b)
    ll sum(int a, int b) {
        ll d = sum(b) - sum(a);
        return d;
    }
};

template <int SIZE>
struct FenwickRAdd {
    FenwickTree<SIZE> b0, b1;
    ll ds[SIZE+1];
    void init(const ll d[]) {
        b0.init();
        b1.init();
        ds[0] = 0;
        for (int i = 1; i <= SIZE; i++) {
            ds[i] = d[i-1]+ds[i-1];
        }
    }

    void add(int i, ll x) {
        b0.add(i, x);
    }

    void add(int l, int r, ll x) {
        b1.add(l, x);
        b1.add(r, -x);
        b0.add(l, -ds[l]*x);
        b0.add(r, ds[r]*x);
    }

    //[0, i)
    ll sum(int i) {
        ll d = b0.sum(i)+b1.sum(i)*ds[i];
        return d;
    }

    //[a, b)
    ll sum(int a, int b) {
        ll d = sum(b) - sum(a);
        return d;
    }
};

const int MN = 101000;
const int BS = 500;
const int BN = MN/BS;

int datb[BN] = {}, dat[MN] = {};
FenwickRAdd<MN> bit;

void setd(int l, int r, int x) {
    if (l/BS == r/BS) {
        int b = l/BS;
        if (datb[b]) {
            for (int i = b*BS; i < (b+1)*BS; i++) {
                dat[i] = datb[b];
            }
            datb[b] = 0;
        }
        for (int i = l; i < r; i++) {
            bit.add(i, abs(dat[i]-x));
            dat[i] = x;
        }
        return;
    }
    if (l%BS && datb[l/BS]) {
        int b = l/BS;
        for (int i = b*BS; i < (b+1)*BS; i++) {
            dat[i] = datb[b];
        }
        datb[b] = 0;
    }
    while (l%BS) {
        bit.add(l, abs(dat[l]-x));
        dat[l] = x;
        l++;
    }
    if (r%BS && datb[r/BS]) {
        int b = r/BS;
        for (int i = b*BS; i < (b+1)*BS; i++) {
            dat[i] = datb[b];
        }
        datb[b] = 0;
    }
    while (r%BS) {
        r--;
        bit.add(r, abs(dat[r]-x));
        dat[r] = x;
    }
    for (int i = l/BS; i < r/BS; i++) {
        if (!datb[i]) {
            for (int j = i*BS; j < (i+1)*BS; j++) {
                bit.add(j, abs(dat[j]-x));
            }
        } else {
            bit.add(i*BS, (i+1)*BS, abs(datb[i]-x));
        }
        datb[i] = x;
    }
}

ll buf[MN];
int main() {
    fill_n(buf, MN, 1);
    bit.init(buf);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        dat[i] = i+1;
    }
    for (int i = 0; i < m; i++) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x); l--;
            setd(l, r, x);
        } else {
            int l, r;
            scanf("%d %d", &l, &r); l--;
            cout << bit.sum(l, r) << endl;
        }
    }
    return 0;
}