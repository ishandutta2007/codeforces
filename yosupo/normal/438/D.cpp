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
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef unsigned int uint;

//size:2**N N=19:524288 N=17:131072 N=12:4096
template <int N>
struct SegTree {
    static const int size = 1<<N;
    typedef pair<ll, ll> P;
    P seg[size*2];
    
    void init() {
        for (int i = 0; i < size; i++) {
            seg[i] = P(0, 0);
        }
    }

    void set(int i, ll x) {
        i += size-1;
        seg[i] = P(x, x);
        while (i) {
            i = (i-1) / 2;
            seg[i].first = seg[i*2+1].first + seg[i*2+2].first;
            seg[i].second = max(seg[i*2+1].second, seg[i*2+2].second);
        }
    }

    void mod(ll x, int a, int b, int k = 0, int l = 0, int r = size) {
        if (seg[k].second < x) return;
        if (r <= a || b <= l) return;
        if (a <= l && r <= b && r-l == 1) {
            seg[k].first %= x;
            seg[k].second %= x;
            return;
        }

        mod(x, a, b, k*2+1, l, (l+r)/2);
        mod(x, a, b, k*2+2, (l+r)/2, r);

        seg[k].first = seg[k*2+1].first + seg[k*2+2].first;
        seg[k].second = max(seg[k*2+1].second, seg[k*2+2].second);
    }

    ll get(uint a, uint b, uint k = 0, uint l = 0, uint r = size) {
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) {
            return seg[k].first;
        }
        ll r1 = get(a, b, k*2+1, l, (l+r)/2);
        ll r2 = get(a, b, k*2+2, (l+r)/2, r);
        return r1+r2;
    }
};

SegTree<17> s;
int main() {
    s.init();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int d;
        scanf("%d", &d);
        s.set(i, d);
    }
    for (int i = 0; i < m; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int l, r;
            scanf("%d %d", &l, &r); l--;
            printf("%I64d\n", s.get(l, r));
        } else if (t == 2) {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x); l--;
            s.mod(x, l, r);
        } else {
            int k, x;
            scanf("%d %d", &k, &x); k--;
            s.set(k, x);
        }
    }
    return 0;
}