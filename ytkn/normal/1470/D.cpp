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

bool dfs(vector<vector<int>> &g, vector<int> &col, int v, int c){
    col[v] = c;
    for(int to: g[v]){
        if(col[to] == -1){
            if(!dfs(g, col, to, c^1)) return false;
        }else if(col[to] == c){
            if(c == 1) return false;
        }
    }
    return true;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    UnionFind uf(n);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
        uf.unionSet(u, v);
    }
    if(uf.size(0) != n){
        cout << "NO" << endl;
        return;
    }
    vector<int> ans;
    queue<int> que;
    vector<bool> seen(n, false);
    que.push(0);
    while(!que.empty()){
        int v = que.front(); que.pop();
        if(seen[v]) continue;
        seen[v] = true;
        ans.push_back(v+1);
        for(int to: g[v]){
            if(seen[to]) continue;
            seen[to] = true;
            for(int tto: g[to]){
                que.push(tto);
            }
        }
    }

    cout << "YES" << endl;
    cout << ans.size() << endl;
    print_vector(ans);   
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}