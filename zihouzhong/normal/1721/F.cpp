#include <bits/stdc++.h>
using namespace std;

template <class T> struct simple_queue {
    vector<T> payload;
    int pos = 0;
    void reserve(int n) { payload.reserve(n); }
    int size() const { return int(payload.size()) - pos; }
    bool empty() const { return pos == int(payload.size()); }
    void push(const T& t) { payload.push_back(t); }
    T& front() { return payload[pos]; }
    void clear() {
        payload.clear();
        pos = 0;
    }
    void pop() { pos++; }
};

template <class Cap> struct mf_graph {
  public:
    mf_graph() : _n(0) {}
    explicit mf_graph(int n) : _n(n), g(n) {}

    int add_edge(int from, int to, Cap cap) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap});
        g[to].push_back(_edge{from, from_id, 0});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
    };

    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }
    vector<edge> edges() {
        int m = int(pos.size());
        vector<edge> result;
        for (int i = 0; i < m; i++) {
            result.push_back(get_edge(i));
        }
        return result;
    }
    void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto& _e = g[pos[i].first][pos[i].second];
        auto& _re = g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }

    Cap flow(int s, int t) {
        return flow(s, t, numeric_limits<Cap>::max());
    }
    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);

        vector<int> level(_n), iter(_n);
        simple_queue<int> que;

        auto bfs = [&]() {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            que.clear();
            que.push(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.push(e.to);
                }
            }
        };
        auto dfs = [&](auto self, int v, Cap up) {
            if (v == s) return up;
            Cap res = 0;
            int level_v = level[v];
            for (int& i = iter[v]; i < int(g[v].size()); i++) {
                _edge& e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                Cap d = self(self, e.to, min(up - res, g[e.to][e.rev].cap));
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) return res;
            }
            level[v] = _n;
            return res;
        };

        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            fill(iter.begin(), iter.end(), 0);
            Cap f = dfs(dfs, t, flow_limit - flow);
            if (!f) break;
            flow += f;
        }
        return flow;
    }

    vector<bool> min_cut(int s) {
        vector<bool> visited(_n);
        simple_queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = true;
            for (auto e : g[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }

  private:
    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    vector<pair<int, int>> pos;
    vector<vector<_edge>> g;
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n1, n2, m, q;
    cin >> n1 >> n2 >> m >> q;
    int s = n1 + n2, t = s + 1;
    mf_graph<int> G(t + 1);
    for (int i = 0; i < n1; i++) {
        G.add_edge(s, i, 1);
    }
    for (int i = 0; i < n2; i++) {
        G.add_edge(n1 + i, t, 1);
    }
    vector<array<int, 2>> E(m);
    vector<int> eid(m);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v, u--, v--;
        E[i] = {u, v}, eid[i] = G.add_edge(u, n1 + v, 1);
    }
    G.flow(s, t);
    auto vis = G.min_cut(s);
    long long sum = 0;
    vector<bool> mark(m);
    vector<array<int, 2>> dec;
    for (int i = 0; i < m; i++) {
        if (!G.get_edge(eid[i]).flow) continue;
        mark[i] = 1, sum += i + 1;
        dec.push_back({!vis[E[i][0]] ? E[i][0] + 1 : -E[i][1] - 1, i});
    }
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            cout << "1\n" << dec.back()[0] << endl;
            sum -= dec.back()[1] + 1, mark[dec.back()[1]] = 0;
            cout << sum << endl, dec.pop_back();
        } else {
            vector<int> res;
            for (int i = 0; i < m; i++) {
                if (mark[i]) res.push_back(i);
            }
            cout << res.size() << endl;
            for (int x : res) {
                cout << x + 1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}