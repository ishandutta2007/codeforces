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

void dfs(int v, vector<vector<int>> &g, vector<int> &depth, vector<int> &par, int d){
    depth[v] = d;
    for(int to: g[v]){
        if(depth[to] == -1) {
            par[to] = v;
            dfs(to, g, depth, par, d+1);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> depth(n, -1);
    vector<int> par(n, -1);
    dfs(0, g, depth, par, 0);
    for(int i = 0; i < n; i++){
        if(depth[i] <= k-1){
            for(int j: g[i]){
                if(depth[j] < depth[i]-1){
                    vector<int> ans;
                    int cur = i;
                    while(true){
                        ans.push_back(cur);
                        if(cur == j) break;
                        cur = par[cur];
                    }
                    cout << 2 << endl;
                    cout << ans.size() << endl;
                    for(int x: ans) cout << x+1 << ' ';
                    cout << endl;
                    return 0;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(depth[i] == k-1){
            int cur = i;
            vector<int> ans;
            while(true){
                if(depth[cur]%2 == 0) ans.push_back(cur);
                if(cur == 0) break;
                cur = par[cur];
            }
            cout << 1 << endl;
            for(int x: ans) cout << x+1 << ' ';
            cout << endl;
            return 0;
        }
    }
    vector<vector<int>> v(2);
    for(int i = 0; i < n; i++){
        v[depth[i]%2].push_back(i);
    }
    int sz = (k+1)/2;
    if(v[0].size() >= sz){
        while(v[0].size() > sz) v[0].pop_back();
        cout << 1 << endl;
        for(int x: v[0]) cout << x+1 << ' ';
        cout << endl;
    }else{
        assert(v[1].size() >= sz);
        while(v[1].size() > sz) v[1].pop_back();
        cout << 1 << endl;
        for(int x: v[1]) cout << x+1 << ' ';
        cout << endl;
    }
}