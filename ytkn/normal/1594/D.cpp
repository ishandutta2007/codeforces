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

struct edge{
    int to, c;
};

bool dfs_col(int v, vector<vector<edge>> &g, vector<int> &col, int c){
    col[v] = c;
    for(edge e: g[v]){
        if(col[e.to] != -1){
            if(col[e.to] != c^e.c) return false;
        }else{
            if(!dfs_col(e.to, g, col, c^e.c)) return false;
        }
    }
    return true;
}

void solve(){
    int n, m; cin >> n >> m;
    UnionFind uf(n);
    vector<vector<edge>> g(n);
    for(int i = 0; i < m; i++){
        int a, b; string s; cin >> a >> b >> s; a--; b--;
        int c = s[0] == 'i' ? 1 : 0;
        g[a].push_back(edge{b, c});
        g[b].push_back(edge{a, c});
        uf.unionSet(a, b);
    }
    vector<vector<int>> components(n);
    vector<int> col(n, -1);
    for(int i = 0; i < n; i++) components[uf.root(i)].push_back(i);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(uf.root(i) != i) continue;
        if(!dfs_col(i, g, col, 0)){
            cout << -1 << endl;
            return;
        }
        int tmp = 0;
        for(int j: components[i]) tmp += col[j];
        ans += max(tmp, uf.size(i)-tmp);
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}