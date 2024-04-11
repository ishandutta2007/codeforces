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

struct edge{
    int to, tp;
};

const int irrelevant = 0;
const int destined = 1;
const int L = 0, R = 1;
int col[200000];
vector<edge> g[200000];
bool seen[200000];

bool dfs(int v, int c){
    seen[v] = true;
    col[v] = c;
    for(edge e: g[v]){
        if(seen[e.to]){
            if(col[e.to] == c) return false;
        }else{
            if(!dfs(e.to, c^1)) return false;
        }
    }
    return true;
}

/**
 * gDAG: ordertrue
 * gDAG: false
 * 
 * verified(DAG): https://atcoder.jp/contests/dp/tasks/dp_g
 * verified(DAG): https://yukicoder.me/submissions/614434
 */ 
bool topological_sort(vector<vector<int>> g, vector<int> &order){
    int n = g.size();
    order.clear();
    vector<bool> used(n, false);
    function<void(int)> dfs = [&](int v){
        used[v] = true;
        for(int to : g[v]){
            if(!used[to]) dfs(to);
        }
        order.push_back(v);
    };
    for(int v = 0; v < n; v++){
        if(!used[v]) dfs(v);
    }
    reverse(order.begin(), order.end());
    vector<int> inv_order(n);
    for(int i = 0; i < n; i++) inv_order[order[i]] = i;
    for(int v = 0; v < n; v++){
        for(int u : g[v]){
            if(inv_order[v] > inv_order[u]) return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int t, u, v; cin >> t >> u >> v; t--; u--; v--;
        g[u].push_back(edge{v, t});
        g[v].push_back(edge{u, t});
    }
    for(int i = 0; i < n; i++){
        if(!seen[i]){
            if(!dfs(i, 0)) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    vector<vector<int>> g_dir(n);
    for(int i = 0; i < n; i++){
        for(edge e: g[i]){
            if(col[i] == L && e.tp == irrelevant){
                g_dir[i].push_back(e.to);
                // cout << i << "->" << e.to << endl;
            }
            if(col[i] == R && e.tp == destined){
                g_dir[i].push_back(e.to);
                // cout << i << "->" << e.to << endl;
            }
        }
    }
    vector<int> ord;
    if(!topological_sort(g_dir, ord)){
        cout << "NO" << endl;
        return 0;
    }
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        ans[ord[i]] = i;
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++){
        if(col[i] == L) cout << "L ";
        else cout << "R ";
        cout << ans[i] << endl;
    }
}