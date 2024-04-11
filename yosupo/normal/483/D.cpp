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
#include <valarray>
#include <list>
#include <cstring>

using namespace std;
const int MN = 100100;

template <int N>
struct RangeMinQuery {
    typedef bool D;
    static const int S = 1<<N;
    D seg[S*2];

    void init() {
        fill_n(seg, S*2, numeric_limits<D>::max());
    }

    void init(int n, D x[]) {
        init();
        for (int i = 0; i < n; i++) {
            seg[i + S-1] = x[i];
        }
        for (int k = N-1; k >= 0; k--) {
            for (int i = (1<<k)-1; i < (1<<(k+1))-1; i++) {
                D s1 = seg[i*2+1], s2 = seg[i*2+2];
                seg[i] = min(s1, s2);
            }
        }
    }

    void set(int i, D x) {
        i += S - 1;
        seg[i] = x;
        while (i) {
            i = (i - 1) / 2;
            D s1 = seg[i*2+1], s2 = seg[i*2+2];
            seg[i] = min(s1, s2);
        }
    }

    void add(int i, D x) {
        i += S - 1;
        seg[i] += x;
        while (i) {
            i = (i - 1) / 2;
            D s1 = seg[i*2+1], s2 = seg[i*2+2];
            seg[i] = min(s1, s2);
        }
    }

    inline D get(int a, int b, int k = 0, int l = 0, int r = S) {
        if (a <= l && r <= b) return seg[k];
        if (r <= a || b <= l) return numeric_limits<D>::max();
        D vl = get(a, b, k*2+1, l, (l+r)/2);
        D vr = get(a, b, k*2+2, (l+r)/2, r);
        return min(vl, vr);
    }
};

int imos[30][MN];
bool imores[30][MN];
bool nolf[30][MN];
bool norf[30][MN];
int res[MN];
int l[MN], r[MN], q[MN];
RangeMinQuery<17> rq[30];
int main() {
    for (int i = 0; i < 30; i++) {
        rq[i].init();
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", l+i, r+i, q+i); l[i]--;
        for (int j = 0; j < 30; j++) {
            if (q[i] & (1<<j)) {
                imos[j][l[i]] += 1;
                imos[j][r[i]] -= 1;
            }
        }
    }
    for (int j = 0; j < 30; j++) {
        int k = 0;
        for (int i = 0; i <= n; i++) {
            k += imos[j][i];
            imores[j][i] = (k > 0);
        }
    }
    for (int j = 0; j < 30; j++) {
        rq[j].init(n, imores[j]);
        for (int i = 0; i < n; i++) {
            if (imores[j][i]) {
                res[i] |= 1<<j;
            }
        }
    }
    bool f = true;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 30; j++) {
            if (!(q[i] & (1<<j))) {
                if (rq[j].get(l[i], r[i])) {
                    f = false;
                    break;
                }
            }
        }
    }
    if (!f) {
        printf("NO\n");
    } else {
        printf("YES\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", res[i]);
        }
        printf("\n");
    }
    return 0;
}