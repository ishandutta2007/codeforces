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

using T = tuple<int, int, int>;

ll tri(ll x){
    return (x*(x-1))/2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<T> vt(m);
    vector<vector<int>> g(n);
    int w_xor = 0;
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w; u--; v--;
        vt[i] = T(w, u, v);
        g[u].push_back(v);
        g[v].push_back(u);
        w_xor ^= w;
    }
    sort(vt.begin(), vt.end());
    set<int> remaining;
    for(int i = 0; i < n; i++) remaining.insert(i);
    vector<bool> edge(n);
    UnionFind uf(n);
    for(int v = 0; v < n; v++){
        if(remaining.count(v) == 0) continue;
        queue<int> que;
        que.push(v);
        while(!que.empty()){
            int u = que.front(); que.pop();
            for(int to: g[u]) edge[to] = true;
            vector<int> erased;
            for(int x: remaining){
                if(!edge[x]) {
                    erased.push_back(x);
                    que.push(x);
                    uf.unionSet(v, x);
                }
            }
            for(int x: erased) remaining.erase(x);
            for(int to: g[u]) edge[to] = false;
        }
    }
    vector<vector<int>> components(n);
    for(int i = 0; i < n; i++){
        int r = uf.root(i);
        components[r].push_back(i);
    }
    vector<ll> count_no_edge(n);
    for(int i = 0; i < n; i++) {
        if(uf.root(i) != i) continue;
        count_no_edge[i] = tri(uf.size(i));
    }
    for(auto [w, u, v]: vt){
        if(uf.findSet(u, v)){
            count_no_edge[uf.root(u)]--;
        }
    }
    bool find_loop = false;
    for(int i = 0; i < n; i++) {
        if(uf.root(i) != i) continue;
        if(count_no_edge[i] >= uf.size(i)){
            find_loop = true;
        }
    }
    ll ans = 0;
    vector<bool> edge_used(m);
    UnionFind uf1(n);
    for(int i = 0; i < m; i++){
        auto [w, u, v] = vt[i];
        if(!uf.findSet(u, v)){
            uf.unionSet(u, v);
            uf1.unionSet(u, v);
            ans += w;
        }
    }
    if(find_loop){
        cout << ans << endl;
        return 0;
    }
    
    for(int i = 0; i < m; i++){
        if(edge_used[i]) continue;
        auto [w, u, v] = vt[i];
        if(w >= w_xor) break;
        if(!uf1.findSet(u, v)){
            cout << ans+w << endl;
            return 0;
        }
    }
    cout << ans+w_xor << endl;
}