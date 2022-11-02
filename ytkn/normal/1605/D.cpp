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

void dfs_col(int v, vector<vector<int>> &g, vector<int> &col, int c){
    col[v] = c;
    for(int to: g[v]){
        if(col[to] != -1) continue;
        dfs_col(to, g, col, c^1);
    }
}

int msb(int n){
    for(int i = 20; i >= 0; i--){
        if(n&(1<<i)) return i;
    }
    return -1;
}

void solve(){
    int n; cin >> n;
    vector<vector<int>> g(n+1);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> col(n+1, -1);
    dfs_col(1, g, col, 0);
    vector<vector<int>> v(2);
    for(int i = 1; i <= n; i++){
        v[col[i]].push_back(i);
    }
    int m = msb(n);
    vector<vector<int>> u(m+1);
    for(int i = 1; i <= n; i++){
        u[msb(i)].push_back(i);
    }
    vector<int> ans(n+1);
    for(int x = m; x >= 0; x--){
        if(v[0].size() > v[1].size()){
            for(int i: u[x]){
                ans[v[0].back()] = i;
                v[0].pop_back();
            }
        }else{
            for(int i: u[x]){
                ans[v[1].back()] = i;
                v[1].pop_back();
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}