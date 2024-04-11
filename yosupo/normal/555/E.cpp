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
typedef long long ll;
typedef unsigned long long ull;

/**
 * 
 */

template <int V>
struct Bridge {
    vector<int> g[V];
    void add(int a, int b) {
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int imos[V]; //0(i, root[i])
    bool used[V];
    int root[V], dps[V];
    void dfs(int i, int b, int dp) {
        root[i] = b;
        dps[i] = dp;
        used[i] = true;
        for (int d: g[i]) {
            if (used[d]) {
                if (dps[i] < dps[d]) {
                    imos[i]--;
                    imos[d]++;
                }
            } else {
                dfs(d, i, dp+1);
            }
        }
    }

    int dfs2(int i) {
        used[i] = true;
        for (int d: g[i]) {
            if (used[d]) continue;
            imos[i] += dfs2(d);
        }
        return imos[i];
    }

    void exec(int v = V) {
        fill_n(imos, v, 0);
        fill_n(root, v, -1);
        fill_n(dps, v, 0);
        fill_n(used, v, false);
        for (int i = 0; i < v; i++) {
            if (used[i]) continue;
            dfs(i, -1, 0);
        }
        fill_n(used, v, false);
        for (int i = 0; i < v; i++) {
            if (root[i] != -1) continue;
            dfs2(i);
        }
    }
};

/**
 * UnionFindQuickFind
 *
 * templateint N
 *
 * See_Also: http://topcoder.g.hatena.ne.jp/iwiwi/20131226/1388062106
 */
template <int N>
struct UnionFind {
    int ig[N];
    vector<int> gi[N];
    int gn;
    /// UnionFindn
    void init(int n = N) {
        for (int i = 0; i < n; ++i) {
            ig[i] = i;
            gi[i] = {i};
        }
        gn = n;
    }

    /// ab
    void merge(int a, int b) {
        if (same(a, b)) return;
        gn--;
        int x = ig[a], y = ig[b];
        if (gi[x].size() < gi[y].size()) swap(x, y);
        for (int j: gi[y]) {
            ig[j] = x;
        }
        gi[x].insert(gi[x].end(), gi[y].begin(), gi[y].end());
        gi[y].clear();
    }
    /// ab
    bool same(int a, int b) {
        return ig[a] == ig[b];
    }
    /// 
    int group_num() {
        return gn;
    }
};

/**
 * Link-Cut Tree
 *
 * linkcutevertroot
 * 
 * 
 * 
 * 2k()ICPC
 */
struct LCNode {
    typedef LCNode* NP;

    typedef int D;
    struct Node {
        bool type;
        bool esz;
        bool up, down;
        bool ups, downs;
        bool ulz, dlz;
    } n;
    LCNode() : l(nullptr), r(nullptr), sz(0), rev(false) {
        n.type = false;
        n.esz = n.up = n.down = n.ups = n.downs = n.ulz = n.dlz = false;

    }
    LCNode(bool t) : p(nullptr), l(last), r(last), sz(1), rev(false) {
        n.type = n.esz = t;
        n.up = n.down = n.ups = n.downs = false;
        n.ulz = n.dlz = false;
    }

    NP update() {
        assert(this != last);
        sz = 1+l->sz+r->sz;
        n.esz = l->n.esz | r->n.esz;
        if (n.type) {
            n.esz = true;
        }
        n.ups = n.up;
        n.downs = n.down;
        if (l->sz) {
            n.ups |= l->n.ups;
            n.downs |= l->n.downs;
        }
        if (r->sz) {
            n.ups |= r->n.ups;
            n.downs |= r->n.downs;
        }
        return this;
    }
    void push() {
        int lsz = l->sz, rsz = r->sz;
        if (rev) {
            if (lsz) {
                l->revdata();
            }
            if (rsz) {
                r->revdata();
            }
            rev = false;
        }
        if (n.ulz) {
            if (lsz) {
                l->ulzdata();
            }
            if (rsz) {
                r->ulzdata();
            }
            n.ulz = false;
        }
        if (n.dlz) {
            if (lsz) {
                l->dlzdata();
            }
            if (rsz) {
                r->dlzdata();
            }
            n.dlz = false;
        }
    }
    void revdata() {
        assert(this != last);
        swap(l, r);
        swap(n.up, n.down);
        swap(n.ups, n.downs);
        swap(n.ulz, n.dlz);
        rev ^= true;
    }
    void ulzdata() {
        if (!n.esz) return;
        if (n.type) {
            n.up = true;
        }
        n.ups = true;
        n.ulz = true;
    }
    void dlzdata() {
        if (!n.esz) return;
        if (n.type) {
            n.down = true;
        }
        n.downs = true;
        n.dlz = true;
    }

    //
    static LCNode last_d;
    static NP last;
    NP p, l, r;
    int sz;
    bool rev;
    inline int pos() {
        if (p) {
            if (p->l == this) return -1;
            if (p->r == this) return 1;
        }
        return 0;
    }
    void rot() {
        NP qq = p->p;
        int pps = p->pos();
        if (p->l == this) {
            p->l = r; r->p = p;
            r = p; p->p = this;
        } else {
            p->r = l; l->p = p;
            l = p; p->p = this;
        }
        p->update(); update();
        p = qq;
        if (!pps) return;
        if (pps == -1) {
            qq->l = this;
        } else {
            qq->r = this;
        }
        qq->update();
    }
    void splay() {
        assert(this != last);
        supush();
        int ps;
        while ((ps = pos())) {
            int pps = p->pos();
            if (!pps) {
                rot();
            } else if (ps == pps) {
                p->rot(); rot();
            } else {
                rot(); rot();
            }
        }
    }
    void expose() {
        assert(this != last);
        NP u = this, ur = last;
        do {
            u->splay();
            u->r = ur;
            u->update();
            ur = u;
        } while ((u = u->p));
        splay();
    }
    /**
     * splaypush
     * stack overflow
     */
    void supush() {
        if (pos()) {
            p->supush();
        }
        push();
    }
    //

    void link(NP r) {
        assert(this != r);
        expose();
        r->expose();
        assert(l == last);
        p = r;
    }

    void cut() {
        expose();
        l->p = NULL;
        l = last;
        update();
    }

    NP root() {
        expose();
        NP u = this;
        while (u->l != last) {
            u = u->l;
            u->push();
        }
        u->expose(); //
        return u;
    }

    NP parent() {
        expose();
        NP u = this->l;
        if (u == last) return nullptr;
        u->push();
        while (u->r != last) {
            u = u->r;
            u->push();
        }
        u->expose();
        return u;
    }

    void evert() {
        expose();
        revdata();
    }

    NP lca(NP n) {
        n->expose();
        expose();
        NP t = n;
        while (n->p != nullptr) {
            if (!n->pos()) t = n->p;
            n = n->p;
        }
        return (this == n) ? t : nullptr;
    }
};
LCNode LCNode::last_d = LCNode();
LCNode::NP LCNode::last = &last_d;


const int MN = 200100;

LCNode tr[MN], et[MN];
int etc = 0;

Bridge<MN> br;
UnionFind<MN> uf;

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        br.add(a, b);
    }
    br.exec(n);
    uf.init(n);
    for (int i = 0; i < n; i++) {
        if (br.root[i] == -1) continue;
        if (br.imos[i] == 0) continue;
        uf.merge(i, br.root[i]);
    }
    for (int i = 0; i < n; i++) {
        tr[i] = LCNode(false);
        et[i] = LCNode(true);
    }
    for (int i = 0; i < n; i++) {
        if (br.root[i] == -1) continue;
        if (br.imos[i] != 0) continue;
        int x = uf.ig[i], y = uf.ig[br.root[i]];
        tr[x].evert();
        tr[x].link(&et[etc]);
        et[etc].link(&tr[y]);
        etc++;
    }

    for (int i = 0; i < q; i++) {
        int s, d;
        scanf("%d %d", &s, &d); s--; d--;
        s = uf.ig[s]; d = uf.ig[d];
//        printf("query %d %d\n", s, d);
        tr[s].evert();
        tr[d].expose();
        if (tr[d].n.downs) {
            cout << "No" << endl;
            return 0;
        }
        tr[d].ulzdata();
        tr[0].evert();
        // printf("debug: ");
        // for (int i = 0; i < n; i++) {
        //     tr[i].expose();
        //     printf("(%d %d) ", tr[i].n.ups, tr[i].n.downs);
        // } printf("\n");
    }
    cout << "Yes" << endl;
    return 0;
}