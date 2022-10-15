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
    ll GetMaxFlow() {
        N = (int)edges.size();
        ll res = 0;
        while (true) {
            BFS();
            Ptr.assign(N, 0);
            ll p = DFS(SOURCE, 1e18 / 2);
            if (!p)
                break;
            res += p;
        }
        return res;
    }

vvi gr;
vi was;
vi res;

void resdfs(int v) {
    if (was[v]) return;
    was[v] = 1;
    res.push_back(v);
    for (int i = 0; i < gr[v].size(); ++i) {
        resdfs(gr[v][i]);
    }
}

int main() {
    vi erat(100000, 1);
    erat[0] = erat[1] = 0;
    for (int i = 2; i * i < erat.size(); ++i) if (erat[i]) {
        for (int j = i * i; j < erat.size(); j += i)
            erat[j] = 0;
    }
    int n;
    cin >> n;
    vi a(n);
    vi odd, even;
    vi indodd, indeven;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 2) {
            odd.push_back(a[i]);
            indodd.push_back(i);
        } else {
            even.push_back(a[i]);
            indeven.push_back(i);
        }
    }
    if (odd.size() != even.size()) {
        cout << "Impossible" << endl;
        return 0;
    }
    int m = odd.size();
    SOURCE = n, TARGET = n+1;
    edges.resize(n + 2);
    for (int i = 0; i < odd.size(); ++i) for (int j = 0; j < even.size(); ++j) if (erat[odd[i] + even[j]]) {
//        cerr << i << ' ' << m+j << endl;
        AddEdge(i, m + j, 1);
    }
    for (int i = 0; i < odd.size(); ++i) {
//        cerr << SOURCE << ' ' << i << endl;
        AddEdge(SOURCE, i, 2);
    }
    for (int i = 0; i < even.size(); ++i) {
//        cerr << m+i << ' ' << TARGET << endl;
        AddEdge(m+i, TARGET, 2);
    }
//    TDinic flow();
    int flow = GetMaxFlow();
    if (flow != n) {
//        cerr << flow << endl;
        cout << "Impossible" << endl;
        return 0;
    }
    gr.resize(n);
    for (int i = 0; i < odd.size(); ++i) {
        for (int j = 0; j < edges[i].size(); ++j) if (edges[i][j]->flow && edges[i][j]->to < n) {
            gr[i].push_back(edges[i][j]->to);
            gr[edges[i][j]->to].push_back(i);
        }
    }
    was.assign(n, 0);
    vvi ans;
    for (int i = 0; i < n; ++i) if (!was[i]) {
        res.clear();
        resdfs(i);
        ans.push_back(res);
    }
    cout << ans.size() << endl;
//    cerr << indodd[0] << ' ' << indodd[5] << endl;
    for (int i = 0; i < ans.size(); ++i) {
/*        for (int j = 0; j < ans[i].size(); ++j) {
            cerr << ans[i][j] << ' ';
        }
        cerr << "m=" << m << endl;*/
        cout << ans[i].size();
        for (int j = 0; j < ans[i].size(); ++j) {
            int x = 0;
            if (ans[i][j] < m) {
                x = indodd[ans[i][j]];
            } else {
                x = indeven[ans[i][j] - m];
            }
            cout << ' ' << x + 1;
        }
        cout << endl;
    }
    return 0;
}