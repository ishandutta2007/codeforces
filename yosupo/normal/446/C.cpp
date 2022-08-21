#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <complex>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

template <int SIZE, ll MD>
struct FenwickTreeMod {
    ll seg[SIZE];
    
    void init() {
        fill_n(seg, SIZE, 0);
    }

    void add(int i, ll x) {
        x %= MD;
        while (i < SIZE) {
            seg[i] += x;
            seg[i] %= MD;
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
            s %= MD;
            d = (i+1) & ~i;
        }
        return s;
    }

    //[a, b)
    ll sum(int a, int b) {
        ll d = sum(b) - sum(a);
        return (d % MD + MD) % MD;
    }
};

template <int SIZE, ll MD>
struct FenwickRAddMod {
    FenwickTreeMod<SIZE, MD> b0, b1;
    ll ds[SIZE+1];
    void init(const ll d[]) {
        b0.init();
        b1.init();
        ds[0] = 0;
        for (int i = 1; i <= SIZE; i++) {
            ds[i] = (d[i-1]+ds[i-1])%MD;
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
        ll d = b0.sum(i)+b1.sum(i)*ds[i]%MD;
        return (d % MD + MD) % MD;
    }

    //[a, b)
    ll sum(int a, int b) {
        ll d = sum(b) - sum(a);
        return (d % MD + MD) % MD;
    }
};

const int MN = 303000;
const ll MD = 1e9+9.1;

FenwickRAddMod<MN-100, MD> b1, b2;
ll fib[MN], fibsum[MN];

ll data[MN];
int main() {
    fib[0] = 0; fib[1] = 1;
    for (int i = 2; i < MN; i++) {
        fib[i] = fib[i-1]+fib[i-2];
        fib[i] %= MD;
    }
    b1.init(fib+1); b2.init(fib+2);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int u;
        scanf("%d", &u);
        b1.add(i, u);
    }
    for (int i = 0; i < m; i++) {
        int type, l, r;
        scanf("%d %d %d", &type, &l, &r); l--;
        if (type == 1) {
            int u = l%2 ? -1 : 1;
            b1.add(l, r, u*fib[l+1]);
            b2.add(l, r, -u*fib[l]);
        } else {
            ll u = b1.sum(l, r)+b2.sum(l, r);
            int k = u%MD;
            printf("%d\n", k);
        }
    }
    return 0;
}