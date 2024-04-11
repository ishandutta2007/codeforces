#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <cmath>
#include <numeric>
#include <functional>
#include <cassert>
#include <random>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;


struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) {}
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
        if (data[y] < data[x]) swap(x, y);
        data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

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

class Simulator{
    public:
    int n;
    int cnt = 0;
    vector<vector<int>> g;
    Simulator(int n): n(n){
        g.resize(n);
        random_device rd;
        mt19937 mt(rd());
        UnionFind uf(n);
        while(uf.size(0) != n){
            int u = mt()%n, v = mt()%n;
            if(!uf.findSet(u, v)){
                uf.unionSet(u, v);
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
    };

    vector<int> ask(int v){
        cout << "ask:" << v << endl;
        cnt++;
        vector<int> d(n);
        Lca lca(g, 0);
        lca.init();
        for(int i = 0; i < n; i++) d[i] = lca.dist(v, i);
        return d;
    }

    void verify(vector<int> a, vector<int> b){
        assert(a.size() == n-1);
        assert(b.size() == n-1);
        assert(cnt <= (n+1)/2);
        for(int i = 0; i < n-1; i++){
            bool ok = false;
            for(int to : g[a[i]]){
                if(to == b[i]) ok = true;
            }
            assert(ok);
        }
    }
};

// #define DEBUG

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    #ifdef DEBUG
    auto sim = Simulator(n);
    #endif
    auto ask = [&](int v)->vector<int>{
        #ifdef DEBUG
        return sim.ask(v);
        #else
        cout << "? " << v+1 << endl;
        vector<int> ans(n);
        for(int i = 0; i < n; i++) cin >> ans[i];
        return ans;
        #endif
    };

    auto verify = [&](vector<int> a, vector<int> b){
        #ifdef DEBUG
        return sim.verify(a, b);
        #else
        cout << "!" << endl;
        for(int i = 0; i < n-1; i++) cout << a[i]+1 << ' ' << b[i]+1 << endl;
        #endif
    };
    
    auto d = ask(0);
    vector<int> o, e;
    vector<int> a, b;
    for(int i = 0; i < n; i++){
        if(d[i]%2 == 0) e.push_back(i);
        else o.push_back(i);
        if(d[i] == 1) {
            a.push_back(0);
            b.push_back(i);
        }
    }
    if(e.size() > o.size()) swap(o, e);
    for(int v : e){
        if(v == 0) continue;
        auto d = ask(v);
        for(int i = 1; i < n; i++){
            if(d[i] == 1){
                a.push_back(v);
                b.push_back(i);
            }
        }
    }
    verify(a, b);
}