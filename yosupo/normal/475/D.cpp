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

template <class T, int N>
struct GcdSegTree {
    static constexpr int size = 1<<N;
    T seg[size*2];

    inline T gcd(T a, T b) {
        if (b==0) return a;
        return gcd(b, a%b);
    }

    void init(T x) {
        for (int i = 0; i < size*2; i++) {
            seg[i] = 0;
        }
    }

    void add(int i, T x) {
        //if (i >= size) return;
        i += size - 1;
        seg[i] += x;
        while (i) {
            i = (i - 1) / 2;
            T s1 = seg[i*2+1], s2 = seg[i*2+2];
            seg[i] = gcd(s1, s2);
        }
    }

    inline T get(int a = 0, int b = size, int k = 0, int l = 0, int r = size) {
        if (a >= b || b > size) return 0;
        if (a <= l && r <= b) return seg[k];
        if (r <= a || b <= l) return 0;
        T vl = get(a, b, k*2+1, l, (l+r)/2);
        T vr = get(a, b, k*2+2, (l+r)/2, r);
        return gcd(vl, vr);
    }
};
template<class T>
inline T gcd(T a, T b) {
    if (b==0) return a;
    return gcd(b, a%b);
}
typedef Pi<int> P;
const int MN = 100100;
GcdSegTree<int, 17> g;
int a[MN], q[MN*3];
int main() {
    int n;
    cin >> n;
    g.init(0);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
        g.add(i, a[i]);
    }
    int m;
    cin >> m;
    vector<int> qv;
    for (int i = 0; i < m; i++) {
        scanf("%d", q+i);
        qv.push_back(q[i]);
    }
    sort(qv.begin(), qv.end());
    map<int, ll> res;
    vector<P> c1, c2;
    vector<int> d;
    c1.push_back(P(n+1, 1));
    for (int i = n-1; i >= 0; i--) {
        int j = i;
        c1.push_back(P(i+1, a[i]));
        c2.clear();
        c2.push_back(P(n+1, 1));
        int cs = c1.size();
        d.clear();
        d.push_back(1);
        for (int k = 1; k < cs; k++) {
            d.push_back(gcd(a[i], c1[k].y));
        }
        for (int k = 1; k < cs; k++) {
            if (binary_search(qv.begin(), qv.end(), d[k])) {
                res[d[k]] += c1[k-1].x-c1[k].x;
            }
            if (k == cs-1 || d[k] != d[k+1]) {
                c2.push_back(P(c1[k].x, d[k]));
            }
        }
        c1 = c2;
    }
    for (int i = 0; i < m; i++) {
        printf("%I64d\n", res[q[i]]);
    }
    return 0;
}