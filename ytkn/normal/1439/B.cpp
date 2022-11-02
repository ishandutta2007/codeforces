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
        set<T> st;
        for(T x: data_) st.insert(x);
        for(T x: st) data.push_back(x);
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

using P = pair<int, int>;

void sub_solve(vector<vector<bool>> &g, int k, vector<int> inv){
    int n = g.size();
    vector<int> degs(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(g[i][j]) degs[i]++;
        }
    }
    auto is_clique = [&](vector<int> &v) -> bool{
        assert(v.size() == k);
        for(int i = 0; i < k; i++){
            for(int j = i+1; j < k; j++){
                if(!g[v[i]][v[j]]) return false;
            }
        }
        return true;
    };
    auto erase_vertex = [&](int v){
        for(int u = 0; u < n; u++){
            if(g[v][u]){
                degs[u]--;
                degs[v]--;
                g[v][u] = false;
                g[u][v] = false;
            }
        }
    };
    auto min_deg_vertex = [&](){
        int d = n;
        int ans = -1;
        for(int i = 0; i < n; i++){
            if(degs[i] == 0) continue;
            if(chmin(d, degs[i])) ans = i;
        }
        return ans;
    };
    while(!degs.empty()){
        int v = min_deg_vertex();
        if(v == -1) break;
        int d = degs[v];

        assert(d > 0);
        if(d == k){
            vector<int> ans;
            for(int i = 0; i < n; i++){
                if(degs[i] > 0) ans.push_back(i);
            }
            cout << 1 << ' ' << ans.size() << "\n";
            for(auto u: ans) cout << inv[u]+1 << ' ';
            cout << "\n";
            return;
        }else if(d == k-1){
            vector<int> vs = {v};
            for(int u = 0; u < n; u++){
                if(g[v][u]) vs.push_back(u);
            }
            if(is_clique(vs)){
                cout << 2 << "\n";
                for(int u: vs) cout << inv[u]+1 << ' ';
                cout << "\n";
                return;
            }else{
                erase_vertex(v);
            }
        }else{
            erase_vertex(v);
        }
    }
    cout << -1 << endl;
}

void solve_small_k(int n, int m, int k, vector<vector<int>> _g){
    vector<set<int>> g(n);
    for(int i = 0; i < n; i++){
        for(int to: _g[i]){
            g[i].insert(to);
            g[to].insert(i);
        }
    }
    set<P> degs;
    for(int i = 0; i < n; i++) {
        if(!g[i].empty()) degs.insert(P(g[i].size(), i));
    }
    auto erase_edge = [&](int u, int v){
        degs.erase(P(g[u].size(), u));
        degs.erase(P(g[v].size(), v));
        g[u].erase(v);
        g[v].erase(u);
        if(!g[u].empty()) degs.insert(P(g[u].size(), u));
        if(!g[v].empty()) degs.insert(P(g[v].size(), v));
    };
    auto erase_vertex = [&](int v){
        vector<int> neighbours;
        for(int to: g[v]) neighbours.push_back(to);
        for(int to: neighbours) erase_edge(v, to);
    };
    auto is_clique = [&](vector<int> &v) -> bool{
        assert(v.size() == k);
        for(int i = 0; i < k; i++){
            for(int j = i+1; j < k; j++){
                if(g[v[i]].count(v[j]) == 0) return false;
            }
        }
        return true;
    };
    while(!degs.empty()){
        auto [d, v] = *degs.begin();
        assert(d > 0);
        if(d == k){
            cout << 1 << ' ' << degs.size() << "\n";
            for(auto [_, u]: degs) cout << u+1 << ' ';
            cout << "\n";
            return;
        }else if(d == k-1){
            vector<int> vs = {v};
            for(int u: g[v]) vs.push_back(u);
            if(is_clique(vs)){
                cout << 2 << "\n";
                for(int u: vs) cout << u+1 << ' ';
                cout << "\n";
                return;
            }else{
                erase_vertex(v);
            }
        }else{
            erase_vertex(v);
        }
    }
    cout << -1 << endl;
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(k <= 100){
        solve_small_k(n, m, k, g);
        return;
    }
    vector<int> degs(n);
    for(int i = 0; i < n; i++) {
        degs[i] = g[i].size();
    }
    auto erase_edge = [&](int u, int v){
        if(degs[v] == 0 || degs[u] == 0) return;
        degs[u]--;
        degs[v]--;
    };
    vector<bool> seen(n);
    queue<int> que;
    auto push = [&](int v){
        if(!seen[v]){
            seen[v] = true;
            que.push(v);
        }
    };
    auto erase_vertex = [&](int v){
        for(int to: g[v]) {
            erase_edge(v, to);
            if(degs[to] <= k-2) push(to);
        }
    };
    for(int i = 0; i < n; i++){
        if(degs[i] < k-1 && degs[i] > 0) push(i);
    }
    while(!que.empty()){
        int v; que.front(); que.pop();
        int d = degs[v];
        if(d == 0) continue;
        if(d >= k-1) break;
        erase_vertex(v);
    }
    vector<int> u;
    for(int i = 0; i < n; i++) {
        if(degs[i] != 0) u.push_back(i);
    }
    auto cp = Compress<int>(u);
    int sz = cp.size();
    auto h = vec2d(sz, sz, false);
    for(int v: u) {
        for(int to: g[v]){
            if(degs[to] == 0) continue;
            h[cp[v]][cp[to]] = true;
            h[cp[to]][cp[v]] = true;
        }
    }
    sub_solve(h, k, cp.data);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}