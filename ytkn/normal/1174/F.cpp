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


class Lca{
    public:
        vector<int> depth;
        vector<vector<int>> parent;
        vector<vector<int>> G;
        int root;
        int n;
        const int N_LOG_MAX = 25;
        bool initialized = false;

        Lca(vector<vector<int>> g, int _root){
            n = g.size();
            G = g;
            root = _root;
            parent = vector<vector<int>>(N_LOG_MAX, vector<int>(n));
            depth = vector<int>(n, 0);
        }

        void init(){
            initialized = true;
            dfs(root, -1, 0);
            for(int i = 0; i < N_LOG_MAX-1; i++){
                for(int v = 0; v < n; v++){
                    if(parent[i][v] < 0) parent[i+1][v] = -1;
                    else parent[i+1][v] = parent[i][parent[i][v]];
                }
            }
        }

        int lca(int u, int v){
            assert(initialized);
            if(depth[u] > depth[v]) swap(u, v);
            for(int i = 0; i < N_LOG_MAX; i++){
                if((depth[v] - depth[u]) >> i & 1){
                    v = parent[i][v];
                }
            }
            if(u == v) return u;
            for(int i = N_LOG_MAX-1; i >= 0; i--){
                if(parent[i][u] != parent[i][v]) {
                    u = parent[i][u];
                    v = parent[i][v];
                }
            }
            return parent[0][u];
        }

        int dist(int u, int v){
            int l = lca(u, v);
            return depth[u]+depth[v]-2*depth[l];
        }

    private:
        void dfs(int v, int p, int d){
            parent[0][v] = p;
            depth[v] = d;
            for(int i = 0; i < G[v].size(); i++){
                if(G[v][i] != p) dfs(G[v][i], v, d+1); 
            }
        }
};


int find_centroid(int r, vector<vector<int>> &g){
    int n = g.size();
    vector<bool> used(n);
    vector<int> ch(n);
    function<void(int, vector<int>&)> dfs = [&](int v, vector<int> &visited){
        used[v] = true;
        ch[v] = 1;
        visited.push_back(v);
        for(int to : g[v]){
            if(!used[to]){
                dfs(to, visited);
                ch[v] += ch[to];
            }
        }
    };

    vector<int> visited;
    dfs(r, visited);
    int m = visited.size();
    for(int v : visited) used[v] = false;
    int cur = r;
    int pre = -1;
    while(true){
        int nx = -1;
        int max_ch = -1;
        for(int to : g[cur]){
            if(!used[to] && to != pre){
                if(ch[to]*2 > m && chmax(max_ch, ch[to])) nx = to;
            }
        }
        if(nx == -1) break;
        pre = cur;
        cur = nx;
    }
    return cur;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<vector<int>> g(n);
    vector<int> u(n-1), v(n-1);
    for(int i = 0; i < n-1; i++) {
        cin >> u[i] >> v[i]; u[i]--; v[i]--;
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    auto lca = Lca(g, 0);
    lca.init();
    auto ask_type_d = [&](int u){
        cout << "d " << u+1 << endl;
        int ans; cin >> ans;
        assert(ans != -1);
        return ans;
    };
    auto ask_type_s = [&](int u){
        cout << "s " << u+1 << endl;
        int ans;
        assert(ans != -1);
        cin >> ans; ans--;
        return ans;
    };
    auto verify = [&](int x){
        cout << "! " << x+1 << endl;
    };
    int dist_from_root = ask_type_d(0);
    vector<bool> cut(n-1);
    auto cut_centroid = [&](int c, int ch){
        for(int i = 0; i < n-1; i++){
            if(u[i] == c){
                cut[i] = true;
            }else if(v[i] == c){
                cut[i] = true;
            }
        }
    };
    auto rebuild_tree = [&](){
        for(int i = 0; i < n; i++) g[i].clear();
        for(int i = 0; i < n-1; i++){
            if(cut[i]) continue;
            g[u[i]].push_back(v[i]);
            g[v[i]].push_back(u[i]);
        }
    };
    int c = find_centroid(0, g);
    while(true){
        int dist_from_centroid = ask_type_d(c);
        if(dist_from_centroid == 0){
            verify(c);
            break;
        }
        if(lca.dist(c, 0) + dist_from_centroid == dist_from_root){
            int ch = ask_type_s(c);
            cut_centroid(c, ch); rebuild_tree();
            c = find_centroid(ch, g);
        }else{
            int ch = -1;
            for(int v: g[c]){
                if(lca.depth[v] < lca.depth[c]) ch = v;
            }
            assert(ch != -1);
            cut_centroid(c, ch); rebuild_tree();
            c = find_centroid(ch, g);
        }
    }
}