#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
const ll LLONG_MAX = 1e18;

struct TEdge {
    int from, to;
    ll capacity, flow;
    ll cost;
    TEdge* reverse;
};

TEdge edgePool[1000000];
int edgePoolPtr = 0;

typedef vector<TEdge*> ve;
vector< ve > edges; //resize

int SOURCE, TARGET; //assign

TEdge* AddEdge(int from, int to, ll capacity, ll cost = 0) {
    TEdge* e1 = &edgePool[edgePoolPtr++];
    TEdge* e2 = &edgePool[edgePoolPtr++];
    TEdge fw = {from, to, capacity, 0, cost, e2};
    TEdge bw = {to, from, 0, 0, cost, e1};
    *e1 = fw;
    *e2 = bw;
    edges[from].push_back(e1);
    edges[to].push_back(e2);
    return e1;
}

inline ll AvailableCapacity(const TEdge* p) {
    return (p->capacity - p->flow);
}

class TDinic {
    vector<int> Distances;
    vector<size_t> Ptr;
    int N;
    void BFS() {
        deque<int> q;
        Distances.assign(N, -1);
        Distances[SOURCE] = 0;
        q.push_back(SOURCE);
        while (!q.empty()) {
            int p = q.front();
            q.pop_front();
            for (size_t i = 0; i < edges[p].size(); i++) {
                if (!AvailableCapacity(edges[p][i]))
                    continue;
                int c = edges[p][i]->to;
                if (Distances[c] == -1) {
                    Distances[c] = Distances[p] + 1;
                    q.push_back(c);
                }
            }
        }
    }
    ll DFS(int p, ll fl) {
        if (fl == 0)
            return 0;
        if (p == TARGET)
            return fl;
        ll res = 0;

        for (size_t &i = Ptr[p]; Ptr[p] < edges[p].size() && fl != 0; ++i) {
            if (!AvailableCapacity(edges[p][i])) {
                continue;
            }
            if (Distances[edges[p][i]->from] + 1 != Distances[edges[p][i]->to])
                continue;
            ll pushed = DFS(edges[p][i]->to, min(fl, AvailableCapacity(edges[p][i])));
            fl -= pushed;
            res += pushed;
            edges[p][i]->flow += pushed;
            edges[p][i]->reverse->flow -= pushed;
            if (fl == 0)
                break;
        }
        return res;
    }
public:
    TDinic() {
        N = (int)edges.size();
    }
    ll GetMaxFlow() {
        ll res = 0;
        while (true) {
            BFS();
            Ptr.assign(N, 0);
            ll p = DFS(SOURCE, LLONG_MAX / 2);
            if (!p)
                break;
            res += p;
        }
        return res;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    vi p;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int x = a[i];
        for (int d = 2; d * d <= x; ++d) if (x % d == 0) {
            p.push_back(d);
            while (x % d == 0) x /= d;
        }
        if (x > 1) p.push_back(x);
    }
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
    vii b(m);
    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        --x; --y;
        if (x % 2) swap(x, y);
        b[i] = pii(x, y);
    }
    SOURCE = n; TARGET = SOURCE + 1;
    ll res = 0;
    for (int it = 0; it < p.size(); ++it) {
        int d = p[it];
        edges.clear();
        edges.resize(TARGET + 1);
        for (int i = 0; i < m; ++i) {
            AddEdge(b[i].first, b[i].second, 1e9);   
        }
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            while (a[i] % d == 0) {
                ++cnt;
                a[i] /= d;
            }
            if (i % 2) {
                AddEdge(i, TARGET, cnt);
            } else {
                AddEdge(SOURCE, i, cnt);
            }
        }
        TDinic fl;
        res += fl.GetMaxFlow();
    }
    cout << res << endl;
    return 0;
}