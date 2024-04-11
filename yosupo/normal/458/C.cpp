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
#include <stack>
using namespace std;

typedef long long ll;

struct Pi {
    int x, y;
    Pi() {}
    Pi(int xx, int yy) {
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
};

struct Ti {
    int x, y, z;
    Ti() {}
    Ti(int xx, int yy, int zz) {
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
};

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

const int MN = 100100;
FenwickTree<MN> f1, f2;
int num[MN];
queue<int> g[MN];

vector<Pi> v;
vector<Pi> vn;
void erf(int i) {
    f1.add(i, -1);
    f2.add(i, -v[i].x);
}

ll cal(int k) {
    if (k <= 0) return 0;
    int l = -1, r = MN-10;
    while (r - l > 1) {
        int md = (r+l)/2;
        if (f1.sum(md) >= k) {
            r = md;
        } else {
            l = md;
        }
    }
    return f2.sum(r);
}

int main() {
    f1.init(); f2.init();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v.push_back(Pi(b, a));
        num[a]++;
    }
    for (int i = 0; i < MN-10; i++) {
        vn.push_back(Pi(num[i], i));
    }
    sort(v.begin(), v.end());
    sort(vn.begin(), vn.end(), greater<Pi>());
    for (int i = 0; i < n; i++) {
        f1.add(i, 1);
        f2.add(i, v[i].x);
        g[v[i].y].push(i);
    }
    ll res = 1LL<<60;
    int u = 0;
    ll ka = 0;
    int kan = 0;
    for (int i = n; i >= 1; i--) {
        while (u < MN-10 && vn[u].x >= i) u++;
        for (int j = 0; j < u; j++) {
            int u = g[vn[j].y].front(); g[vn[j].y].pop();
            erf(u);
            ka += v[u].x;
            kan++;
        }
        //if (i-kan < 0) break;
        res = min(res, ka+cal(i-kan));
    }
    cout << res << endl;
    return 0;
}