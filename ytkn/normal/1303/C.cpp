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

void dfs(int v, vector<vector<int>> &g, vector<bool> &seen, vector<int> &ans){
    seen[v] = true;
    ans.push_back(v);
    for(int to: g[v]){
        if(!seen[to]) dfs(to, g, seen, ans);
    }
}

void solve(){
    string s; cin >> s;
    UnionFind uf(26);
    int n = s.size();
    vector<vector<int>> g(26);
    vector<bool> seen(26);
    auto edge = vec2d(26, 26, false);
    for(int i = 0; i+1 < n; i++){
        int x = s[i]-'a';
        int y = s[i+1]-'a';
        if(x == y) continue;
        if(edge[x][y]) continue;
        if(edge[y][x]) continue;
        edge[x][y] = true;
        edge[y][x] = true;
        if(uf.findSet(x, y)){
            cout << "NO" << endl;
            return;
        }
        uf.unionSet(x, y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> ans;
    for(int i = 0; i < 26; i++){
        if(g[i].size() >= 3){
            cout << "NO" << endl;
            return;
        }
        if(g[i].size() == 2) continue;
        if(!seen[i]) dfs(i, g, seen, ans);
    }
    assert(ans.size() == 26);
    cout << "YES" << endl;
    for(int i: ans) cout << (char)('a'+i);
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}