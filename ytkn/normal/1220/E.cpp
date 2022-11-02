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
using P = pair<int, int>;

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

struct edge{
    int from, to;
    edge(int from, int to): from(from), to(to) {}
};

/**
 * dfspathimos
 * 
 * verified by ARC039 D
 */
class TwoEdgeConnectedComponents{
    public:
        TwoEdgeConnectedComponents(vector<edge> v, int size){
            G = vector<vector<int>>(size);
            used = vector<bool>(size, false);
            col = vector<int>(size, 0);
            depth = vector<int>(size, 0);
            for(edge e : v){
                int from = e.from;
                int to = e.to;
                G[from].push_back(to);
                G[to].push_back(from);
            }
            N = size;
        }

        vector<vector<int>> G;
        int N;
        vector<edge> run(){
            vector<edge> bridges;
            dfs(0, -1, 0);
            clear();
            paint(0, -1, bridges);
            return bridges;
        }
    private:
        vector<bool> used;
        vector<int> col;
        vector<int> depth;
        void dfs(int u, int p, int d){
            used[u] = true;
            depth[u] = d;
            for(int to : G[u]){
                if(to == p) continue;
                if(used[to] && depth[to] < depth[u]){
                    col[u]++;
                    col[to]--;
                }else if(!used[to]){
                    dfs(to, u, d+1);
                }
            }
        }

        void paint(int u, int p, vector<edge> &v){
            used[u] = true;
            for(int to : G[u]){
                if(to == p) continue;
                if(!used[to]){
                    paint(to, u, v);
                    col[u] += col[to];
                    if(col[to] == 0){
                        v.push_back((edge){u, to});
                    }
                }
            }
        }
        void clear(){
            for(int i = 0; i < N; i++){
                used[i] = false;
            }
        }
};

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

void dfs(int v, vector<vector<int>> &g, vector<bool> &seen, vector<ll> &sum, vector<ll> &dp, vector<int> &sizes, vector<bool> &ok){
    int ch = 0;
    seen[v] = true;
    if(sizes[v] > 1) ok[v] = true;
    dp[v] = sum[v];
    ll mx = 0;
    for(int to: g[v]){
        if(seen[to]) continue;
        dfs(to, g, seen, sum, dp, sizes, ok);
        if(ok[to]) ok[v] = true;
        chmax(mx, dp[to]);
        ch++;
    }
    dp[v] += mx;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<ll> w(n);
    for(int i = 0; i < n; i++) cin >> w[i];
    vector<edge> edges;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--; v--;
        edges.push_back(edge(u, v));
    }
    int s; cin >> s; s--;
    auto tcc = TwoEdgeConnectedComponents(edges, n);
    auto bridges = tcc.run();
    set<P> st;
    for(auto e: bridges){
        st.insert(P(e.from, e.to));
        st.insert(P(e.to, e.from));
    }
    UnionFind uf(n);
    for(edge e: edges){
        if(st.count(P(e.from, e.to))) continue;
        uf.unionSet(e.from, e.to);
    }
    vector<int> roots;
    for(int i = 0; i < n; i++){
        if(uf.root(i) == i) roots.push_back(i);
    }
    auto cp = Compress<int>(roots);
    int sz = cp.size();
    vector<int> sizes(sz);
    vector<ll> sum(sz);
    for(int i = 0; i < n; i++){
        int r = uf.root(i);
        int r_idx = cp[r];
        sum[r_idx] += w[i];
    }
    for(int r: roots) sizes[cp[r]] = uf.size(r);
    vector<vector<int>> g(sz);
    for(edge e: bridges){
        int u = cp[uf.root(e.from)];
        int v = cp[uf.root(e.to)];  
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll ans = 0;
    vector<bool> seen(sz);
    vector<ll> dp(sz);
    vector<bool> ok(sz);
    int sr = uf.root(s);
    dfs(cp[sr], g, seen, sum, dp, sizes, ok);
    ll mx = 0;
    for(int i = 0; i < sz; i++){
        if(ok[i]){
            ans += sum[i];
        }else{
            chmax(mx, dp[i]);
        }
    }
    ans += mx;
    cout << ans << endl;
}