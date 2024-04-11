#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cmath>
#include <numeric>
#include <functional>
#include <cassert>

#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <vector>


#include <vector>

namespace atcoder {

namespace internal {

template <class T> struct simple_queue {
    std::vector<T> payload;
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

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

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
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result;
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
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);

        std::vector<int> level(_n), iter(_n);
        internal::simple_queue<int> que;

        auto bfs = [&]() {
            std::fill(level.begin(), level.end(), -1);
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
                Cap d =
                    self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));
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
            std::fill(iter.begin(), iter.end(), 0);
            Cap f = dfs(dfs, t, flow_limit - flow);
            if (!f) break;
            flow += f;
        }
        return flow;
    }

    std::vector<bool> min_cut(int s) {
        std::vector<bool> visited(_n);
        internal::simple_queue<int> que;
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
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};

}  // namespace atcoder


#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

template<typename T>
vector<vector<T>> vec2d(int n, int m, T v){
    return vector<vector<T>>(n, vector<T>(m, v));
}

template<typename T>
vector<vector<vector<T>>> vec3d(int n, int m, int k, T v){
    return vector<vector<vector<T>>>(n, vector<vector<T>>(m, vector<T>(k, v)));
}

template<typename T>
void print_vector(vector<T> v, char delimiter=' '){
    if(v.empty()) {
        cout << endl;
        return;
    }
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<int> s(n), a(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> u(m), v(m);
    vector<int> deg(n), in_deg(n);
    for(int i = 0; i < m; i++) {
        cin >> u[i] >> v[i]; u[i]--; v[i]--;
        deg[u[i]]++;
        deg[v[i]]++;
    }
    for(int i = 0; i < n; i++){
        if(s[i] == 0) continue;
        if((a[i]+deg[i])%2 == 1){
            cout << "NO" << endl;
            return 0;
        }
        in_deg[i] = (a[i]+deg[i])/2;
        if(in_deg[i] < 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    atcoder::mf_graph<int> mf(2+m+n);
    auto edge_idx = [&](int i){
        return i+1;
    };
    auto vertex_idx = [&](int i){
        return i+1+m;
    };
    auto is_edge = [&](int idx){
        return edge_idx(0) <= idx && idx <= edge_idx(m-1);
    };
    auto is_vertex = [&](int idx){
        return vertex_idx(0) <= idx && idx <= vertex_idx(n-1);
    };
    int from = 0, to = n+m+1;
    int cnt_both = 0;
    for(int i = 0; i < m; i++){
        mf.add_edge(from, edge_idx(i), 1);
        if(s[u[i]] == 1 && s[v[i]] == 1){
            cnt_both++;
            mf.add_edge(edge_idx(i), vertex_idx(v[i]), 1);
            mf.add_edge(edge_idx(i), vertex_idx(u[i]), 1);
        }
    }
    for(int i = 0; i < n; i++){
        if(s[i] == 1) mf.add_edge(vertex_idx(i), to, in_deg[i]);
    }
    int f = mf.flow(from, to);
    if(f != cnt_both){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0; i < m; i++){
        if(s[u[i]] == 1 && s[v[i]] == 1){
            continue;
        }else if(s[u[i]] == 1){
            mf.add_edge(edge_idx(i), vertex_idx(u[i]), 1);
        }else if(s[v[i]] == 1){
            mf.add_edge(edge_idx(i), vertex_idx(v[i]), 1);
        }
    }
    f += mf.flow(from, to);
    int indeg_sum = accumulate(in_deg.begin(), in_deg.end(), 0);
    if(f != indeg_sum){
        cout << "NO" << endl;
        return 0;
    }
    vector<bool> is_u_in(m);
    vector<bool> is_v_in(m);
    for(auto e: mf.edges()){
        if(is_edge(e.from) && is_vertex(e.to) && e.flow == 1){
            int i = e.from-1;
            if(e.to == vertex_idx(u[i])) is_u_in[i] = true;
            if(e.to == vertex_idx(v[i])) is_v_in[i] = true;
        }
    }
    
    cout << "YES" << endl;
    for(int i = 0; i < m; i++){
        if(is_u_in[i]) cout << v[i]+1 << ' ' << u[i]+1 << endl;
        else if(is_v_in[i]) cout << u[i]+1 << ' ' << v[i]+1 << endl;
        else{
            if(s[u[i]] == 1) cout << u[i]+1 << ' ' << v[i]+1 << endl;
            else cout << v[i]+1 << ' ' << u[i]+1 << endl;
        }
    }
}