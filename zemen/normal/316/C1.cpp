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
#define INFL __LONG_LONG_MAX__
#define pb push_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef complex <double> point;

#define NAME "c"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

#define _(a,b) memset((a),(b),sizeof(a))
#define sz(a) (int)(a).size()
 
const int maxn = 10000;
 
struct Edge {
    int a, b, id, cap, flow, cost;
};
 
vector<int> g[maxn];
vector<Edge> e;
int S, T;
int d[maxn], pot[maxn], last[maxn];
set<pair<int, int> > q;
 
void adde(int a, int b, int cap, int cost) {
    //~ cerr << a << ' ' << b << ' ' << cost << '\n';
    Edge t;
    t.a = a;
    t.b = b;
    t.id = sz(e);
    t.cap = cap;
    t.flow = 0;
    t.cost = cost;
    e.pb(t);
    g[t.a].pb(t.id);

    t.id++;
    swap(t.a, t.b);
    t.cap = 0;
    t.cost = -cost;
    e.pb(t);
    g[t.a].pb(t.id);
}
 
void update(int id, int nd, int lst) {
    if (d[id] > nd)
    {
            q.erase(mp(d[id], id));
            d[id] = nd;
            last[id] = lst;
            q.insert(mp(nd, id));
    }
}
 
bool dij() {
    _(d, 127);
    update(S, 0, -1);
    while (!q.empty())
    {
            int id = q.begin()->second;
            q.erase(q.begin());
            for (int i = 0; i < sz(g[id]); i++)
            {
                    Edge &t = e[g[id][i]];
                    if (t.flow < t.cap)
                            update(t.b, d[t.a] + pot[t.a] - pot[t.b] + t.cost, t.id);
            }
    }
    for (int i = 0; i < maxn; i++)
    {
            if (d[i] < INF)
                    pot[i] += d[i];
    }
    return d[T] < INF;
}
 
void augm() {
    int id = T, mn = INF;
    while (id != S)
    {
            Edge &t = e[last[id]];
            mn = min(mn, t.cap - t.flow);
            id = t.a;
    }
    id = T;
    while (id != S)
    {
            Edge &t = e[last[id]];
            t.flow += mn;
            e[t.id ^ 1].flow -= mn;
            id = t.a;
    }
}
 
int flow() {
    while (dij())
            augm();
    int ret = 0;
    for (int i = 0; i < sz(e); i += 2) {
            ret += e[i].flow * e[i].cost;
            //~ cerr << e[i].a << ' ' << e[i].b << ' ' << e[i].flow << ' ' << e[i].cost << '\n';
        }
    return ret;
}

int n, m;
int a[100][100];

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < m; ++j) {
            int u = i * m + j;
            int v = i * m + j + m;
            if ((i + j) % 2 == 0)
                swap(u, v);
            adde(u, v, 1, a[i][j] != a[i + 1][j]);
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m - 1; ++j) {
            int u = i * m + j;
            int v = i * m + j + 1;
            if ((i + j) % 2 == 0)
                swap(u, v);
            adde(u, v, 1, a[i][j] != a[i][j + 1]);
        }
    S = n * m;
    T = n * m + 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if ((i + j) % 2)
                adde(S, i * m + j, 1, 0);
            else
                adde(i * m + j, T, 1, 0);
    int res = flow();
    cout << res << '\n';
}