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
#include <deque>

using namespace std;

typedef long long ll;

template<class T>
struct Pi {
    T x, y;
    Pi() {}
    Pi(T xx, T yy) {
        x = xx; y = yy;
    }
    bool operator<(const Pi &r) const {
        if (x != r.x) return x < r.x;
        return y < r.y;
    }
    bool operator>(const Pi &r) const {
        if (x != r.x) return x > r.x;
        return y > r.y;
    }
    bool operator==(const Pi &r) const {
        if (x != r.x) return false;
        return y == r.y;
    }
};

template<class T>
struct Ti {
    T x, y, z;
    Ti() {}
    Ti(T xx, T yy, T zz) {
        x = xx; y = yy; z = zz;
    }
    bool operator<(const Ti &r) const {
        if (x != r.x) return x < r.x;
        if (y != r.y) return y < r.y;
        return z < r.z;
    }
    bool operator>(const Ti &r) const {
        if (x != r.x) return x > r.x;
        if (y != r.y) return y > r.y;
        return z > r.z;
    }
    bool operator==(const Ti &r) const {
        if (x != r.x) return false;
        if (y != r.y) return false;
        return z == r.z;
    }
};

template <int SIZE>
struct FenwickTree {
    int seg[SIZE];
    
    void init() {
        fill_n(seg, SIZE, 0);
    }

    void add(int i, int x) {
        while (i < SIZE) {
            seg[i] += x;
            i += (i+1) & ~i;
        }
    }

    //[0, i)
    int sum(int i) {
        int s = 0;
        int d = 1;
        while (i >= d) {
            i -= d;
            s += seg[i];
            d = (i+1) & ~i;
        }
        return s;
    }

    //[a, b)
    int sum(int a, int b) {
        int d = sum(b) - sum(a);
        return d;
    }
};
const int MN = 101000;
FenwickTree<MN> f;
int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        f.add(i, 1);
    }
    int dir = 1;
    int off = 0;
    for (int qq = 0; qq < q; qq++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int p;
            scanf("%d", &p);
            if (p > n-p) {
                p = n-p;
                dir *= -1;
            }
            if (dir == 1) {
                for (int i = 0; i < p; i++) {
                    int u = f.sum(off+i, off+i+1);
                    f.add(off+i, -u);
                    f.add(off+2*p-i-1, u);
                }
                off += p;
            } else {
                for (int i = 0; i < p; i++) {
                    int u = f.sum(off+n-i-1, off+n-i);
                    f.add(off+n-i-1, -u);
                    f.add(off+n-2*p+i, u);
                }
            }
            n -= p;
        } else {
            int l, r;
            scanf("%d", &l); scanf("%d", &r);
            if (dir == 1) {
                printf("%d\n", f.sum(off+l, off+r));
            } else {
                printf("%d\n", f.sum(off+n-r, off+n-l));
            }
        }
    }
    return 0;
}