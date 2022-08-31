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
#include <array>

using namespace std;

typedef long long ll;

struct Tree {

    struct Node {
        Node *l, *r;
        int sz;
        bool f;
        array<int, 3> d;
        Node(int li, int ri) {
            sz = ri-li;
            d.fill(0);
            if (ri-li == 1) return;
            int md = (li+ri)/2;
            l = new Node(li, md);
            r = new Node(md, ri);
        }
    } *n;

    typedef Node* NP;

    Tree() {
        n = NULL;
    }
    Tree(NP u) {
        n = new Node(*u);
    }
    Tree(int li, int ri) {
        n = new Node(li, ri);
    }

    NP set(NP x, int k) {
        x = new Node(*x);
        if (x->sz == 1) {
            x->f = true;
            x->d.fill(1);
            return x;
        }
        if (k < x->l->sz) {
            x->l = set(x->l, k);
        } else {
            x->r = set(x->r, k- x->l->sz);
        }
        auto &ld = x->l->d, &md = x->d, &rd = x->r->d;
        md[0] = (ld[0] == x->l->sz) ? ld[0]+rd[0] : ld[0];
        md[2] = (rd[2] == x->r->sz) ? ld[2]+rd[2] : rd[2];
        md[1] = max(max(ld[1], rd[1]), ld[2]+rd[0]);
        return x;
    }
    
    array<int, 3> get(NP x, int l, int r) {
        array<int, 3> md;
        if (x->sz <= l || r <= 0) {
            md.fill(0);
            return md;
        }
        if (l <= 0 && x->sz <= r) return x->d;
        if (x->sz == 1) return x->d;
        array<int, 3> ld = get(x->l, l, r);
        array<int, 3> rd = get(x->r, l- x->l->sz, r- x->l->sz);
        md[0] = (ld[0] == x->l->sz) ? ld[0]+rd[0] : ld[0];
        md[2] = (rd[2] == x->r->sz) ? ld[2]+rd[2] : rd[2];
        md[1] = max(max(ld[1], rd[1]), ld[2]+rd[0]);    
        return md;
    }
    Tree set(int k) {
        return Tree(set(n, k));
    }
    array<int, 3> get(int l, int r) {
        return get(n, l, r);
    }
};

const int MN = 100100;
typedef pair<int, int> P;
int a[MN];
Tree tr[MN];
int main() {
    int n;
    cin >> n;
    vector<P> v;
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
        v.push_back(P(a[i], i));
    }
    sort(v.begin(), v.end());
    tr[n] = Tree(0, n);
    for (int i = n-1; i >= 0; i--) {
        tr[i] = tr[i+1].set(v[i].second);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r, w;
        cin >> l >> r >> w; l--;
        int lh = 0, rh = n;
        while (rh - lh > 1) {
            int md = (rh + lh) / 2;
            if (tr[md].get(l, r)[1] >= w) {
                lh = md;
            } else {
                rh = md;
            }
        }
        printf("%d\n", v[lh].first);
    }
    return 0;
}