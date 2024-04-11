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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll a_max = *max_element(a.begin(), a.end());
    if(a_max <= 0){ // 
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == a_max) cnt++;
        }
        cout << a_max*cnt << ' ' << cnt << endl;
        return 0;
    }
    vector<ll> max_child(n);
    function<void(int, int)> dfs1 = [&](int v, int par){
        ll sum = a[v];
        for(int to: g[v]){
            if(to == par) continue;
            dfs1(to, v);
            sum += max_child[to];
        }
        chmax(max_child[v], sum);
    };
    int root = 2;
    dfs1(root, -1);
    vector<ll> max_sum(n);
    UnionFind uf(n);
    function<void(int, int, ll)> dfs2 = [&](int v, int par, ll from_par){
        chmax(from_par, 0ll);
        if(from_par > 0 && max_child[v] > 0) uf.unionSet(v, par);
        ll sum_all = from_par;
        for(int to: g[v]){
            if(to == par) continue;
            sum_all += max_child[to];
        }
        chmax(max_sum[v], sum_all+a[v]);
        for(int to: g[v]){
            if(to == par) continue;
            dfs2(to, v, sum_all+a[v]-max_child[to]);
        }
    };
    dfs2(root, -1, 0);
    ll mx = *max_element(max_sum.begin(), max_sum.end());
    vector<ll> sum(n);
    for(int i = 0; i < n; i++){
        int r = uf.root(i);
        sum[r] += a[i];
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(mx == sum[i]) cnt++;
    }
    cout << cnt*mx << ' ' << cnt << endl;
}