#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

const int MN = 200100;
int n;
int a[MN];


struct Node {
    using NP = Node*;

    ll sm;
    int mi, lz;

    /*
     init_node, update, push
    */
    void init_node(int v = 0) {
        sm = mi = v;
        lz = -1;
    }
    void update() {
        assert(lz == -1);
        sm = l->sm + r->sm;
        mi = min(l->mi, r->mi);
    }
    void push() {
        if (lz != -1) {
            l->lzdata(lz);
            r->lzdata(lz);
            lz = -1;
        }
    }
    void lzdata(int x) {
        sm = (ll)x * sz;
        mi = x;
        lz = x;
    }

    void set(int a, int b, int x) {
        if (b <= 0 or sz <= a) return;
        if (a <= 0 and sz <= b) {
            lzdata(x);
            return;
        }
        push();
        l->set(a, b, x);
        r->set(a - sz/2, b - sz/2, x);
        update();
    }
    ll get(int a, int b) {
        if (b <= 0 or sz <= a) return 0;
        if (a <= 0 and sz <= b) {
            return sm;
        }
        push();
        return l->get(a, b) + r->get(a-sz/2, b-sz/2);
    }
    
    int find(int x) {
        if (x <= mi) return sz;
        if (sz == 1) {
            return 0;
        }
        int u = l->find(x);
        if (u < l->sz) return u;
        return l->sz + r->find(x);
    }

    NP l, r;
    int sz;
    Node(int sz, int d[]) : sz(sz) {
        init_node(d[0]);
        if (sz == 1) return;
        l = new Node(sz/2, d);
        r = new Node(sz - sz/2, d+sz/2);
        update();
    }
};

Node* tr;
int d[MN];
void init() {
    tr = new Node(n, d);
}
void setd(int r, int x) {
    int u = tr->find(x);
    if (u < r) {
        tr->set(u, r, x);
    }
/*    for (int i = 0; i < r; i++) {
        d[i] = max(d[i], x);
    }*/
}
ll que(int l) {
/*    ll ans = 0;
    for (int i = l; i < n; i++) {
        ans += d[i];
    }
    assert(ans == tr->get(l, n));*/
    return tr->get(l, n);
}

bool used[MN], buf0[MN], buf1[MN];
int ml[MN];
ll solve() {
    int ma = 0;
    fill_n(ml, MN, n);
    for (int i = n-1; i >= 0; i--) {
        d[i] = ma;
        for (int j = 1; j*j <= a[i]; j++) {
            if (a[i] % j == 0) {
                int x = j, y = a[i]/j;
                if (ml[x] < n) ma = max(ma, x);
                if (ml[y] < n) ma = max(ma, y);
                if (ml[x] == n) ml[x] = i;
                if (ml[y] == n) ml[y] = i;
            }
        }
    }
    init();
    ll ans = 0;
    fill_n(used, MN, false);
    fill_n(buf0, MN, false);
    fill_n(buf1, MN, false);
    for (int i = 0; i < n; i++) {
        ans += que(i);
//        printf("%d %lld\n", i, que(i+1));
        for (int j = 1; j*j <= a[i]; j++) {
            if (a[i] % j == 0) {
                int x = j, y = a[i]/j;
                //ll
                if (used[x] and !buf0[x]) {
                    buf0[x] = true;
                    setd(n, x);
                }
                if (used[y] and !buf0[y]) {
                    buf0[y] = true;
                    setd(n, y);
                }


                //lr
                if (ml[x] < n and !buf1[x]) {
                    buf1[x] = true;
                    setd(ml[x], x);
                }
                if (ml[y] < n and !buf1[y]) {
                    buf1[y] = true;
                    setd(ml[y], y);
                }

                used[x] = true;
                used[y] = true;
            }
        }
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }
    cout << solve() << endl;
    return 0;
}