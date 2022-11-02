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
        cout << '\n';
        return;
    }
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << '\n';
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

struct edge{
    int to, c;
    edge(int to, int c): to(to), c(c) {}
};

void solve(){
    int n; cin >> n;
    auto a = vec2d(n, n, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    vector<int> col(n, -1);
    UnionFind uf(n);
    vector<vector<edge>> g(n);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(a[i][j] == a[j][i]) continue;
            if(uf.findSet(i, j)) continue;
            if(a[i][j] < a[j][i]){ // 
                g[i].push_back(edge(j, 0));
                g[j].push_back(edge(i, 0));
            }else{ // 
                g[i].push_back(edge(j, 1));
                g[j].push_back(edge(i, 1));
            }
            uf.unionSet(i, j);
        }
    }
    function<void(int, int)> dfs = [&](int v, int c){
        col[v] = c;
        for(edge e: g[v]){
            if(col[e.to] == -1){
                dfs(e.to, c^e.c);
            }
        }
    };
    for(int i = 0; i < n; i++){
        if(col[i] == -1) dfs(i, 0);
    }
    // print_vector(col);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            bool f = col[i]^col[j];
            if(f) swap(a[i][j], a[j][i]);
        }
    }
    for(int i = 0; i < n; i++) print_vector(a[i]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}