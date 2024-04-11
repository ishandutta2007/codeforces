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

template<typename T>
class Compress{
    public:
    vector<T> data;
    int offset;
    Compress(vector<T> data_, int offset=0): offset(offset){
        data = data_;
        sort(begin(data), end(data));
        data.erase(unique(begin(data), end(data)), end(data));
    };
    int operator[](T x) {
        auto p = lower_bound(data.begin(), data.end(), x);
        assert(x == *p);
        return offset+(p-data.begin());
	}
    T inv(int x){
        return data[x-offset];
    }
    int size(){
        return data.size();
    }
};

void solve(){
    int n; cin >> n;
    vector<map<int, int>> dists(2);
    vector<vector<int>> v(2);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            int d; cin >> d;
            v[i].push_back(d);
            if(dists[i].count(d) == 0){
                dists[i][d] = 0;
            }
            dists[i][d]++;
        }
    }
    vector<Compress<int>> cp;
    for(int i = 0; i < 2; i++) cp.push_back(Compress<int>(v[i]));
    int m0 = dists[0].size();
    int m1 = dists[1].size();
    int d0 = dists[0].begin()->first;
    int s = 0, t = m0+m1+1;
    for(auto [x, cnt]: dists[1]){
        for(int d: {d0+x, abs(d0-x)}){
            bool ok = true;
            atcoder::mf_graph<int> mf(m0+m1+2);
            for(auto [x0, cnt0]: dists[0]) mf.add_edge(s, cp[0][x0]+1, cnt0);
            for(auto [x1, cnt1]: dists[1]) mf.add_edge(cp[1][x1]+m0+1,t, cnt1);
            for(auto it: dists[0]){
                int x0 = it.first;
                int cnt0 = it.second;
                int cnt = 0;
                auto add_edge = [&](int x1){
                    if(dists[1].count(x1) == 0){
                        return;
                    }
                    int cnt1 = dists[1][x1];
                    mf.add_edge(cp[0][x0]+1, cp[1][x1]+m0+1, min(cnt0, cnt1));
                    cnt += cnt1;
                };
                add_edge(d-x0);
                add_edge(x0-d);
                add_edge(x0+d);
                if(cnt == 0){
                    ok = false;
                    break;
                }
            }
            if(ok){
                int f = mf.flow(s, t);
                if(f == n){
                    cout << "YES" << endl;
                    vector<int> x;
                    for(auto e: mf.edges()){
                        if(e.flow == 0) continue;
                        bool is_left = (1 <= e.from && e.from <= m0);
                        if(!is_left) continue;
                        bool is_right = (1+m0 <= e.to && e.to < t);
                        if(!is_right) continue;

                        int i0 = e.from-1;
                        int i1 = e.to-m0-1;
                        int x0 = cp[0].data[i0], x1 = cp[1].data[i1];
                        for(int i = 0; i < e.flow; i++){
                            if(x0+x1 == d){
                                x.push_back(x0);
                            }else if(x0-x1 == d){
                                x.push_back(x0);
                            }else{
                                assert(x1-x0 == d);
                                x.push_back(-x0);
                            }
                        }
                    }
                    int p0 = 0, p1 = d;
                    int min_x = *min_element(x.begin(), x.end());
                    if(min_x < 0){
                        p0 -= min_x;
                        p1 -= min_x;
                        for(int i = 0; i < n; i++) x[i] -= min_x;
                    }
                    print_vector(x);
                    cout << p0 << ' ' << p1 << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}