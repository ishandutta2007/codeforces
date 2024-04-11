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

class Scc{
    public:
        int N;
        vector<vector<int>> G;
        vector<vector<int>> G_inv;
        vector<int> idx;

        Scc(int n){
            N = n;
            G = vector<vector<int>>(n, vector<int>());
            G_inv = vector<vector<int>>(n, vector<int>());
            used = vector<bool>(n, false);
            idx = vector<int>(n);
        }

        void add_edge(int from, int to){
            G[from].push_back(to);
            G_inv[to].push_back(from);
        }

        vector<vector<int>> scc(){
            vector<vector<int>> ans;
            for(int i = 0; i < N; i++){
                if(!used[i]) dfs1(i);
            }
            clear();
            int cur = 0;
            for(int i = vs.size()-1; i >= 0; i--){
                if(!used[vs[i]]) {
                    dfs2(vs[i], cur);
                    cur++;
                    ans.push_back(buf);
                    buf.clear();
                }
            }
            return ans;
        }

    private:
        vector<bool> used;
        vector<int> vs;
        vector<int> buf;
        void clear(){
            for(int i = 0; i < N; i++) used[i] = false;
        }

        void dfs1(int v){
            used[v] = true;
            for(int i = 0; i < G[v].size(); i++){
                if(!used[G[v][i]]) dfs1(G[v][i]);
            }
            vs.push_back(v);
        }

        void dfs2(int v, int k){
            used[v] = true;
            idx[v] = k;
            for(int i = 0; i < G_inv[v].size(); i++){
                if(!used[G_inv[v][i]]) dfs2(G_inv[v][i], k);
            }
            buf.push_back(v);
        }
};

struct edge{
    int to;
    ll cost;
    edge(int to, ll cost) : to(to), cost(cost) {}
};

void dfs(int v, vector<vector<edge>> &g, vector<bool> &seen, vector<ll> &dist, vector<ll> &gc, vector<int> &indices, ll d){
    seen[v] = true;
    dist[v] = d;
    for(edge e: g[v]){
        if(seen[e.to]){
            ll cycle = dist[v]-dist[e.to]+e.cost;
            int i = indices[v];
            if(indices[e.to] == i){
                gc[i] = gcd(gc[i], cycle);
            }
        }else{
            dfs(e.to, g, seen, dist, gc, indices, d+e.cost);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<vector<edge>> g(n);
    Scc scc(n);
    for(int i = 0; i < m; i++) {
        int a, b, l; cin >> a >> b >> l; a--; b--;
        scc.add_edge(a, b);
        g[a].push_back(edge(b, l));
    }
    auto u = scc.scc();
    int n_components = u.size();
    vector<ll> gc(n_components);
    vector<ll> dist(n);
    vector<bool> seen(n);
    for(int i = 0; i < n; i++){
        if(!seen[i]) dfs(i, g, seen, dist, gc, scc.idx, 0);
    }
    int q; cin >> q;
    while(q--){
        int v; ll s, t; cin >> v >> s >> t; v--;
        int i = scc.idx[v];
        ll g = gcd(gc[i], t);
        if(s%g == 0){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }
}