#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long long i64;
typedef long double ld;

const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 100100;
const int maxm = 400100;

struct Edge {
    int to, id;
};

bool usedEdge[maxm];
vector<Edge> g[maxn];
vector<Edge> gr[maxn];
int ptr[maxn];
vector<pair<int, int>> e;

vector<int> cycle;
void eulerCycle(int u) {
    while (ptr[u] < sz(g[u]) && usedEdge[g[u][ptr[u]].id])
        ++ptr[u];
    if (ptr[u] == sz(g[u]))
        return;
    const Edge &e = g[u][ptr[u]];
    usedEdge[e.id] = true;
    eulerCycle(e.to);
    cycle.push_back(e.id);
    eulerCycle(u);
}

int edges = 0;
void addEdge(int u, int v) {
    //cerr << u << ' ' << v << ' ' << edges << '\n';
    g[u].push_back(Edge{v, edges});
    gr[v].push_back(Edge{u, edges++});
    e.emplace_back(u, v);
}

int main() {
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("cycle.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    int ver = -1;
    forn (i, n) {
        string t;
        cin >> t;
        int u = t[0] * 256 + t[1];
        int v = t[1] * 256 + t[2];
        ver = u;
        addEdge(u, v);
    }
    int nodes = 256 * 256;
    vector<int> bads, badsr;
    bool SHIT = false;
    forn (i, nodes) {
        if (g[i].size() < gr[i].size())
            bads.push_back(i);
        if (gr[i].size() < g[i].size())
            badsr.push_back(i);
        if (g[i].size() + 1 < gr[i].size())
            SHIT = true;
        if (gr[i].size() + 1 < g[i].size())
            SHIT = true;
    }
    if (SHIT || bads.size() > 1 || badsr.size() > 1) {
        cout << "NO\n";
        return 0;
    }
    bool added = false;
    if (bads.size() == 1)
        addEdge(bads[0], badsr[0]), added = true;
    eulerCycle(ver);
    reverse(cycle.begin(), cycle.end());
    forn (i, edges)
        if (!usedEdge[i]) {
            cout << "NO\n";
            return 0;
        }
    if (added) {
        rotate(cycle.begin(), max_element(cycle.begin(), cycle.end()), cycle.end());
        cycle.erase(cycle.begin());
    }
    cout << "YES\n";
    int u = e[cycle[0]].first;
    printf("%c%c", u / 256, u % 256);
    for (auto id: cycle)
        printf("%c", e[id].second % 256);
    printf("\n");

    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}