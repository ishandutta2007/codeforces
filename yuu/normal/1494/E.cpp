#include <bits/stdc++.h>
using namespace std;
int n, m;
map<pair<int, int>, char> edges;
int opposite_count;
int good_edge_count;

void AddEdge(int u, int v, char c) {
    edges[{u, v}] = c;
    auto f = edges.find({v, u});
    if (f == edges.end()) return;
    if (f->second == c) {
        good_edge_count++;
    }
    opposite_count++;
}

void RemoveEdge(int u, int v) {
    auto f = edges.find({v, u});
    auto g = edges.find({u, v});
    if (f != edges.end()) {
        if (f->second == g->second) {
            good_edge_count--;
        }
        opposite_count--;
    }
    edges.erase(g);
}

string Solve(int k) {
    if (good_edge_count) return "YES";
    if (k % 2 == 0) return "NO";  // no possible mid edge
    if (opposite_count) return "YES";
    return "NO";
}

void solve() {
    cin >> n >> m;
    char type, c;
    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> type;
        if (type == '?') {
            cin >> u;
            cout << Solve(u) << '\n';
            continue;
        }
        cin >> u >> v;
        if (type == '-') {
            RemoveEdge(u, v);
        } else {
            cin >> c;
            AddEdge(u, v, c);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}