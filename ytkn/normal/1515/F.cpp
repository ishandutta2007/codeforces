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

using P = pair<ll, int>;
using edge = pair<int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; ll x; cin >> n >> m >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<set<edge>> g(n);
    UnionFind uf_scan(n);
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y; x--; y--;
        if(uf_scan.findSet(x, y)) continue;
        g[x].insert(edge(y, i));
        g[y].insert(edge(x, i));
    }
    ll asum = accumulate(a.begin(), a.end(), 0ll);
    if(asum < x*(n-1)){
        cout << "NO" << endl;
        return 0;
    }
    vector<int> pos(n);
    for(int i = 0; i < n; i++) pos[i] = i;
    vector<int> ans;
    UnionFind uf(n);
    set<P> vertices;
    vector<bool> used(m);
    for(int i = 0; i < n; i++) vertices.insert(P(a[i], i));
    while(vertices.size() > 1){
        auto p_ = *prev(vertices.end());
        ll sum = p_.first;
        int v = p_.second;
        vertices.erase(P(sum, v));
        if(sum < x) break;
        int vr = uf.root(v);
        assert(vr == v);
        int pv = pos[vr];
        int u = -1, idx = -1;
        vector<edge> erase;
        for(edge e: g[pv]){
            int _idx = e.second;
            if(used[_idx]) {
                erase.push_back(e);
                continue;
            }
            if(uf.findSet(e.first, v)){
                erase.push_back(e);
                continue;
            }
            u = e.first;
            idx = e.second;
            break;
        }
        for(edge e: erase){
            g[pv].erase(e);
        }
        int ur = uf.root(u);
        vertices.erase(P(a[ur], ur));
        int pu = pos[ur];
        ans.push_back(idx);
        uf.unionSet(u, v);
        int r = uf.root(u);
        if(g[pv].size() > g[pu].size()){
            pos[r] = pv;
            for(edge e: g[pu]) {
                auto [to, idx] = e;
                if(uf.findSet(r, to)) continue;
                g[pv].insert(edge(uf.root(to), idx));
            }
        }else{
            pos[r] = pu;
            for(edge e: g[pv]) {
                auto [to, idx] = e;
                if(uf.findSet(r, to)) continue;
                g[pu].insert(edge(uf.root(to), idx));
            }
        }
        a[r] = a[ur]+a[vr]-x;
        vertices.insert(P(a[r], r));
    }
    for(int i = 0; i < n; i++){
        for(auto [j, idx]: g[i]){
            if(!uf.findSet(i, j)){
                uf.unionSet(i, j);
                ans.push_back(idx);
            }
        }
    }
    cout << "YES" << endl;
    for(int idx: ans) cout << idx+1 << "\n";
}