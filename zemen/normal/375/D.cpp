#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>
#include <cassert>

using namespace std;

#define INF 1000000001
#define INFL 1000000000000000001ll
#define pb push_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef complex <double> point;

#define NAME "d"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

inline int rand_int() {
    return rand() << 15 | rand();
}

struct node {
    node *l, *r;
    int x, y;
    int cnt;
    int count;
    
    node(int _x) {
        x = _x;
        cnt = count = 1;
        y = rand_int();
        l = r = 0;
    }
};

typedef node * lnk;

inline int cnt(lnk t) {
    return t ? t->cnt : 0;
}

inline void update(lnk t) {
    if (t)
        t->cnt = cnt(t->l) + cnt(t->r) + t->count;
}

inline void split(lnk t, lnk &l, lnk &r, int x) {
    if (!t) {
        l = r = 0;
        return;
    }
    if (t->x >= x) {
        split(t->l, l, t->l, x);
        r = t;
    } else {
        split(t->r, t->r, r, x);
        l = t;
    }
    update(t);
}

inline void merge(lnk &t, lnk l, lnk r) {
    if (!l) {
        t = r;
        return;
    }
    if (!r) {
        t = l;
        return;
    }
    if (l->y > r->y) {
        merge(l->r, l->r, r);
        t = l;
    } else {
        merge(r->l, l, r->l);
        t = r;
    }
    update(t);
}

inline void erase(lnk &t, int x) {
    lnk a, b, c;
    split(t, a, b, x);
    split(b, b, c, x + 1);
    assert(b);
    if (b->count == 1)
        b = 0;
    else {
        b->count--;
        b->cnt--;
    }
    merge(t, a, b);
    merge(t, t, c);
}

inline void insert(lnk &t, int y) {
    lnk a, b, c;
    split(t, a, b, y);
    split(b, b, c, y + 1);
    if (b) {
        b->count++;
        b->cnt++;
    } else
        b = new node(y);
    merge(t, a, b);
    merge(t, t, c);
}

inline void print(lnk t) {
    if (!t)
        return;
    print(t->l);
    cerr << t->x << ' ' << t->count << '\n';
    print(t->r);
}

struct data {
    int sz;
    map <int, int> col;
    lnk t;
    
    data() {
        sz = 0;
    }
    
    void add(int c, int cnt) {
        if (!col[c]) {
            sz++;
        } else
            erase(t, col[c]);
        int new_val = col[c] + cnt;
        insert(t, new_val);
        col[c] += cnt;
    }
    
    int get(int x) {
        lnk a, b;
        split(t, a, b, x);
        int res = cnt(b);
        merge(t, a, b);  
        return res;
    }
    
    void pop() {
        --sz;
        col.erase(col.begin());
    }
};

int c[100001];
vector <int> q[100001];
int q_cnt[100001];
vector <int> g[100001];
int ans[100001];
data t[100001];

inline int dfs(int u, int prev = -1) {
    int cur = u;
    t[cur].add(c[u], 1);
    for (int i = 0; i < (int) g[u].size(); ++i) {
        int v = g[u][i];
        if (v == prev)
            continue;
        int pos = dfs(v, u);
        if (t[pos].sz > t[cur].sz)
            swap(pos, cur);
        while (t[pos].sz) {
            t[cur].add(t[pos].col.begin()->fi, t[pos].col.begin()->se);
            t[pos].pop();
        }
    }
    for (int i = 0; i < (int) q[u].size(); ++i) {
        ans[q[u][i]] = t[cur].get(q_cnt[q[u][i]]);
    }
    //~ cerr << "vertex " << u + 1 << '\n';
    //~ for (__typeof(t[cur].col.begin()) it = t[cur].col.begin(); it != t[cur].col.end(); ++it)
        //~ cerr << it->fi << ' ' << it->se << '\n';
    //~ cerr << "tree\n";
    //~ print(t[cur].t);
    return cur;
}

int main() {
    srand(42);
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    int u, v;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        --u;
        q[u].pb(i);
        q_cnt[i] = v;
    }
    dfs(0);
    for (int i = 0; i < m; ++i)
        cout << ans[i] << '\n';
}