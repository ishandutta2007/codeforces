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
#include <numeric>
#include <valarray>
#include <array>
using namespace std;


typedef pair<int, int> P;
typedef tuple<int, int, int> T;

template <int N>
struct StarrySkyTree {
    using P = std::pair<int, int>;
    using uint = unsigned int;
    static constexpr int size = 1<<N;
    struct T {
        int x, y, z;
        T(){}
        T(int xx, int yy, int zz) {
            x = xx; y = yy; z = zz;
        }
    };
    T seg[size*2];
    
    void init() {
        fill_n(seg, size*2, T(0, 0, 0));
        for (int i = 0; i < size; i++) {
            seg[i+size-1].z = i;
        }
        for (int i = size-2; i >= 0; i--) {
            seg[i].z = seg[i*2+1].z;
        }
    }

    inline void add(uint a, uint b, int x, uint k = 0, uint l = 0, uint r = size) {
        if (a >= b || b > size) return;
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            seg[k].x += x;
            seg[k].y += x;
            return;
        }
        add(a, b, x, k*2+1, l, (l+r)/2);
        add(a, b, x, k*2+2, (l+r)/2, r);
        if (seg[k*2+1].x < seg[k*2+2].x) {
            seg[k].x = seg[k].y + seg[k*2+2].x;
            seg[k].z = seg[k*2+2].z;
        } else {
            seg[k].x = seg[k].y + seg[k*2+1].x;
            seg[k].z = seg[k*2+1].z;
        }
        //seg[k].x = std::get<1>(seg[k]).second + std::max(seg[k*2+1].first, seg[k*2+2].first);
    }

    inline P get(uint a = 0, uint b = size, uint k = 0, uint l = 0, uint r = size) {
        if (a <= l && r <= b) return P(seg[k].x, seg[k].z);
        if (r <= a || b <= l) return P(-10000000, -10000000);
        P vl = get(a, b, k*2+1, l, (l+r)/2);
        P vr = get(a, b, k*2+2, (l+r)/2, r);
        if (vl.first < vr.first) {
            return P(seg[k].y + vr.first, vr.second);
        } else {
            return P(seg[k].y + vl.first, vl.second);
        }
    }
};
StarrySkyTree<17> tr;
const int MN = 101000;
int ll[MN], rr[MN];
int l[MN], r[MN];
P v[MN];
vector<int> gl[MN];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int vv;
        scanf("%d %d %d", ll+i, &vv, rr+i);
        v[i] = P(vv, i);
    }
    sort(v, v+n);
    for (int i = 0; i < n; i++) {
        l[i] = ll[v[i].second];
        r[i] = rr[v[i].second];
    }
    for (int i = 0; i < n; i++) {
        l[i] = lower_bound(v, v+n, P(l[i], -1))-v;
        r[i] = upper_bound(v, v+n, P(r[i], MN))-v;
        gl[l[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
    }
    tr.init();
    int u = 0;
    int res = 0;
    int ml, mr;
    for (int i = 0; i < n; i++) {
        if (i) {
            tr.add(i-1, r[i-1], -1);
        }
        for (int d: gl[i]) {
            tr.add(d, r[d], 1);
        }
        P p = tr.get();
        if (res < p.first) {
            res = p.first;
            ml = i;
            mr = p.second;
        }
    }
    cout << res << endl;
    for (int i = ml; i <= mr; i++) {
        if (l[i] <= ml && mr <= r[i]) {
            printf("%d ", v[i].second+1);
        }
    }
    return 0;
}