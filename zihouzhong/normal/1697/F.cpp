#include <bits/stdc++.h>
using namespace std;

namespace atcoder {
namespace internal {
template <class E> struct csr {
    vector<int> start;
    vector<E> elist;
    explicit csr(int n, const vector<pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};
}  // namespace internal
}  // namespace atcoder

namespace atcoder {
namespace internal {

// Reference:
// R. Tarjan,
// Depth-First Search and Linear Graph Algorithms
struct scc_graph {
  public:
    explicit scc_graph(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    // @return pair of (# of scc, scc id)
    pair<int, vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = min(low[v], low[to]);
                } else {
                    low[v] = min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    vector<vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        vector<vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

  private:
    int _n;
    struct edge {
        int to;
    };
    vector<pair<int, edge>> edges;
};

}  // namespace internal

}  // namespace atcoder

namespace atcoder {

// Reference:
// B. Aspvall, M. Plass, and R. Tarjan,
// A Linear-Time Algorithm for Testing the Truth of Certain Quantified Boolean
// Formulas
struct two_sat {
  public:
    two_sat() : _n(0), scc(0) {}
    explicit two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}

    void add_clause(int i, bool f, int j, bool g) {
        assert(0 <= i && i < _n);
        assert(0 <= j && j < _n);
        scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
        scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
    }
    bool satisfiable() {
        auto id = scc.scc_ids().second;
        for (int i = 0; i < _n; i++) {
            if (id[2 * i] == id[2 * i + 1]) return false;
            _answer[i] = id[2 * i] < id[2 * i + 1];
        }
        return true;
    }
    vector<bool> answer() { return _answer; }

  private:
    int _n;
    vector<bool> _answer;
    internal::scc_graph scc;
};

}  // namespace atcoder

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, K;
        cin >> n >> m >> K;
        atcoder::two_sat G(2 * n * K);
        auto id = [&](int o, int i, int j) {
            return o * n * K + i * K + j - 1;
        };
        for (int i = 0; i < n; i++) {
            G.add_clause(id(0, i, K), 1, id(0, i, K), 1);
            G.add_clause(id(1, i, 1), 1, id(1, i, 1), 1);
            for (int j = 1; j <= K; j++) {
                G.add_clause(id(0, i, j), 1, id(1, i, j), 1);
                if (j < K) G.add_clause(id(0, i, j), 0, id(1, i, j + 1), 0);
                if (j < K) G.add_clause(id(0, i, j), 1, id(1, i, j + 1), 1);
                if (j < K) G.add_clause(id(0, i, j), 0, id(0, i, j + 1), 1);
                if (j > 1) G.add_clause(id(1, i, j), 0, id(1, i, j - 1), 1);
                if (i + 1 < n) G.add_clause(id(1, i, j), 0, id(1, i + 1, j), 1);
                if (i + 1 < n) G.add_clause(id(0, i + 1, j), 0, id(0, i, j), 1);
            }
        }
        while (m--) {
            int op, i, j, x;
            cin >> op >> i, i--;
            if (op == 1) {
                cin >> x;
                G.add_clause(id(0, i, x), 0, id(1, i, x), 0);
            } else if (op == 2) {
                cin >> j >> x, j--;
                for (int p = 1; p <= K; p++) if (x - p >= 1 && x - p <= K) {
                    G.add_clause(id(1, i, p), 0, id(0, j, x - p), 1);
                    G.add_clause(id(1, j, p), 0, id(0, i, x - p), 1);
                }
                x = min(x - 1, K);
                G.add_clause(id(0, i, x), 1, id(0, i, x), 1);
                G.add_clause(id(0, j, x), 1, id(0, j, x), 1);
            } else {
                cin >> j >> x, j--;
                for (int p = 1; p <= K; p++) if (x - p >= 1 && x - p <= K) {
                    G.add_clause(id(0, i, p), 0, id(1, j, x - p), 1);
                    G.add_clause(id(0, j, p), 0, id(1, i, x - p), 1);
                }
                x = max(1, x - K);
                G.add_clause(id(1, i, x), 1, id(1, i, x), 1);
                G.add_clause(id(1, j, x), 1, id(1, j, x), 1);
            }
        }
        if (!G.satisfiable()) { cout << "-1\n"; continue; }
        auto res = G.answer();
        for (int i = 0, lst = 1; i < n; i++) {
            for (int j = lst; j <= K; j++) {
                if (res[id(0, i, j)]) { cout << (lst = j) << " "; break; }
            }
        }
        cout << "\n";
    }
    return 0;
}