#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair <int, int> pii;

typedef pair <ll, int> pli;

const int N = 3e5 + 10;

int n, m, q, tot;

ll f[N];

vector <int> c[N];

struct Edge {
    int u, v;
    ll w;
} e[N];

map <pii, int> id;

set <pli> g[N], mn, s;

set <pli> :: iterator it; 

bool chk_(int x, int y) {
    return e[x].u != e[y].u && e[x].u != e[y].v && e[x].v != e[y].u && e[x].v != e[y].v;
}

void upd_(int u, int k, int op) {
    if (~f[u])
        s.erase(s.find(pli(f[u], u)));

    it = g[u].begin(), c[u].clear();

    for (int i = 1; i <= 3 && it != g[u].end(); i++, it++) 
        if (mn.find(*it) != mn.end()) 
            mn.erase(mn.find(*it));
    
    if (op == 1)
        g[u].insert(pli(e[k].w, k));
    else
        g[u].erase(g[u].find(pli(e[k].w, k)));

    if (g[u].size() >= 3) {
        it = g[u].begin(), f[u] = 0;

        for (int i = 1; i <= 3; i++, it++)    
            f[u] += (*it).first;
        
        s.insert(pli(f[u], u));
    } else  
        f[u] = -1;

    it = g[u].begin();

    for (int i = 1; i <= 3 && it != g[u].end(); i++, it++)  
        mn.insert(*it), c[u].push_back((*it).second);
}

void ins_() {
    int x = ++tot;
    scanf("%d%d%lld", &e[x].u, &e[x].v, &e[x].w);

    if (e[x].u > e[x].v) swap(e[x].u, e[x].v);

    upd_(e[x].u, x, 1);
    upd_(e[x].v, x, 1);
    id[pii(e[x].u, e[x].v)] = x;
}       

void del_(int k) {
    upd_(e[k].u, k, -1);
    upd_(e[k].v, k, -1);
    id[pii(e[k].u, e[k].v)] = 0;
}

void solve_() {
    ll ans = 1e18;

    if (s.size())
        ans = min(ans, (*s.begin()).first);
    
    int x = (*mn.begin()).second, cnt = 0;

    vector <int> del;

    it = mn.begin(), it++;

    for (; it != mn.end(); it++, cnt++) {
        int y = (*it).second;

        if (chk_(x, y)) {
            ans = min(ans, e[x].w + e[y].w);
            break;
        }

        if (cnt > 6)
            del.push_back(y);
    }

    for (int i : del)
        mn.erase(mn.find(pli(e[i].w, i)));

    int u = e[x].u, v = e[x].v;

    for (int i : c[u])
        for (int j : c[v])
            if (chk_(i, j))
                ans = min(ans, e[i].w + e[j].w);
    
    printf("%lld\n", ans);
}

int main() {
    scanf("%d%d", &n, &m);

    memset(f, -1, sizeof(f));

    for (int i = 1; i <= m; i++)
        ins_();

    solve_();
    
    scanf("%d", &q);

    for (int u, v, op, i = 1; i <= q; i++) {
        scanf("%d", &op);

        if (op == 1)
            ins_();
        else {
            scanf("%d%d", &u, &v);

            if (u > v) swap(u, v);

            del_(id[pii(u, v)]);
        }

        solve_();
    }
}