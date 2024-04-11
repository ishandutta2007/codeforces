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
#include <cstdio>

using namespace std;
typedef long long ll;


template <int S>
struct StarrySkyTree {
    typedef ll D;
    static const int N = 1<<S;
    static const D INF = 1LL<<60;
    struct Node {
        D ma, l, r;
        D dsm;
    } n[2*N];
    int sz[2*N];
    StarrySkyTree() {
        for (int i = 2*N-1; i >= N; i--) {
            sz[i] = 1;
        }
        for (int i = N-1; i >= 1; i--) {
            sz[i] = sz[i*2]+sz[i*2+1];
        }
    }
    void init_node(D d, D h, int k) {
        h *= 2;
        k += N;
        n[k].ma = 0;
        n[k].l = h;
        n[k].r = d+h;
        n[k].dsm = d;
    }
    void init() {
        for (int i = N-1; i >= 1; i--) {
            update(i);
        }
    }
    Node merge(Node l, Node r) {
        Node u;
        u.ma = max(max(l.ma, r.ma), l.r+r.l);
        u.l = max(l.l, l.dsm+r.l);
        u.r = max(l.r+r.dsm, r.r);
        u.dsm = l.dsm+r.dsm;
        return u;
    }
    void update(int k) {
        assert(1 <= k && k < N);
        n[k] = merge(n[k*2], n[k*2+1]);
    }
    Node get(int a, int b, int k = 1) {
        if (sz[k] <= a || b <= 0) return Node{0, -INF, -INF, 0};
        if (a <= 0 && sz[k] <= b) return n[k];
        return merge(get(a, b, k*2), get(a-sz[k]/2, b-sz[k]/2, k*2+1));
    }
};
StarrySkyTree<18> st;
ll d[1<<18], h[1<<18];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int dd;
        scanf("%d", &dd);
        d[i] = d[i+n] = dd;
    }
    for (int i = 0; i < n; i++) {
        int hh;
        scanf("%d", &hh);
        h[i] = h[i+n] = hh;
    }
    for (int i = 0; i < 2*n; i++) {
        st.init_node(d[i], h[i], i);
    }
    st.init();
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        if (a <= b) a += n;
        b++;
        printf("%I64d\n", st.get(b, a).ma);
    }
    return 0;
}